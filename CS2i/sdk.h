#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <dxgi.h>

#include <cstdint>
#include <vector>
#include <span>
#include <string>
#include <ranges>
#include <functional>

#include <imgui.h>
#include <imgui_impl_win32.h>
#include <imgui_impl_dx11.h>

#include <d3d11.h>

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

#define LOGINFO(fmt, ...) \
	do { \
		if (CS2::ConMsg) { \
			CS2::ConMsg("[CS2i] " fmt "\n", ##__VA_ARGS__); \
		} else { \
			MessageBoxA(NULL, "ConMsg not initialized!", "CS2i", MB_OK); \
		} \
	} while (0)

namespace CS2 {
	using DXGIPresentFn_t = HRESULT(__stdcall*)(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);
	DXGIPresentFn_t dxgiPresentFn = nullptr;
	DXGIPresentFn_t originalDXGIPresent = nullptr;

	using ConMsgFn_t = void(__stdcall*)(const char* fmt, ...);
	ConMsgFn_t ConMsg = nullptr;

	HRESULT __stdcall hookedDXGIPresent(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags) {
		ConMsg("CS2i: DXGI Present hooked!");
		return originalDXGIPresent(pSwapChain, SyncInterval, Flags);
	}

	using FNV1A_t = uint64_t;
	constexpr FNV1A_t ullBasis = 0xCBF29CE484222325ULL;
	constexpr FNV1A_t ullPrime = 0x100000001B3ULL;

	consteval FNV1A_t HashConst(const char* szString, const FNV1A_t uKey = ullBasis) noexcept {
		return (szString[0] == '\0') ? uKey : HashConst(&szString[1], (uKey ^ static_cast<FNV1A_t>(szString[0])) * ullPrime);
	}

	inline FNV1A_t Hash(const char* szString, FNV1A_t uKey = ullBasis) noexcept {
		while (*szString) {
			uKey ^= static_cast<FNV1A_t>(*szString++);
			uKey *= ullPrime;
		}

		return uKey;
	}

	template<typename D>
	struct CHashAllocatedBlob {
		/* 0x000 */ CHashAllocatedBlob<D>* next;
		/* 0x008 */ uint8_t pad_0008[0x8];
		/* 0x010 */ D* data;
		/* 0x018 */ uint8_t pad_0018[0x8];
	};

	template <typename D, typename K>
	struct CHashFixedDataInternal {
		/* 0x000 */ K uiKey;
		/* 0x008 */ CHashFixedDataInternal<D, K>* next;
		/* 0x010 */ D* data;
	};

	template <typename D, typename K>
	struct CHashBucket {
		/* 0x000 */ RTL_SRWLOCK* lock;
		/* 0x008 */ CHashFixedDataInternal<D, K>* first;
		/* 0x010 */ CHashFixedDataInternal<D, K>* firstUncommitted;
	};

	struct CUtlMemoryPoolBase {
		/* 0x0000 */ int32_t blockSize;
		/* 0x0004 */ int32_t blocksPerBlob;
		/* 0x0008 */ int32_t growMode;
		/* 0x000C */ int32_t blocksAlloc;
		/* 0x0010 */ int32_t peakAlloc;
		/* 0x0014 */ uint16_t alignOf;
		/* 0x0016 */ uint16_t blobCount;
		/* 0x0018 */ void* freeListTail;
		/* 0x0020 */ void* freeListHead;
		/* 0x0028 */ uint8_t pad_0028[0x48];
		/* 0x0070 */ void* blobHead;
		/* 0x0078 */ int32_t totalSize;
		/* 0x007C */ uint8_t pad_007C[0x4];
	};

	template <typename D, size_t C = 256, typename K = uint64_t>
	struct CUtlTsHash {
		/* 0x0000 */ CUtlMemoryPoolBase entryMem;
		/* 0x0800 */ CHashBucket<D, K> buckets[C];
		/* 0x1880 */ bool needs_commit;
		/* 0x1881 */ uint8_t pad_1881[0xF];

		struct iterator {
			size_t bucketIndex;
			CHashFixedDataInternal<D, K>* current;
			CUtlTsHash* parent;

			iterator(CUtlTsHash* p, size_t idx, CHashFixedDataInternal<D, K>* cur)
				: bucketIndex(idx), current(cur), parent(p) {
				advanceToValid();
			}

			void advanceToValid() {
				while (!current && bucketIndex < C - 1) {
					current = parent->buckets[++bucketIndex].first;
				}
			}

			iterator& operator++() {
				if (current) current = current->next;
				if (!current) advanceToValid();
				return *this;
			}

			D& operator*() const { return *current->data; }
			D* operator->() const { return current->data; }
			bool operator==(const iterator& o) const { return current == o.current; }
			bool operator!=(const iterator& o) const { return !(*this == o); }
		};

		iterator begin() { return iterator(this, 0, buckets[0].first); }
		iterator end() { return iterator(this, C - 1, nullptr); }
	};

	class PresentManager_t {
	public:
		PresentManager_t() {
			auto base = (uintptr_t)GetModuleHandleA("GameOverlayRenderer64.dll");
			auto ptr = base + 0x162258;
			originalDXGIPresent = *(DXGIPresentFn_t*)ptr;
			DWORD oProt;
			VirtualProtect((LPVOID)ptr, sizeof(DXGIPresentFn_t), PAGE_EXECUTE_READWRITE, &oProt);
			*(DXGIPresentFn_t*)ptr = HookedDXGIPresent;
			VirtualProtect((LPVOID)ptr, sizeof(DXGIPresentFn_t), oProt, &oProt);
		}

		void shutdown() {
			// Restore original function
			auto base = (uintptr_t)GetModuleHandleA("GameOverlayRenderer64.dll");
			auto ptr = base + 0x162258;
			DWORD oProt;
			VirtualProtect((LPVOID)ptr, sizeof(DXGIPresentFn_t), PAGE_EXECUTE_READWRITE, &oProt);
			*(DXGIPresentFn_t*)ptr = originalDXGIPresent;
			VirtualProtect((LPVOID)ptr, sizeof(DXGIPresentFn_t), oProt, &oProt);
			SetWindowLongPtr(hWnd_, GWLP_WNDPROC, originalWndProc);
		}

		~PresentManager_t() {
			shutdown();
		}

		static PresentManager_t& get() {
			static PresentManager_t instance;
			return instance;
		}

		void setOnPresentCallback(std::function<void(bool&, IDXGISwapChain*, UINT, UINT)> callback) {
			onPresentCallback = callback;
		}

	private:
		static inline bool initialized_ = false;
		typedef HRESULT(__stdcall* DXGIPresentFn_t)(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);
		static inline DXGIPresentFn_t originalDXGIPresent = nullptr;
		static inline std::function<void(bool&, IDXGISwapChain*, UINT, UINT)> onPresentCallback = nullptr;
		static inline HWND hWnd_ = nullptr;

		static inline LONG_PTR originalWndProc = 0;

		// D3D11 state
		static inline ID3D11Device* pDevice = nullptr;
		static inline ID3D11DeviceContext* pContext = nullptr;
		static inline ID3D11RenderTargetView* pRenderTargetView = nullptr;
		
		static inline bool takesFocus_ = true;

		static LRESULT __stdcall WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
			if (ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam) || takesFocus_)
				return true;

			return CallWindowProc((WNDPROC)originalWndProc, hWnd, uMsg, wParam, lParam);
		}

		static long __stdcall HookedDXGIPresent(IDXGISwapChain* iPSwapChain, UINT SyncInterval, UINT Flags) {
			if (!initialized_) {
				// init imgui
				IDXGISwapChain* pSwapChain = (IDXGISwapChain*)iPSwapChain;
				pSwapChain->GetDevice(__uuidof(ID3D11Device), (void**)&pDevice);
				pDevice->GetImmediateContext(&pContext);

				// Get the render target view
				ID3D11Texture2D* pBackBuffer = nullptr;
				pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&pBackBuffer);
				pDevice->CreateRenderTargetView(pBackBuffer, nullptr, &pRenderTargetView);
				pBackBuffer->Release();

				DXGI_SWAP_CHAIN_DESC sd;
				pSwapChain->GetDesc(&sd);
				HWND hWnd = sd.OutputWindow;
				ImGui::CreateContext();
				ImGuiIO& io = ImGui::GetIO(); (void)io;
				io.ConfigFlags |= ImGuiConfigFlags_NoMouseCursorChange;
				ImGui::StyleColorsDark();
				ImGui_ImplWin32_Init(hWnd);
				ImGui_ImplDX11_Init(pDevice, pContext);

				originalWndProc = SetWindowLongPtr(hWnd, GWLP_WNDPROC, (LONG_PTR)WndProc);

				hWnd_ = hWnd;

				initialized_ = true;
			}

			ImGui_ImplDX11_NewFrame();
			ImGui_ImplWin32_NewFrame();
			ImGui::NewFrame();

			if (onPresentCallback) {
				onPresentCallback(takesFocus_, iPSwapChain, SyncInterval, Flags);
			}

			ImGui::Render();
			pContext->OMSetRenderTargets(1, &pRenderTargetView, nullptr);
			ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

			return PresentManager_t::get().originalDXGIPresent(iPSwapChain, SyncInterval, Flags);
		}
	};

	void initPtrs() {
		uintptr_t t0Base = (uintptr_t)GetModuleHandleA("tier0.dll");
		uintptr_t conMsgA = t0Base + 0x7CDE0; // tier0.dll!ConMsg
		ConMsg = (ConMsgFn_t)(conMsgA);

		LOGINFO("tier0.dll base: 0x%p", (void*)t0Base);
		LOGINFO("ConMsg address: 0x%p", (void*)conMsgA);
	}

	void resetPtrs() {
		// TODO
	}

	class IEngineClient;
	class ISchemaSystem;
	class IGameResourceService;
	class IMatchmaking;
	class CTraceManager;

	using InstantiateInterfaceFn_t = void* (*)();

	// [x]
	class CInterfaceRegister {
	public:
		InstantiateInterfaceFn_t fnCreate;
		const char* szName;
		CInterfaceRegister* pNext;

		static inline const CInterfaceRegister* GetRegisterList(const wchar_t* wszModuleName) {
			HMODULE hModule = GetModuleHandleW(wszModuleName);
			if (hModule == nullptr) {
				LOGINFO("Failed to get module handle for %ls", wszModuleName);
				MessageBoxA(NULL, "fail", "CS2i", MB_OK);
				return nullptr;
			}

			std::uint8_t* pCreateInterface = reinterpret_cast<std::uint8_t*>(GetProcAddress(hModule, "CreateInterface"));

			if (pCreateInterface == nullptr)
				return nullptr;

			std::uint32_t nRVA = *reinterpret_cast<std::uint32_t*>(pCreateInterface + 0x3);
			std::uintptr_t nRIP = reinterpret_cast<std::uintptr_t>(pCreateInterface) + 0x7;
			CInterfaceRegister** ppRegisterList = reinterpret_cast<CInterfaceRegister**>(nRVA + nRIP);

			LOGINFO("Got InterfaceRegister list address for %ls: 0x%p", wszModuleName, ppRegisterList);

			return *ppRegisterList;
		}

		template <typename T = void*>
		static inline T* Capture(const CInterfaceRegister* pModuleRegister, const char* szInterfaceName) {
			size_t nInterfaceNameLength = strlen(szInterfaceName);
			for (const CInterfaceRegister* pRegister = pModuleRegister; pRegister != nullptr; pRegister = pRegister->pNext) {
				size_t nRegisterNameLength = strlen(pRegister->szName);
				if (strncmp(szInterfaceName, pRegister->szName, nInterfaceNameLength) == 0 &&
					(nRegisterNameLength == nInterfaceNameLength ||
						(strtol(pRegister->szName + nInterfaceNameLength, nullptr, 10) > 0))
					) {
					void* pInterface = pRegister->fnCreate();
					LOGINFO("Captured interface %s at address 0x%p", szInterfaceName, pInterface);
					return static_cast<T*>(pInterface);
				}
			}

			return nullptr;
		}
	};

	// [x]
	namespace Interfaces {
		inline IEngineClient* GEngineClient = nullptr;
		inline ISchemaSystem* GSchemaSystem = nullptr;
		inline IGameResourceService* GGameResourceService = nullptr;
		inline IMatchmaking* GMatchmaking = nullptr;
		inline CTraceManager* GTraceManager = nullptr;
		bool setupInterfaces() {
			bool success = true;

			const auto engineRegisterList = CInterfaceRegister::GetRegisterList(L"engine2.dll");
			success &= (engineRegisterList != nullptr);
			const auto scehemaRegisterList = CInterfaceRegister::GetRegisterList(L"schemasystem.dll");
			success &= (scehemaRegisterList != nullptr);
			const auto matchmakingRegisterList = CInterfaceRegister::GetRegisterList(L"matchmaking.dll");
			success &= (matchmakingRegisterList != nullptr);

			GEngineClient = CInterfaceRegister::Capture<IEngineClient>(engineRegisterList, "Source2EngineToClient001");
			success &= (GEngineClient != nullptr);
			GSchemaSystem = CInterfaceRegister::Capture<ISchemaSystem>(scehemaRegisterList, "SchemaSystem_001");
			success &= (GSchemaSystem != nullptr);
			GGameResourceService = CInterfaceRegister::Capture<IGameResourceService>(engineRegisterList, "GameResourceServiceClientV001");
			success &= (GGameResourceService != nullptr);
			GMatchmaking = CInterfaceRegister::Capture<IMatchmaking>(matchmakingRegisterList, "GameTypes001");
			success &= (GMatchmaking != nullptr);

			// TODO: Set gTraceManager

			LOGINFO("Interfaces setup? %s", success ? "Yes" : "No");
			return success;
		}
	}

	class CSchemaSystemTypeScope;
	class CSchemaType;
	struct SchemaBaseClassInfoData_t;
	struct SchemaStaticFieldData_t;
	struct SchemaClassInfoData;

	// Full definition moved up so SchemaClassInfoData_t can use it.
	struct SchemaClassFieldData_t {
		const char* fieldName;  // 0x00
		CSchemaType* schemaType; // 0x08
		int32_t          offset;     // 0x10
		int32_t          pad0;         // 0x14
		int64_t          pad1;         // 0x18
	};

	struct SchemaData_t {
		FNV1A_t uHashedFieldName;
		std::uint32_t uOffset;
	};

	inline static std::vector<SchemaData_t> SchemaData;

	template <class T>
	class CUtlVector {
	public:
		/* 0x000 */ int m_Size;
		/* 0x004 */ int pad; // compiler should do this anyway, better safe than sorry though
		/* 0x008 */ T* m_Elements;

		T& operator[](int i) { return m_Elements[i]; }

		std::span<T> ToSpan() {
			return std::span<T>(m_Elements, m_Size);
		}
	};

	template <int Index, typename ReturnType, typename... Args>
	inline ReturnType CallVFunc(void* pThis, Args... args) {
		using func = ReturnType(__thiscall*)(void*, Args...);
		LOGINFO("Calling vfunc index %d", Index);
		return (*(func**)(pThis))[Index](pThis, args...);
	}

	struct SchemaBaseClassInfoData_t {
		uint64_t               pad0;        // 0x00
		SchemaClassInfoData* classInfo; // 0x08
	};

	enum class SchemaTypeCategory : uint8_t {
		BuiltIn = 0,
		Ptr,
		Bitfield,
		FixedArray,
		Atomic,
		DeclaredClass,
		DeclaredEnum,
		None,
	};

	enum SchemaAtomicCategory : uint8_t {
		Basic = 0,
		T,
		CollectionOfT,
		TF,
		TT,
		TTF,
		I,
		None,
	};

	class CSchemaType {
	public:
		/* 0x000 */ virtual void* VirtualFunction_0() {}
		/* 0x008 */ const char* typeName;
		/* 0x010 */ CSchemaSystemTypeScope* typeScope;
		/* 0x018 */ SchemaTypeCategory typeCategory;
		/* 0x019 */ SchemaAtomicCategory atomicCategory;

		// TODO: There is also a `SchemaTypeUnion` meant to be here at 0x20
		// seems to be strange to convert however.
	};

	struct SchemaClassInfoData {
		/* 0x000 */ SchemaClassInfoData* base;
		/* 0x008 */ const char* name;
		/* 0x010 */ const char* moduleName;
		/* 0x018 */ int32_t size;
		/* 0x01C */ int16_t fieldsCount;
		/* 0x01E */ int16_t staticMetadataCount;
		/* 0x020 */ uint8_t pad0[0x2];
		/* 0x022 */ uint8_t alignOf;
		/* 0x023 */ uint8_t hasBaseClass; // TODO: bool? (or maybe a count?)
		/* 0x024 */ int16_t totalClassSize;
		/* 0x026 */ int16_t derivedClassSize;
		/* 0x028 */ SchemaClassFieldData_t* fields;
		/* 0x030 */ uint8_t pad1[0x8];
		/* 0x038 */ SchemaBaseClassInfoData_t* baseClasses;
		/* 0x040 */ SchemaStaticFieldData_t* staticMetadata;
		/* 0x048 */ uint8_t pad2[0x8]; // TODO: Why do we need this but they don't?
		/* 0x050 */ CSchemaSystemTypeScope* typeScope;
		/* 0x058 */ CSchemaType* type;
		/* 0x060 */ uint8_t pad3[0x10];

		std::span<SchemaClassFieldData_t> fieldsSpan() const {
			return std::span<SchemaClassFieldData_t>(fields, fieldsCount);
		}
	};

	class CSchemaSystemTypeScope {
	public:
		/* 0x000 */ virtual void* VirtualFunction_0() {}
		/* 0x008 */ char name[256];
		/* 0x108 */ CSchemaSystemTypeScope* globalScope;
		/* 0x110 */ char pad_0x110[0x3F0];
		/* 0x500 */ CUtlTsHash<SchemaClassInfoData> declaredClasses;

	public:
		// Virtual function to find a declared class by name
		SchemaClassInfoData* FindDeclaredClass(const char* className) {
		}
	};

	class ISchemaSystem {
	public:
		/* 0x000 */ virtual void* VirtualFunction_0() {}
		/* 0x008 */ char pad_0x000[0x180];
		/* 0x188 */ CUtlVector<CSchemaSystemTypeScope*> typeScopes;
		/* 0x198 */ char pad_0x198[0xE0];
		/* 0x278 */ int numRegistrations;

	public:
		CSchemaSystemTypeScope* FindTypeScopeForModule(const char* moduleName) {
			return CallVFunc<13u, CSchemaSystemTypeScope*>(this, moduleName, nullptr);
		}
	};


	struct SchemaStaticFieldData_t {
		const char* fieldName;  // 0x0000
		CSchemaType* schemaType; // 0x0008
		void* instance;   // 0x0010

		uint64_t pad_0x18; // 0x0018
		uint64_t pad_0x20; // 0x0020
	};

	namespace schemas {
		inline int32_t GetSchemaOffset(const char* moduleName, const char* className, const char* fieldName) {
			/*SchemaClassInfoData_t* classInfo = Interfaces::GSchemaSystem->FindTypeScopeForModule(moduleName)->FindDeclaredClass(className);
			for (int16_t i = 0; i < classInfo->fieldsCount; i++) {
				if (std::string(fieldName) == classInfo->fields[i].fieldName) {
					return classInfo->fields[i].offset;
				}
			}*/

			return 0;
		}

		inline std::uint32_t GetOffset(const FNV1A_t uHashedFieldName) {
			if (const auto it = std::ranges::find_if(SchemaData, [uHashedFieldName](const SchemaData_t& data) {
				return data.uHashedFieldName == uHashedFieldName;
				});
				it != SchemaData.end())
				return it->uOffset;

			return 0U;
		}
	}

#define SCHEMA(type, name, field_name, class_name, module_name)                                               \
		std::add_lvalue_reference_t<type> name() {                                                                \
	        return *(type *)((uint64_t)this + schemas::GetSchemaOffset(_X(module_name), _X(class_name), _X(field_name))); \
		}

#define SCHEMA_ADD_OFFSET(TYPE, NAME, OFFSET)                                                                 \
		inline std::add_lvalue_reference_t<TYPE> NAME() {                                        \
			static const std::uint32_t uOffset = OFFSET;                                                          \
			return *reinterpret_cast<std::add_pointer_t<TYPE>>(reinterpret_cast<std::uint8_t*>(this) + (uOffset)); \
		}

#define SCHEMA_ADD_POFFSET(TYPE, NAME, OFFSET)                                                               \
		inline std::add_pointer_t<TYPE> NAME() {                                                \
			const static std::uint32_t uOffset = OFFSET;                                                         \
			return reinterpret_cast<std::add_pointer_t<TYPE>>(reinterpret_cast<std::uint8_t*>(this) + (uOffset)); \
		}

#define SCHEMA_ADD_FIELD_OFFSET(TYPE, NAME, FIELD, ADDITIONAL) SCHEMA_ADD_OFFSET(TYPE, NAME, schemas::GetOffset(FNV1A::HashConst(FIELD)) + ADDITIONAL)
#define SCHEMA_ADD_FIELD(TYPE, NAME, FIELD) SCHEMA_ADD_FIELD_OFFSET(TYPE, NAME, FIELD, 0U)
#define SCHEMA_ADD_PFIELD_OFFSET(TYPE, NAME, FIELD, ADDITIONAL) SCHEMA_ADD_POFFSET(TYPE, NAME, schemas::GetOffset(FNV1A::HashConst(FIELD)) + ADDITIONAL)
#define SCHEMA_ADD_PFIELD(TYPE, NAME, FIELD) SCHEMA_ADD_PFIELD_OFFSET(TYPE, NAME, FIELD, 0U)
} // namespace CS2

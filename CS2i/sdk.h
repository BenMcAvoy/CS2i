#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <dxgi.h>
#include <Psapi.h>

#include <cstdint>
#include <vector>
#include <span>
#include <string>
#include <ranges>
#include <functional>
#include <filesystem>

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
	using byte = uint8_t;
	using byte_t = uint8_t;
	using uint = unsigned int;
	using ulong = unsigned long;
	using uchar = unsigned char;
	using ushort = unsigned short;
	using float32 = float;
	using float64 = double;
	using GameTime_t = double;
	using GameTick_t = int32_t;

	using int8 = int8_t;
	using int16 = int16_t;
	using int32 = int32_t;
	using int64 = int64_t;

	using uint8 = uint8_t;
	using uint16 = uint16_t;
	using uint32 = uint32_t;
	using uint64 = uint64_t;

	// TODO: Get these automatically instead of hardcoding
	class ViewMatrix_t;
	class CCSPlayerController;
	class C_CSPlayerPawn;
	namespace Offsets {
		inline uintptr_t dwEntityList = *reinterpret_cast<uintptr_t*>(
			(uintptr_t)GetModuleHandleA("client.dll") + 0x1FB15D0
			);

		inline ViewMatrix_t* viewMatrix = reinterpret_cast<ViewMatrix_t*>(
			(uintptr_t)GetModuleHandleA("client.dll") + 0x1E2AEC0
			);

		inline int32_t* width = reinterpret_cast<int32_t*>(
			(uintptr_t)GetModuleHandleA("engine2.dll") + 0x8ED620
			);
		inline int32_t* height = reinterpret_cast<int32_t*>(
			(uintptr_t)GetModuleHandleA("engine2.dll") + 0x8ED624
			);
		inline void* dwLocalPlayerController = reinterpret_cast<CCSPlayerController**>(
			(uintptr_t)GetModuleHandleA("client.dll") + 0x1E16870
			);
		inline void* dwLocalPlayerPawn = reinterpret_cast<C_CSPlayerPawn**>(
			(uintptr_t)GetModuleHandleA("client.dll") + 0x1BE7DA0
			);
		inline void* dwPlantedC4 = reinterpret_cast<void**>(
			(uintptr_t)GetModuleHandleA("client.dll") + 0x1E30360
			);
	} // namespace Offsets

	using DXGIPresentFn_t = HRESULT(__stdcall*)(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);
	inline DXGIPresentFn_t dxgiPresentFn = nullptr;
	inline DXGIPresentFn_t originalDXGIPresent = nullptr;

	using ConMsgFn_t = void(__stdcall*)(const char* fmt, ...);
	inline ConMsgFn_t ConMsg = nullptr;

	template <int Index, typename ReturnType, typename... Args>
	inline ReturnType CallVFunc(void* pThis, Args... args) {
		using func = ReturnType(__thiscall*)(void*, Args...);
		return (*(func**)(pThis))[Index](pThis, args...);
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

	class Pattern {
	private:
		std::vector<int> pattern_;
		uintptr_t foundAddress_ = 0;

		static std::vector<int> parsePattern(const char* patternStr) {
			std::vector<int> result;
			const char* p = patternStr;
			
			while (*p) {
				while (*p == ' ' || *p == '\t') p++;
				if (!*p) break;

				if (*p == '?') {
					result.push_back(-1);
					p++;
					if (*p == '?') p++;
				}
				else {
					char byteStr[3] = { 0 };
					if (*p && *(p + 1)) {
						byteStr[0] = *p++;
						byteStr[1] = *p++;
						result.push_back(static_cast<int>(strtol(byteStr, nullptr, 16)));
					}
				}
			}
			
			return result;
		}

		static bool comparePattern(const uint8_t* data, const std::vector<int>& pattern) {
			for (size_t i = 0; i < pattern.size(); i++) {
				if (pattern[i] != -1 && data[i] != static_cast<uint8_t>(pattern[i])) {
					return false;
				}
			}
			return true;
		}

	public:
		Pattern(const char* patternStr) : pattern_(parsePattern(patternStr)) {}

		Pattern& scanNow(const char* moduleName) {
			HMODULE hModule = GetModuleHandleA(moduleName);
			if (!hModule) {
				foundAddress_ = 0;
				return *this;
			}

			MODULEINFO modInfo;
			if (!GetModuleInformation(GetCurrentProcess(), hModule, &modInfo, sizeof(MODULEINFO))) {
				foundAddress_ = 0;
				return *this;
			}

			uintptr_t baseAddress = reinterpret_cast<uintptr_t>(modInfo.lpBaseOfDll);
			size_t moduleSize = modInfo.SizeOfImage;

			for (size_t i = 0; i < moduleSize - pattern_.size(); i++) {
				if (comparePattern(reinterpret_cast<uint8_t*>(baseAddress + i), pattern_)) {
					foundAddress_ = baseAddress + i;
					return *this;
				}
			}

			foundAddress_ = 0;
			return *this;
		}

		Pattern& getRIP(int offset = 3, int instructionSize = 7) {
			if (foundAddress_ == 0) {
				return *this;
			}

			int32_t relativeOffset = *reinterpret_cast<int32_t*>(foundAddress_ + offset);
			foundAddress_ = foundAddress_ + instructionSize + relativeOffset;
			return *this;
		}

		uintptr_t getAddress() const {
			return foundAddress_;
		}

		operator uintptr_t() const {
			return foundAddress_;
		}

		bool isValid() const {
			return foundAddress_ != 0;
		}
	};

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

				constexpr auto path = R"(C:\Users\Ben\AppData\Local\Microsoft\Windows\Fonts\JetBrainsMonoNerdFont-Regular.ttf)";
				if (std::filesystem::exists(path)) {
					io.Fonts->AddFontFromFileTTF(path, 16.0f);
					io.Fonts->Build();
				}
				else {
					io.Fonts->AddFontDefault();
				}

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

	inline void initPtrs() {
		uintptr_t t0Base = (uintptr_t)GetModuleHandleA("tier0.dll");
		uintptr_t conMsgA = t0Base + 0x7CDE0; // tier0.dll!ConMsg
		ConMsg = (ConMsgFn_t)(conMsgA);

		LOGINFO("tier0.dll base: 0x%p", (void*)t0Base);
		LOGINFO("ConMsg address: 0x%p", (void*)conMsgA);
	}

	inline void resetPtrs() {
		// TODO
	}

	class C_BaseEntity;
	class IEngineClient {
	public:
		int maxClients() {
			return CallVFunc<34u, int>(this);
		}

		bool shouldBeTrue() {
			return CallVFunc<10u, bool>(this);
		}

		bool isPlayerInputEnabled() {
			return CallVFunc<11u, bool>(this);
		}

		C_BaseEntity* getBaseEntByIndex(int index) {
			return CallVFunc<22u, C_BaseEntity*>(this, index);
		}
	};

	class ISchemaSystem;

	template <typename T>
	class CHandle;

	class C_GameEntitySystem {
	private:
		/* 0x000 */ char pad_0x000[0x20F0];
	public:
		/* 0x20F0 */ int nMaxEntities;

	public:
		template <typename T = C_BaseEntity>
		T* Get(int index) {
			return reinterpret_cast<T*>(this->GetEntityByIndex(index));
		}

		template <typename T = C_BaseEntity, typename H> // H = handle type (doesn't matter)
		T* Get(const CHandle<H>& handle) {
			return Get<T>(handle.GetEntryIndex());
		}

	private:
		void* GetEntityByIndex(int entryIndex) noexcept {
			static auto addy = Pattern("4C 8D 49 ? 81 FA").scanNow("client.dll").getAddress();
			using GetEntityByIndexFn_t = void* (__thiscall*)(void*, int);
			static auto fnGetEntityByIndex = reinterpret_cast<GetEntityByIndexFn_t>(addy);
			return fnGetEntityByIndex(this, entryIndex);
		}
	};

	class IGameResourceService {
	private:
		/* 0x0000 */ char pad_0x0000[0x58];
	public:
		/* 0x0058 */ C_GameEntitySystem* m_pGameEntitySystem;
	};
	class IMatchmaking;
	class ISceneSystem;
	class CTraceManager;

	namespace Interfaces {
		inline IEngineClient* GEngineClient = nullptr;
		inline ISchemaSystem* GSchemaSystem = nullptr;
		inline IGameResourceService* GGameResourceService = nullptr;
		inline IMatchmaking* GMatchmaking = nullptr;
		inline ISceneSystem* GSceneSystem = nullptr;
		inline CTraceManager* GTraceManager = nullptr;
	} // namespace Interfaces

#define INVALID_EHANDLE_INDEX 0xFFFFFFFF
#define ENT_ENTRY_MASK 0x7FFF
#define NUM_SERIAL_NUM_SHIFT_BITS 15
#define ENT_MAX_NETWORKED_ENTRY 16384

	template <typename T>
	class CHandle {
	public:
		CHandle() : index(INVALID_EHANDLE_INDEX) {}
		CHandle(const int nEntry, const int nSerial) noexcept {
			index = nEntry | (nSerial << NUM_SERIAL_NUM_SHIFT_BITS);
		}
		CHandle(const uint32_t nIndex) noexcept : index(nIndex) {}

		bool operator==(const CHandle& other) const noexcept {
			return index == other.index;
		}

		bool IsValid() const noexcept {
			return index != INVALID_EHANDLE_INDEX;
		}

		int GetEntryIndex() const noexcept {
			if (!IsValid())
				return ENT_ENTRY_MASK;
			return index & ENT_ENTRY_MASK;
		}

		int GetSerialNumber() const noexcept {
			if (!IsValid())
				return 0;
			return index >> NUM_SERIAL_NUM_SHIFT_BITS;
		}

		uint32_t GetIndex() const noexcept {
			return index;
		}

		int ID() const noexcept {
			return index & 0x1FF;
		}

		T* Get() const noexcept {
			if (!IsValid())
				return nullptr;
			return Interfaces::GGameResourceService->m_pGameEntitySystem->Get<T>(GetEntryIndex());
		}

	private:
		uint32_t index;
	};

	template <typename T>
	class CStrongHandle {
	public:
		operator T* () const {
			return binding ? (T*)(*binding) : nullptr;
		}

		T* operator->() const {
			return binding ? (T*)(*binding) : nullptr;
		}

	private:
		const void** binding;
	};

	struct KV3ID {
		const char* name;
		std::uint64_t unk0;
		std::uint64_t unk1;
	};

	class CKeyValues3 {
	private:
		/* 0x000 */ char pad_0x000[0x100];
	public:
		/* 0x100 */ std::uint64_t key;
		/* 0x108 */ void* pValue;
	private:
		/* 0x110 */ char pad_0x110[0x8];
	};

	template <typename T>
	class C_NetworkUtlVectorBase {
		// TODO: Implement..
	};

	class Color {
		int color32;
	public:
		Color() : color32(0) {}
		Color(int r, int g, int b, int a) {
			color32 = (a << 24) | (b << 16) | (g << 8) | r;
		}
		int r() const { return color32 & 0xFF; }
		int g() const { return (color32 >> 8) & 0xFF; }
		int b() const { return (color32 >> 16) & 0xFF; }
	};

	class LightDataEntry_t {
	private:
		int unk; // 0x0
		int unk2; // 0x4
		int unk3; // 0x8
		float unk4; // 0xC
	public:
		Color col; // 0x10
		int index; // 0x14
		int handle = -1; // 0x18
	private:
		int unk5; // 0x1C
	};
	struct LightData_t {
		char pad_0x000[0x8];
		LightDataEntry_t entries[0x100];
	};
	class ISceneSystem {
	private:
		char pad_0x000[0x3148];
	public:
		class {
		private:
			char pad_0x000[0x18];
		public:
			LightData_t* data;
		}* LightData;
	};

	class XyVec4 {
	public:
		float x; // 0x0
		float y; // 0x4
		float z; // 0x8
		float w; // 0xC
	};

	class CTextureDx11;
	class MaterialParameter_t {
	public:
		XyVec4 vec_value; // 0x0
		CTextureDx11** texture_value; // 0x10
		char pad_0x018[0x10]; // 0x18
		const char* parameter_name; // 0x28
		const char* text_value; // 0x30
		int64_t int_value; // 0x38
	};

	class CMaterial2 {
	public:
		char pad_0x000[0x10];
		int m_nParameterCount; // 0x10
		char pad_0x14[0x4]; // 0x14
		MaterialParameter_t* m_pParameter; // 0x18
		char pad_0x020[0x3D8];
		void* pMaterialMode;
		const char* getName() {
			using function_t = const char* (__thiscall*)(CMaterial2*);
			return (*reinterpret_cast<function_t**>(uint64_t(this)))[0](this);
		}

		MaterialParameter_t* findParameter2(const char* name) {
			for (int i = 0; i < m_nParameterCount; i++) {
				if (strcmp(m_pParameter[i].parameter_name, name) == 0) {
					return &m_pParameter[i];
				}
			}

			return nullptr;
		}
	};

	class CAggregateSceneObjectMaterialArray {
	public:
		CMaterial2* pMaterial;
		char pad_0x008[0x28];
	};


	class CSceneWorld;
	class CRenderMesh;

	class CAggregateSceneObjectDesc;
	class CAggregateSceneObject {
	public:
		void* vtable; // 0x0
		char pad_0x008[0x10]; // 0x8
		CAggregateSceneObjectDesc* pDesc; // 0x18
		void* pSomeArray; // 0x20
		char pad_0x028[0x88]; // 0x28
		CSceneWorld* pSceneWorld; // 0xB0
		char pad_0x0B8[0x18]; // 0xB8
		void* pModelArray; // 0xD0
		CAggregateSceneObjectMaterialArray* pMaterialArray; // 0xD8
		char pad_0xE0[0x18]; // 0xE0
		CRenderMesh* pRenderMesh; // 0xF8
		void* pSomeData; // 0x100
		char pad_0x108[0x30]; // 0x108
		int nSomeCount1; // 0x138
		char pad_0x13C[0x4]; // 0x13C
		void* pSomeData1; // 0x140
		char pad_0x148[0x8]; // 0x148
		int nCount; // 0x150
		char pad_0x154[0x4]; // 0x154
		void* pSomeData2; // 0x158
	};
	class _CAggregateSceneObjectData {
	public:
		char pad_0x000[0x4];
		int nCount;
		char pad_0x008[0x8];
		int nIndex;
	};
	class CAggregateObjectArr {
	public:
		CAggregateSceneObject* object;
		_CAggregateSceneObjectData* data;
	};

	class CTraceManager;

	using InstantiateInterfaceFn_t = void* (*)();

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
		inline T* Capture(const char* szInterfaceName) const {
			size_t nInterfaceNameLength = strlen(szInterfaceName);
			for (const CInterfaceRegister* pRegister = this; pRegister != nullptr; pRegister = pRegister->pNext) {
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

	namespace Interfaces {
		inline bool setupInterfaces() {
			bool success = true;

			const auto engineRegisterList = CInterfaceRegister::GetRegisterList(L"engine2.dll");
			success &= (engineRegisterList != nullptr);
			const auto scehemaRegisterList = CInterfaceRegister::GetRegisterList(L"schemasystem.dll");
			success &= (scehemaRegisterList != nullptr);
			const auto matchmakingRegisterList = CInterfaceRegister::GetRegisterList(L"matchmaking.dll");
			success &= (matchmakingRegisterList != nullptr);
			const auto sceneRegisterList = CInterfaceRegister::GetRegisterList(L"scenesystem.dll");
			success &= (sceneRegisterList != nullptr);

			GEngineClient = engineRegisterList->Capture<IEngineClient>("Source2EngineToClient001");
			success &= (GEngineClient != nullptr);
			GSchemaSystem = scehemaRegisterList->Capture<ISchemaSystem>("SchemaSystem_001");
			success &= (GSchemaSystem != nullptr);
			GGameResourceService = engineRegisterList->Capture<IGameResourceService>("GameResourceServiceClientV001");
			success &= (GGameResourceService != nullptr);
			GMatchmaking = matchmakingRegisterList->Capture<IMatchmaking>("GameTypes001");
			success &= (GMatchmaking != nullptr);
			GSceneSystem = sceneRegisterList->Capture<ISceneSystem>("SceneSystem_002");
			success &= (GSceneSystem != nullptr);

			// TODO: Set gTraceManager

			LOGINFO("Interfaces setup? %s", success ? "Yes" : "No");
			return success;
		}
	}

	class CSchemaSystemTypeScope;
	class CSchemaType;
	struct SchemaStaticFieldData_t;
	struct SchemaClassInfoData;
	struct SchemaBaseClass {
		/* 0x000 */ char pd_0x0[0x10];
		/* 0x010 */ const char* name;
	};

	struct SchemaBaseClassInfoData_t {
		/* 0x000 */ char pad_0x0[0x18];
		/* 0x018 */ SchemaBaseClass* info;
	};

	struct SchemaClassFieldData_t {
		/* 0x000 */ const char* fieldName;
		/* 0x008 */ CSchemaType* schemaType;
		/* 0x010 */ int32_t offset;
		/* 0x014 */ int32_t pad0;
		/* 0x018 */ int64_t pad1;
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
		// Find a declared class by name
		SchemaClassInfoData* FindDeclaredClass(const char* className) {
			if (!className)
				return nullptr;

			FNV1A_t hash = Hash(className);

			// Iterate through the hash table to find the class
			for (auto& classInfo : declaredClasses) {
				if (classInfo.name && strcmp(classInfo.name, className) == 0) {
					return &classInfo;
				}
			}

			return nullptr;
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
		/* 0x000 */ const char* fieldName;
		/* 0x008 */ CSchemaType* schemaType;
		/* 0x010 */ void* instance;

		/* 0x018 */ uint64_t pad_0x18;
		/* 0x020 */ uint64_t pad_0x20;
	};

	namespace schemas {
		inline int32_t GetSchemaOffset(const char* moduleName, const char* className, const char* fieldName) {
			if (!Interfaces::GSchemaSystem) {
				LOGINFO("SchemaSystem not initialized!");
				return 0;
			}

			CSchemaSystemTypeScope* typeScope = Interfaces::GSchemaSystem->FindTypeScopeForModule(moduleName);
			if (!typeScope) {
				LOGINFO("Failed to find type scope for module: %s", moduleName);
				return 0;
			}

			SchemaClassInfoData* classInfo = typeScope->FindDeclaredClass(className);
			if (!classInfo) {
				LOGINFO("Failed to find class: %s", className);
				return 0;
			}

			for (int16_t i = 0; i < classInfo->fieldsCount; i++) {
				if (std::string(fieldName) == classInfo->fields[i].fieldName) {
					return classInfo->fields[i].offset;
				}
			}

			LOGINFO("Failed to find field: %s in class: %s", fieldName, className);
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
	        return *(type *)((uint64_t)this + schemas::GetSchemaOffset(module_name, class_name, field_name)); \
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

#define SCHEMA_ADD_FIELD_OFFSET(TYPE, NAME, FIELD, ADDITIONAL) SCHEMA_ADD_OFFSET(TYPE, NAME, schemas::GetOffset(CS2::HashConst(FIELD)) + ADDITIONAL)
#define SCHEMA_ADD_FIELD(TYPE, NAME, FIELD) SCHEMA_ADD_FIELD_OFFSET(TYPE, NAME, FIELD, 0U)
#define SCHEMA_ADD_PFIELD_OFFSET(TYPE, NAME, FIELD, ADDITIONAL) SCHEMA_ADD_POFFSET(TYPE, NAME, schemas::GetOffset(CS2::HashConst(FIELD)) + ADDITIONAL)
#define SCHEMA_ADD_PFIELD(TYPE, NAME, FIELD) SCHEMA_ADD_PFIELD_OFFSET(TYPE, NAME, FIELD, 0U)

	// Main SDK. All above is for schema reflection and hooking...

	class CEntityInstance;
	class CEntityIdentity {
	public:
		SCHEMA_ADD_OFFSET(std::uint32_t, GetIndex, 0x10);
		SCHEMA(const char*, GetDesignerName, "m_designerName", "CEntityIdentity", "client.dll");
		SCHEMA(std::uint32_t, GetFlags, "m_flags", "CEntityIdentity", "client.dll");

		bool isValid() {
			return GetIndex() != INVALID_EHANDLE_INDEX;
		}

		int getEntryIndex() {
			if (!isValid())
				return ENT_ENTRY_MASK;

			return GetIndex() & ENT_ENTRY_MASK;
		}

		int getSerialNumber() {
			if (!isValid())
				return 0;
			return GetIndex() >> NUM_SERIAL_NUM_SHIFT_BITS;
		}

		CEntityInstance* pInstance;
	};

	class Vector3 {
	public:
		float x;
		float y;
		float z;

		bool isZero() const {
			return x == 0.0f && y == 0.0f && z == 0.0f;
		}
		bool operator==(const Vector3& other) const {
			return x == other.x && y == other.y && z == other.z;
		}
		bool operator!=(const Vector3& other) const {
			return !(*this == other);
		}
		bool operator<(const Vector3& other) const {
			if (x != other.x) return x < other.x;
			if (y != other.y) return y < other.y;
			return z < other.z;
		}
		bool operator<=(const Vector3& other) const {
			return *this < other || *this == other;
		}
		bool operator>(const Vector3& other) const {
			return !(*this <= other);
		}
		bool operator>=(const Vector3& other) const {
			return !(*this < other);
		}

		float length() const {
			return std::sqrt(x * x + y * y + z * z);
		}

		float lengthSqr() const {
			return x * x + y * y + z * z;
		}

		float DistanceTo(const Vector3& other) const {
			float dx = x - other.x;
			float dy = y - other.y;
			float dz = z - other.z;
			return std::sqrt(dx * dx + dy * dy + dz * dz);
		}
	};

	class CTransform {};

	class ViewMatrix_t {
	public:
		float* operator[](int index) { return matrix[index]; }
		float matrix[4][4];
	};

	// NOTE: These may need updating if the skeleton changes..
	enum BONEINDEX : int {
		PELVIS = 0, NECK = 5, HEAD = 6, LEFT_SHOULDER = 8, LEFT_ELBOW = 9, LEFT_HAND = 11,
		RIGHT_SHOULDER = 13, RIGHT_ELBOW = 14, RIGHT_HAND = 16, LEFT_LEG = 22, LEFT_KNEE = 23, LEFT_FOOT = 24,
		RIGHT_LEG = 25, RIGHT_KNEE = 26, RIGHT_FOOT = 27
	};
	static std::pair<int, int> bones[] = {
		{NECK, PELVIS}, {NECK, LEFT_SHOULDER}, {NECK, RIGHT_SHOULDER},
		{PELVIS, LEFT_LEG}, {PELVIS, RIGHT_LEG}, {LEFT_SHOULDER, LEFT_ELBOW}, {LEFT_ELBOW, LEFT_HAND},
		{RIGHT_SHOULDER, RIGHT_ELBOW}, {RIGHT_ELBOW, RIGHT_HAND}, {LEFT_LEG, LEFT_KNEE}, {LEFT_KNEE, LEFT_FOOT},
		{RIGHT_LEG, RIGHT_KNEE}, {RIGHT_KNEE, RIGHT_FOOT}
	};
	static int bonesToRead[] = {
		PELVIS,
		NECK,
		HEAD,
		LEFT_SHOULDER,
		LEFT_ELBOW,
		LEFT_HAND,
		RIGHT_SHOULDER,
		RIGHT_ELBOW,
		RIGHT_HAND,
		LEFT_LEG,
		LEFT_KNEE,
		LEFT_FOOT,
		RIGHT_LEG,
		RIGHT_KNEE,
		RIGHT_FOOT
	};

	class CMaterial2;
	class CMeshData;

#if 0
	class CGameSceneNode {
	public:
		SCHEMA(CEntityIdentity*, GetIdentity, "m_pOwner", "CGameSceneNode", "client.dll");
		SCHEMA(Vector3, GetAbsOrigin, "m_vecAbsOrigin", "CGameSceneNode", "client.dll");
		SCHEMA(bool, IsDormant, "m_bDormant", "CGameSceneNode", "client.dll");
		SCHEMA(CTransform, GetTransform, "m_nodeToWorld", "CGameSceneNode", "client.dll");

		// TODO: Get skeleton
	};

	// C_CSPlayerPawn : C_CSPlayerPawnBase : C_BasePlayerPawn : C_BaseCombatCharacter : C_BaseFlex : CBaseAnimGraph : C_BaseModelEntity : C_BaseEntity : CEntityInstance
	class CEntityInstance {};
	class C_BaseEntity : public CEntityInstance { // TODO: not finished! lol, so many netvars
	public:
		SCHEMA(std::int32_t, GetHealth, "m_iHealth", "C_BaseEntity", "client.dll");
		SCHEMA(std::uint8_t, GetTeam, "m_iTeamNum", "C_BaseEntity", "client.dll");
		SCHEMA(CGameSceneNode*, GetGameSceneNode, "m_pGameSceneNode", "C_BaseEntity", "client.dll");
	};

	class C_PlayerPing : C_BaseEntity {
	public:
		SCHEMA(CHandle, m_hPlayer, "m_hPlayer", "C_PlayerPing", "client.dll");
		SCHEMA(CHandle, m_hPingedEntity, "m_hPingedEntity", "C_PlayerPing", "client.dll");
		SCHEMA(int32, m_iType, "m_iType", "C_PlayerPing", "client.dll");
		SCHEMA(bool, m_bUrgent, "m_bUrgent", "C_PlayerPing", "client.dll");
		SCHEMA(char*, m_szPlaceName, "m_szPlaceName", "C_PlayerPing", "client.dll");
	};
	class CPlayerComponent {}; // no netvars
	class CCSPlayer_PingServices : public CPlayerComponent {
	public:
		SCHEMA(CHandle, m_hPlayerPing, "m_hPlayerPing", "CCSPlayer_PingServices", "client.dll");
	};
	class CCSPlayer_BulletServices : public CPlayerComponent {
	public:
		SCHEMA(int32, m_totalHitsOnServer, "m_totalHitsOnServer", "CCSPlayer_BulletServices", "client.dll");
	};
	class CSPlayerState {}; // no netvars

	class C_BaseModelEntity : public C_BaseEntity {};
	class CBaseAnimGraph : public C_BaseModelEntity {};
	class C_BaseFlex : public CBaseAnimGraph {};
	class C_BaseCombatCharacter : public C_BaseFlex {};
	class C_BasePlayerPawn : public C_BaseCombatCharacter {};
	class C_CSPlayerPawnBase : public C_BasePlayerPawn {
	public:
		SCHEMA(CCSPlayer_PingServices*, m_pPingServices, "m_pPingServices", "C_CSPlayerPawnBase", "client.dll");
		SCHEMA(CSPlayerState, m_previousPlayerState, "m_previousPlayerState", "C_CSPlayerPawnBase", "client.dll");
		SCHEMA(CSPlayerState, m_iPlayerState, "m_iPlayerState", "C_CSPlayerPawnBase", "client.dll");
		SCHEMA(bool, m_bHasMovedSinceSpawn, "m_bHasMovedSinceSpawn", "C_CSPlayerPawnBase", "client.dll");
		SCHEMA(GameTime_t, m_flLastSpawnTimeIndex, "m_flLastSpawnTimeIndex", "C_CSPlayerPawnBase", "client.dll");
		SCHEMA(int32, m_iProgressBarDuration, "m_iProgressBarDuration", "C_CSPlayerPawnBase", "client.dll");
		SCHEMA(float32, m_flProgressBarStartTime, "m_flProgressBarStartTime", "C_CSPlayerPawnBase", "client.dll");
		SCHEMA(GameTime_t, m_flClientDeathTime, "m_flClientDeathTime", "C_CSPlayerPawnBase", "client.dll");
		SCHEMA(float32, m_flFlashBangTime, "m_flFlashBangTime", "C_CSPlayerPawnBase", "client.dll");
		SCHEMA(float32, m_flFlashScreenshotAlpha, "m_flFlashScreenshotAlpha", "C_CSPlayerPawnBase", "client.dll");
		SCHEMA(float32, m_flFlashOverlayAlpha, "m_flFlashOverlayAlpha", "C_CSPlayerPawnBase", "client.dll");
		SCHEMA(bool, m_bFlashBuildUp, "m_bFlashBuildUp", "C_CSPlayerPawnBase", "client.dll");
		SCHEMA(bool, m_bFlashDspHasBeenCleared, "m_bFlashDspHasBeenCleared", "C_CSPlayerPawnBase", "client.dll");
		SCHEMA(bool, m_bFlashScreenshotHasBeenGrabbed, "m_bFlashScreenshotHasBeenGrabbed", "C_CSPlayerPawnBase", "client.dll");
		SCHEMA(float32, m_flFlashMaxAlpha, "m_flFlashMaxAlpha", "C_CSPlayerPawnBase", "client.dll");
		SCHEMA(float32, m_flFlashDuration, "m_flFlashDuration", "C_CSPlayerPawnBase", "client.dll");
		SCHEMA(GameTime_t, m_flClientHealthFadeChangeTimestamp, "m_flClientHealthFadeChangeTimestamp", "C_CSPlayerPawnBase", "client.dll");
		SCHEMA(int32, m_nClientHealthFadeParityValue, "m_nClientHealthFadeParityValue", "C_CSPlayerPawnBase", "client.dll");
		SCHEMA(float32, m_fNextThinkPushAway, "m_fNextThinkPushAway", "C_CSPlayerPawnBase", "client.dll");
		SCHEMA(float32, m_flCurrentMusicStartTime, "m_flCurrentMusicStartTime", "C_CSPlayerPawnBase", "client.dll");
		SCHEMA(float32, m_flMusicRoundStartTime, "m_flMusicRoundStartTime", "C_CSPlayerPawnBase", "client.dll");
		SCHEMA(bool, m_bDeferStartMusicOnWarmup, "m_bDeferStartMusicOnWarmup", "C_CSPlayerPawnBase", "client.dll");
		SCHEMA(float32, m_flLastSmokeOverlayAlpha, "m_flLastSmokeOverlayAlpha", "C_CSPlayerPawnBase", "client.dll");
		SCHEMA(float32, m_flLastSmokeAge, "m_flLastSmokeAge", "C_CSPlayerPawnBase", "client.dll");
		SCHEMA(Vector3, m_vLastSmokeOverlayColor, "m_vLastSmokeOverlayColor", "C_CSPlayerPawnBase", "client.dll");
		SCHEMA(CHandle, m_hOriginalController, "m_hOriginalController", "C_CSPlayerPawnBase", "client.dll");
	};
	class C_CSPlayerPawn : public C_CSPlayerPawnBase {
	};
#endif
} // namespace CS2

#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <dxgi.h>

#include <cstdint>
#include <vector>
#include <span>
#include <string>
#include <ranges>

#include <vendor/fnva1.h>

#define LOGINFO(fmt, ...) \
	do { \
		if (CS2::ConMsg) { \
			CS2::ConMsg("[CS2i] " fmt "\n", ##__VA_ARGS__); \
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

	class CSchemaSystem;
	class CSchemaSystemTypeScope;
	class CSchemaType_XXX;
	struct SchemaClassFieldData_t;
	struct SchemaBaseClassInfoData_t;
	struct SchemaStaticFieldData_t;
	struct SchemaClassInfoData_t;

	struct SchemaData_t {
		FNV1A_t uHashedFieldName;
		std::uint32_t uOffset;
	};

	inline static std::vector<SchemaData_t> SchemaData;

	template <class T>
	class CUtlVector {
	public:
		int m_Size;
		T* m_Elements;

		T& operator[](int i) { return m_Elements[i]; }

		std::span<T> ToSpan() {
			return std::span<T>(m_Elements, m_Size);
		}
	};

	template <int Index, typename ReturnType, typename... Args>
	inline ReturnType CallVFunc(void* pThis, Args... args) {
		using func = ReturnType(__thiscall*)(void*, Args...);
		return (*(func**)(pThis))[Index](pThis, args...);
	}

	struct SchemaBaseClassInfoData_t {
		uint64_t               pad0;        // 0x00
		SchemaClassInfoData_t* classInfo; // 0x08
	};

	class CSchemaSystemTypeScope {
	public:
		void* vtable;            // 0x00
		char  name[0x100]; // 0x08
		// CUtlTSHash<CSchemaClassBinding> 0x588
		// CUtlTSHash<CSchemaEnumBinding>  0x2DD0

		void FindDeclaredClass(SchemaClassInfoData_t** classInfo, const char* className) {
			CallVFunc<2, void*>(this, &classInfo, className);
		}

		SchemaClassInfoData_t* FindDeclaredClass(const char* className) {
			if (this == nullptr)
				return nullptr;

			SchemaClassInfoData_t* classInfo = nullptr;
			CallVFunc<2, void*>(this, &classInfo, className);
			return classInfo;
		}
	};

	// https://github.com/a2x/cs2-dumper/tree/daef095f2f4c18be821cbe35ebf0b0adc132435c/src/source2/schema_system
	// https://github.com/bruhmoment21/cs2-sdk/blob/v2/cs2-sdk/sdk/include/interfaces/schemasystem.hpp
	struct SchemaClassInfoData_t {
		uint64_t    pad0;         // 0x00
		const char* className;  // 0x08
		const char* moduleName; // 0x10

		int32_t sizeOf;      // 0x18
		int16_t fieldsCount; // 0x1C
		int16_t staticCount; // 0x1E

		int16_t metadataCount;    // 0x20
		int8_t  align;          // 0x22 align :-1
		int8_t  baseClassesCount; // 0x23 base : 1
		int16_t pad2;               // 0x24
		int16_t pad3;               // 0x26

		SchemaClassFieldData_t* fields;       // 0x28
		SchemaStaticFieldData_t* staticFields; // 0x30
		SchemaBaseClassInfoData_t* baseClasses;  // 0x38

		void* pad4;         // 0x40
		void* metadata;   // 0x48 SchemaMetadataSetData_t
		CSchemaSystemTypeScope* typeScope;  // 0x50
		CSchemaType_XXX* schemaType; // 0x58 CSchemaType_DeclaredClass
		uint64_t                classFlags; // 0x60 SchemaClassFlags_t

		bool InheritsFrom(SchemaClassInfoData_t* pClassInfo) {
			if (pClassInfo == this && pClassInfo != nullptr)
				return true;
			else if (baseClasses == nullptr || pClassInfo == nullptr)
				return false;

			for (int i = 0; i < baseClassesCount; i++) {
				auto& baseClass = baseClasses[i];
				if (baseClass.classInfo->InheritsFrom(pClassInfo))
					return true;
			}

			return false;
		}

		void Dump() {
			if (this == nullptr)
				return;

			LOGINFO("// SchemaClassInfoData_t: 0x%p", this);
			LOGINFO("// m_ClassName: %s", this->className);
			LOGINFO("// m_ModuleName: %s", this->moduleName);
			LOGINFO("// m_SizeOf: 0x%X", this->sizeOf);
			LOGINFO("// m_FieldsCount: %d", this->fieldsCount);
			LOGINFO("// m_StaticCount: %d", this->staticCount);
			LOGINFO("// m_MetadataCount: %d", this->metadataCount);
			LOGINFO("// m_AlignOf: %d", this->align);
			LOGINFO("// m_BaseClassesCount: %d", this->baseClassesCount);
			LOGINFO("// pad2: %d", this->pad2);
			LOGINFO("// pad3: %d", this->pad3);
			if (this->baseClasses != nullptr)
				LOGINFO("// BaseClass: %s", this->baseClasses->classInfo->className);

			LOGINFO("namespace %s {", this->className);
			for (size_t i = 0; i < this->fieldsCount; i++) {
				LOGINFO("    constexpr std::ptrdiff_t %s = 0x%X; // %s",
					this->fields[i].fieldName,
					this->fields[i].offset,
					this->fields[i].schemaType->typeName);
			}
			LOGINFO("}\n");

			if (this->baseClasses != nullptr)
				this->baseClasses->classInfo->Dump();
		}
	};

	class CSchemaSystemTypeScope;
	class ISchemaSystem {
	public:
		char pad[0x188];
		CUtlVector<CSchemaSystemTypeScope*> typeScope; // 0x188

	public:
		CSchemaSystemTypeScope* FindTypeScopeForModule(const char* moduleName) {
			return CallVFunc<13u, CSchemaSystemTypeScope*>(this, moduleName, nullptr);
		}

		void dumpAllClasses() {
			for (size_t i = 0; i < typeScope.m_Size; i++) {
				CSchemaSystemTypeScope* pTypeScope = typeScope.m_Elements[i];
				if (pTypeScope == nullptr)
					continue;

				SchemaClassInfoData_t* pClassInfo = pTypeScope->FindDeclaredClass("CBaseEntity");
				if (pClassInfo != nullptr) {
					pClassInfo->Dump();
				}
			}
		}
	};

	class CSchemaType_XXX {
	public:
		virtual void* VirtualFunction_0() {} // 0x00
		const char* typeName;            // 0x08
		CSchemaSystemTypeScope* typeScope;           // 0x10
	};

	struct SchemaClassFieldData_t {
		const char* fieldName;  // 0x00
		CSchemaType_XXX* schemaType; // 0x08
		int32_t          offset;     // 0x10
		int32_t          pad0;         // 0x14
		int64_t          pad1;         // 0x18
	};

	struct SchemaStaticFieldData_t {
		const char* fieldName;  // 0x0000
		CSchemaType_XXX* schemaType; // 0x0008
		void* instance;   // 0x0010

		uint64_t pad_0x18; // 0x0018
		uint64_t pad_0x20; // 0x0020
	};

	namespace schemas {
		inline int32_t GetSchemaOffset(const char* moduleName, const char* className, const char* fieldName) {
			SchemaClassInfoData_t* classInfo = Interfaces::GSchemaSystem->FindTypeScopeForModule(moduleName)->FindDeclaredClass(className);
			for (int16_t i = 0; i < classInfo->fieldsCount; i++) {
				if (std::string(fieldName) == classInfo->fields[i].fieldName) {
					return classInfo->fields[i].offset;
				}
			}

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

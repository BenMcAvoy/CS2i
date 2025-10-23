#include "injection.h"

#include "vendor/xorstr.h"

void __stdcall shellcode(ManualMappingData* pData);

bool manualMap(HANDLE hProc, std::string_view dllFile) {
	BYTE* pSrcData = nullptr;
	IMAGE_NT_HEADERS* pOldNtHeader = nullptr;
	IMAGE_OPTIONAL_HEADER* pOldOptHeader = nullptr;
	IMAGE_FILE_HEADER* pOldFileHeader = nullptr;
	BYTE* pTargetBase = nullptr;

	if (!std::filesystem::exists(dllFile)) {
		LERR(xorstr_("DLL file does not exist: ") << dllFile);
		return false;
	}

	std::ifstream ifs(dllFile.data(), std::ios::binary | std::ios::ate);
	if (!ifs.is_open()) {
		LERR(xorstr_("Failed to open DLL file: ") << dllFile);
		return false;
	}
	auto fileSize = ifs.tellg();
	ifs.seekg(0, std::ios::beg);

	pSrcData = new BYTE[(size_t)fileSize];
	ifs.read(reinterpret_cast<char*>(pSrcData), fileSize);
	ifs.close();

	if (*(WORD*)pSrcData != IMAGE_DOS_SIGNATURE) {
		LERR(xorstr_("Invalid DOS signature."));
		delete[] pSrcData;
		return false;
	}

	LINF(xorstr_("Valid DOS signature confirmed."));

	pOldNtHeader = (IMAGE_NT_HEADERS*)(pSrcData + ((IMAGE_DOS_HEADER*)pSrcData)->e_lfanew);
	if (pOldNtHeader->Signature != IMAGE_NT_SIGNATURE) {
		LERR(xorstr_("Invalid NT signature."));
		delete[] pSrcData;
		return false;
	}
	LINF(xorstr_("Valid NT signature confirmed."));

	pOldFileHeader = &pOldNtHeader->FileHeader;
	pOldOptHeader = &pOldNtHeader->OptionalHeader;

	LINF(xorstr_("DLL Architecture: ") << (pOldOptHeader->Magic == IMAGE_NT_OPTIONAL_HDR32_MAGIC ? xorstr_("x86") : (pOldOptHeader->Magic == IMAGE_NT_OPTIONAL_HDR64_MAGIC ? xorstr_("x64") : xorstr_("Unknown"))));
	LINF(xorstr_("ImageBase: 0x") << std::hex << pOldOptHeader->ImageBase);

#ifdef _WIN64
	if (pOldOptHeader->Magic != IMAGE_NT_OPTIONAL_HDR64_MAGIC) {
		LERR(xorstr_("DLL is not x64."));
		delete[] pSrcData;
		return false;
	}
#elif _WIN32
	if (pOldOptHeader->Magic != IMAGE_NT_OPTIONAL_HDR32_MAGIC) {
		LERR(xorstr_("DLL is not x86."));
		delete[] pSrcData;
		return false;
	}
#else
#error Unknown platform
#endif

	LINF(xorstr_("DLL Architecture matches the injector."));

	pTargetBase = (BYTE*)VirtualAllocEx(hProc, (LPVOID)pOldOptHeader->ImageBase, pOldOptHeader->SizeOfImage, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
	if (!pTargetBase) {
		// Allocate anywhere instead of preferred base
		pTargetBase = (BYTE*)VirtualAllocEx(hProc, NULL, pOldOptHeader->SizeOfImage, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
		if (!pTargetBase) {
			LERR(xorstr_("VirtualAllocEx failed. Error: ") << GetLastError());
			delete[] pSrcData;
			return false;
		}

		LWRN(xorstr_("Preferred ImageBase is unavailable, allocated elsewhere"));
	}

	LINF(xorstr_("Allocated memory in target process at: 0x") << std::hex << (uintptr_t)pTargetBase);

	ManualMappingData data = { 0 };
	data.pLoadLibraryA = LoadLibraryA;
	data.pGetProcAddress = GetProcAddress;

	int sectionsCopied = 0;

	auto pSectionHeader = IMAGE_FIRST_SECTION(pOldNtHeader);
	for (UINT i = 0; i < pOldNtHeader->FileHeader.NumberOfSections; i++, pSectionHeader++) {
		if (pSectionHeader->SizeOfRawData == 0)
			continue;

		if (!WriteProcessMemory(
			hProc, pTargetBase + pSectionHeader->VirtualAddress, pSrcData + pSectionHeader->PointerToRawData,
			pSectionHeader->SizeOfRawData, nullptr
		)) {
			LERR(xorstr_("WriteProcessMemory failed for section ") << std::string((char*)pSectionHeader->Name, strnlen_s((char*)pSectionHeader->Name, IMAGE_SIZEOF_SHORT_NAME)) << xorstr_(". Error: ") << GetLastError());
			VirtualFreeEx(hProc, pTargetBase, 0, MEM_RELEASE);
			delete[] pSrcData;
			return false;
		}

		sectionsCopied++;
	}

	memcpy(pSrcData, &data, sizeof(ManualMappingData));
	if (!WriteProcessMemory(hProc, pTargetBase, pSrcData, 0x1000, nullptr)) {
		LERR(xorstr_("WriteProcessMemory failed for ManualMappingData. Error: ") << GetLastError());
		VirtualFreeEx(hProc, pTargetBase, 0, MEM_RELEASE);
		delete[] pSrcData;
		return false;
	}

	delete[] pSrcData;
	LINF(xorstr_("Copied ") << sectionsCopied << xorstr_(" sections to target process."));

	data.hinstDLL = (HINSTANCE)pTargetBase;

	void* pShellcode = VirtualAllocEx(hProc, nullptr, 0x1000, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
	if (!pShellcode) {
		LERR(xorstr_("VirtualAllocEx failed for shellcode. Error: ") << GetLastError());
		VirtualFreeEx(hProc, pTargetBase, 0, MEM_RELEASE);
		return false;
	}

	if (!WriteProcessMemory(hProc, pShellcode, (LPCVOID)shellcode, 0x1000, nullptr)) {
		LERR(xorstr_("WriteProcessMemory failed for shellcode. Error: ") << GetLastError());
		VirtualFreeEx(hProc, pTargetBase, 0, MEM_RELEASE);
		VirtualFreeEx(hProc, pShellcode, 0, MEM_RELEASE);
		return false;
	}

	HANDLE hThread = CreateRemoteThread(hProc, nullptr, 0, (LPTHREAD_START_ROUTINE)pShellcode, pTargetBase, 0, nullptr);
	if (!hThread) {
		LERR(xorstr_("CreateRemoteThread failed. Error: ") << GetLastError());
		VirtualFreeEx(hProc, pShellcode, 0, MEM_RELEASE);
		VirtualFreeEx(hProc, pTargetBase, 0, MEM_RELEASE);
		return false;
	}

	WaitForSingleObject(hThread, INFINITE);
	CloseHandle(hThread);
	VirtualFreeEx(hProc, pShellcode, 0, MEM_RELEASE);

	HINSTANCE hCheck;
	while (true) {
		if (!ReadProcessMemory(hProc, pTargetBase, &hCheck, sizeof(HINSTANCE), nullptr)) {
			LERR(xorstr_("ReadProcessMemory failed. Error: ") << GetLastError());
			VirtualFreeEx(hProc, pTargetBase, 0, MEM_RELEASE);
			return false;
		}
		if (hCheck != NULL)
			break;
		Sleep(10);
	}

	LINF(xorstr_("Manual mapping completed successfully."));
	return true;
}

#define RELOC_FLAG32(RelInfo) ((RelInfo >> 0x0C) == IMAGE_REL_BASED_HIGHLOW)
#define RELOC_FLAG64(RelInfo) ((RelInfo >> 0x0C) == IMAGE_REL_BASED_DIR64)

#if defined(_WIN64)
#define RELOC_FLAG RELOC_FLAG64
#else
#define RELOC_FLAG RELOC_FLAG32
#endif

void __stdcall shellcode(ManualMappingData* pData) {
	if (!pData) return;

	auto* pBase = (BYTE*)pData;
	auto pOptional = &reinterpret_cast<IMAGE_NT_HEADERS*>(pBase + ((IMAGE_DOS_HEADER*)pBase)->e_lfanew)->OptionalHeader;

	auto _LoadLibraryA = pData->pLoadLibraryA;
	auto _GetProcAddress = pData->pGetProcAddress;
	auto _DllEntryPoint = (fDllEntryPoint)(pBase + pOptional->AddressOfEntryPoint);

	// Relocations
	BYTE* pDelta = pBase - pOptional->ImageBase;
	if (pDelta != 0) {
		if (pOptional->DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC].Size == 0)
			return;

		auto pReloc = (IMAGE_BASE_RELOCATION*)(pBase + pOptional->DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC].VirtualAddress);
		while (pReloc->VirtualAddress) {
			UINT entryCount = (pReloc->SizeOfBlock - sizeof(IMAGE_BASE_RELOCATION)) / sizeof(WORD); // WORDs after the header
			WORD* pEntry = (WORD*)(pReloc + 1);

			for (UINT i = 0; i != entryCount; i++, pEntry++) {
				if (RELOC_FLAG(*pEntry)) {
					UINT_PTR* pPatch = (UINT_PTR*)(pBase + pReloc->VirtualAddress + ((*pEntry) & 0x0FFF)); // Offset is lower 12 bits
					*pPatch += (UINT_PTR)pDelta;
				}
			}
			pReloc = (IMAGE_BASE_RELOCATION*)((BYTE*)pReloc + pReloc->SizeOfBlock); // Move to next block
		}
	}

	// Load dependencies (imports)
	if (pOptional->DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].Size) {
		auto pImportDescription = (IMAGE_IMPORT_DESCRIPTOR*)(pBase + pOptional->DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress);
		while (pImportDescription->Name) {
			char* szMod = (char*)(pBase + pImportDescription->Name);
			HINSTANCE hMod = _LoadLibraryA(szMod);
			
			if (!hMod) {
				pImportDescription++;
				continue;
			}
			
			ULONG_PTR* pThunkRef = (ULONG_PTR*)(pBase + pImportDescription->OriginalFirstThunk);
			ULONG_PTR* pFuncRef = (ULONG_PTR*)(pBase + pImportDescription->FirstThunk);

			if (!pThunkRef) pThunkRef = pFuncRef;

			for (; *pThunkRef; pThunkRef++, pFuncRef++) {
				if (IMAGE_SNAP_BY_ORDINAL(*pThunkRef)) {
					*pFuncRef = (ULONG_PTR)_GetProcAddress(hMod, (LPCSTR)IMAGE_ORDINAL(*pThunkRef));
				}
				else {
					auto pImport = (IMAGE_IMPORT_BY_NAME*)(pBase + (*pThunkRef));
					*pFuncRef = (ULONG_PTR)_GetProcAddress(hMod, pImport->Name);
				}
				
				if (!*pFuncRef) {
					return;
				}
			}
			pImportDescription++;
		}
	}

	// TLS setup (call callbacks)
	if (pOptional->DataDirectory[IMAGE_DIRECTORY_ENTRY_TLS].Size) {
		auto pTLS = (IMAGE_TLS_DIRECTORY*)(pBase + pOptional->DataDirectory[IMAGE_DIRECTORY_ENTRY_TLS].VirtualAddress);
		auto pCallback = (PIMAGE_TLS_CALLBACK*)pTLS->AddressOfCallBacks;
		if (pCallback) {
			for (; *pCallback; pCallback++) {
				(*pCallback)((LPVOID)pBase, DLL_PROCESS_ATTACH, nullptr);
			}
		}
	}

	_DllEntryPoint((HINSTANCE)pBase, DLL_PROCESS_ATTACH, nullptr);
	pData->hinstDLL = (HINSTANCE)pBase;
}

#pragma once

#include "common.h"

using fLoadLibraryA		= HINSTANCE	(WINAPI*)(LPCSTR);
using fGetProcAddress	= FARPROC	(WINAPI*)(HINSTANCE, LPCSTR);
using fDllEntryPoint	= BOOL		(WINAPI*)(HINSTANCE, DWORD, LPVOID);

struct ManualMappingData {
	fLoadLibraryA		pLoadLibraryA;
	fGetProcAddress		pGetProcAddress;
	HINSTANCE 			hinstDLL;
	fDllEntryPoint		pDllEntryPoint;
};

bool manualMap(HANDLE hProc, std::string_view dllFile);

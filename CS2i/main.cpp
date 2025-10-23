#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "sdk.h"

DWORD WINAPI MainThread(LPVOID lpParam) {
	//while (!IsDebuggerPresent()) Sleep(100);

	CS2::initPtrs();
	CS2::Interfaces::setupInterfaces();

	CS2::Interfaces::GSchemaSystem->dumpAllClasses();

	//Sleep(1000);
	//CS2::resetPtrs();
	return 0;
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {
	if (fdwReason == DLL_PROCESS_ATTACH) {
		DisableThreadLibraryCalls(hinstDLL);
		CreateThread(nullptr, 0, MainThread, nullptr, 0, nullptr);
	}

	return TRUE;
}
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {
	if (fdwReason == DLL_PROCESS_ATTACH) {
		MessageBoxA(NULL, "DummyDLL loaded!", "Info", MB_OK | MB_ICONINFORMATION);
	}

	return TRUE;
}
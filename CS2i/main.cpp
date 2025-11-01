#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <vector>
#include <memory>

#include "sdk.h"
#include "sdk-gen.h"

#include <minhook.h>

#include "Feature.h"
#include "PlayerESP.h"
#include "WeaponESP.h"
#include "WorldTint.h"
#include "SchemaExplorer.h"

DWORD WINAPI MainThread(LPVOID lpParam) {
    SetUnhandledExceptionFilter([](EXCEPTION_POINTERS* ExceptionInfo) -> LONG {
        do {
            if (CS2::ConMsg) {
				CS2::ConMsg("[CS2i] " "Unhandled exception: code 0x%X at address 0x%p" "\n", ExceptionInfo->ExceptionRecord->ExceptionCode, ExceptionInfo->ExceptionRecord->ExceptionAddress);
            }
            else {
                MessageBoxA(0, "ConMsg not initialized!", "CS2i", 0x00000000L);
            }
        } while (0);
		// swallow the exception
		return EXCEPTION_CONTINUE_EXECUTION;
        });

    CS2::initPtrs();
    CS2::Interfaces::setupInterfaces();

    std::vector<std::unique_ptr<Feature>> features;
	features.push_back(std::make_unique<WeaponESP>());
	features.push_back(std::make_unique<WorldTint>());
	features.push_back(std::make_unique<SchemaExplorer>());
	features.push_back(std::make_unique<PlayerESP>()); // render last, nothing should overlay this

    MH_Initialize();

    static bool* outerTakesFocus = nullptr;

    auto& presentManager = CS2::PresentManager_t::get();
    presentManager.setOnPresentCallback([&features](bool& takesFocus, IDXGISwapChain* /*pSwapChain*/, UINT /*SyncInterval*/, UINT /*Flags*/) {
        outerTakesFocus = &takesFocus;

        for (auto& feature : features) {
            feature->update(takesFocus);
        }
    });

    while (!GetAsyncKeyState(VK_END)) {
        if (GetAsyncKeyState(VK_INSERT) & 1) {
            if (outerTakesFocus) *outerTakesFocus = !*outerTakesFocus;
        }
        Sleep(100);
    }

    MH_Uninitialize();

    presentManager.shutdown();
    return 0;
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID /*lpvReserved*/) {
    if (fdwReason == DLL_PROCESS_ATTACH) {
        DisableThreadLibraryCalls(hinstDLL);
        CreateThread(nullptr, 0, MainThread, nullptr, 0, nullptr);
    }

    return TRUE;
}

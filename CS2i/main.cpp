#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <vector>
#include <memory>

#include "sdk.h"
#include "sdk-gen.h"

#include <minhook.h>

#include "Feature.h"
#include "PlayerESP.h"
#include "EntityESP.h"
#include "WorldTint.h"
#include "SchemaExplorer.h"

DWORD WINAPI MainThread(LPVOID lpParam) {
    CS2::initPtrs();
    CS2::Interfaces::setupInterfaces();

    std::vector<std::unique_ptr<Feature>> features;
    features.push_back(std::make_unique<PlayerESP>());

    auto* entityESP = new EntityESP();
    features.push_back(std::unique_ptr<Feature>(entityESP));

    auto* worldTint = new WorldTint();
    features.push_back(std::unique_ptr<Feature>(worldTint));

    auto* schemaExplorer = new SchemaExplorer();
    features.push_back(std::unique_ptr<Feature>(schemaExplorer));

    MH_Initialize();

    static bool* outerTakesFocus = nullptr;

    auto& presentManager = CS2::PresentManager_t::get();
    presentManager.setOnPresentCallback([&features, &entityESP, &worldTint, &schemaExplorer](bool& takesFocus, IDXGISwapChain* /*pSwapChain*/, UINT /*SyncInterval*/, UINT /*Flags*/) {
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

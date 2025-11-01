#include "WorldTint.h"
#include "sdk-gen.h"
#include <cstring>

void WorldTint::update(bool menuOpen) {
    if (enabled) {
        auto& eSys = CS2::Interfaces::GGameResourceService->m_pGameEntitySystem;
        if (!eSys) return;
        
        auto localPlayer = *reinterpret_cast<CS2::C_CSPlayerPawn**>(CS2::Offsets::dwLocalPlayerPawn);
        
        static CS2::Color tintCol = CS2::Color(255, 128, 255, 255);
        tintCol = CS2::Color(
            static_cast<uint8_t>(tintColor[0] * 255),
            static_cast<uint8_t>(tintColor[1] * 255),
            static_cast<uint8_t>(tintColor[2] * 255),
            255
        );
        
        if (localPlayer && localPlayer->m_pCameraServices()) {
            auto* fogColor = localPlayer->m_pCameraServices()->m_OverrideFogColor();
            auto* fogEnabled = localPlayer->m_pCameraServices()->m_bOverrideFogColor();
            if (fogColor && fogEnabled) {
                *fogColor = tintCol;
                *fogEnabled = true;
            }
        }
        
        for (int i = 0; i < 0xFFFF; i++) {
            auto* baseEnt = eSys->Get(i);
            if (!baseEnt) continue;

            auto* gameSceneNode = baseEnt->m_pGameSceneNode();
            if (!gameSceneNode) continue;

            auto* owner = gameSceneNode->m_pOwner();
            if (!owner) continue;

            auto* identity = owner->m_pEntity();
            if (!identity) continue;

            const char* designerName = identity->GetDesignerName();
            if (!designerName) continue;

            if (std::strcmp(designerName, "env_sky") == 0) {
                CS2::C_EnvSky* pSky = reinterpret_cast<CS2::C_EnvSky*>(identity->pInstance);
                if (pSky) {
                    pSky->m_bEnabled() = true;
                    pSky->m_vTintColor() = tintCol;
                    pSky->m_vTintColorLightingOnly() = tintCol;
                }
            } else if (std::strcmp(designerName, "env_combined_light_probe_volume") == 0) {
                CS2::C_EnvCombinedLightProbeVolume* pProbe = reinterpret_cast<CS2::C_EnvCombinedLightProbeVolume*>(baseEnt);
                if (pProbe) {
                    pProbe->m_Entity_Color() = tintCol;
                }
            } else if (std::strcmp(designerName, "light_barn") == 0) {
                CS2::C_BarnLight* pBarnLight = reinterpret_cast<CS2::C_BarnLight*>(baseEnt);
                pBarnLight->m_Color() = tintCol;
            } else if (std::strcmp(designerName, "light_rect") == 0) {
                CS2::C_RectLight* pRectLight = reinterpret_cast<CS2::C_RectLight*>(baseEnt);
                pRectLight->m_Color() = tintCol;
            }
        }
    } else {
        auto localPlayer = *reinterpret_cast<CS2::C_CSPlayerPawn**>(CS2::Offsets::dwLocalPlayerPawn);
        if (localPlayer && localPlayer->m_pCameraServices()) {
            auto* fogEnabled = localPlayer->m_pCameraServices()->m_bOverrideFogColor();
            if (fogEnabled) {
                *fogEnabled = false;
            }
        }
    }
}

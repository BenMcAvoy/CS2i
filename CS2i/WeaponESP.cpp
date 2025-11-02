#include "WeaponESP.h"
#include "sdk-gen.h"

bool WeaponESP::W2S(ImVec2& out, const CS2::Vector3& in) {
    auto vm = *CS2::Offsets::viewMatrix;
    float w = vm[3][0] * in.x + vm[3][1] * in.y + vm[3][2] * in.z + vm[3][3];
    if (w < 0.01f)
        return false;

    float invW = 1.0f / w;
    out.x = (vm[0][0] * in.x + vm[0][1] * in.y + vm[0][2] * in.z + vm[0][3]) * invW;
    out.y = (vm[1][0] * in.x + vm[1][1] * in.y + vm[1][2] * in.z + vm[1][3]) * invW;

    float sw = (float)*CS2::Offsets::width;
    float sh = (float)*CS2::Offsets::height;

    out.x = (sw / 2.0f) + (out.x * sw) / 2.0f;
    out.y = (sh / 2.0f) - (out.y * sh) / 2.0f;

    return true;
}

void WeaponESP::update(bool menuOpen) {
    if (!enabled) return;
    
    auto& entSys = CS2::Interfaces::GGameResourceService->m_pGameEntitySystem;

    for (int i = 0; i < 0xFFFF; i++) {
        auto* baseEnt = entSys->Get(i);
        if (!baseEnt) continue;
        auto* gameSceneNode = baseEnt->m_pGameSceneNode();
        if (!gameSceneNode) continue;
        auto* owner = gameSceneNode->m_pOwner();
        if (!owner) continue;
        auto* identity = owner->m_pEntity();
        if (!identity) continue;
        const char* designerName = identity->GetDesignerName();
        if (!designerName) continue;

        // TODO: Lookup instead of string compare + clone

        bool valid = false;
        bool skipOwned = true;
        bool isSmokeGrenade = false;

        std::string designerNameStr = designerName;

		// if it starts with "weapon_"
		if (designerNameStr.compare(0, 7, "weapon_") == 0) {
			designerNameStr.erase(0, 7);
			valid = true;
        }

        const std::string suffix = "projectile";

        if (designerNameStr.size() > suffix.size() &&
            designerNameStr.compare(designerNameStr.size() - suffix.size(), suffix.size(), suffix) == 0) {
            designerNameStr.erase(designerNameStr.size() - (suffix.size() + 1));
            valid = true;
			skipOwned = false;
			
			// Check if it's a smoke grenade
			if (designerNameStr == "smokegrenade") {
				isSmokeGrenade = true;
			}
        }

		if (!valid) continue;

		auto& displayName = designerNameStr;

		for (auto& c : displayName)
            c = std::toupper(c);

		CS2::C_CSWeaponBaseGun* weapon = reinterpret_cast<CS2::C_CSWeaponBaseGun*>(baseEnt);
        auto whOwner = weapon->m_hOwnerEntity();
        if (skipOwned && whOwner.IsValid()) {
            continue;
        }

        auto& pos = gameSceneNode->m_vecAbsOrigin();
		auto localPlayer = *reinterpret_cast<CS2::CCSPlayerController**>(CS2::Offsets::dwLocalPlayerController);
		if (!localPlayer) continue;
		auto& localPlayerPos = localPlayer->m_hPawn().Get()->m_pGameSceneNode()->m_vecAbsOrigin();
		float dist = pos.DistanceTo(localPlayerPos);

        ImVec2 screenPos;
        if (!W2S(screenPos, pos)) continue;

		// For smoke grenades, add timer display
		std::string finalDisplayText = displayName;
		if (isSmokeGrenade) {
			CS2::C_SmokeGrenadeProjectile* smokeGrenade = reinterpret_cast<CS2::C_SmokeGrenadeProjectile*>(baseEnt);
			int32_t smokeEffectTickBegin = smokeGrenade->m_nSmokeEffectTickBegin();
			bool didSmokeEffect = smokeGrenade->m_bDidSmokeEffect();
			
			if (didSmokeEffect && smokeEffectTickBegin > 0) {
				auto* localPawn = localPlayer->m_hPawn().Get();
				if (localPawn) {
					int32_t currentTick = localPawn->m_nSimulationTick();
					int32_t ticksElapsed = currentTick - smokeEffectTickBegin;
					
					// Smoke grenades last approximately 18.5 seconds (1152 ticks at 64 tick)
					const float tickRate = 64.0f;
					const float smokeDurationSeconds = 18.5f;
					const int32_t smokeDurationTicks = static_cast<int32_t>(smokeDurationSeconds * tickRate);
					
					float timeElapsed = ticksElapsed / tickRate;
					float timeRemaining = smokeDurationSeconds - timeElapsed;
					
					if (timeRemaining > 0.0f) {
						char timeBuffer[32];
						snprintf(timeBuffer, sizeof(timeBuffer), " (%.1fs)", timeRemaining);
						finalDisplayText += timeBuffer;
					}
				}
			}
		}

		ImVec2 textSize = ImGui::CalcTextSize(finalDisplayText.c_str());
        ImVec2 textPos = ImVec2(screenPos.x - textSize.x / 2, screenPos.y);

		float alpha = 1.0f;
		// Fade out after 1000 units, fully invisible at 3000 units
		if (dist > 1000.0f) {
			alpha = 1.0f - ((dist - 1000.0f) / 2000.0f);
			if (alpha < 0.0f) alpha = 0.0f;
		}
        
        ImGui::GetBackgroundDrawList()->AddRectFilled(
            ImVec2(textPos.x - 2, textPos.y - 2),
            ImVec2(textPos.x + textSize.x + 2, textPos.y + textSize.y + 2),
			IM_COL32(0, 0, 0, (int)(150 * alpha))
        );
        ImGui::GetBackgroundDrawList()->AddText(
            textPos,
			IM_COL32(255, 255, 255, (int)(255 * alpha)),
			finalDisplayText.c_str()
        );
    }
}

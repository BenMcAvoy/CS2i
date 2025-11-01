#include "PlayerESP.h"
#include <algorithm>

bool PlayerESP::W2S(ImVec2& out, const CS2::Vector3& in) {
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

bool PlayerESP::calcBoxSize(std::span<BoneJointData> boneData, ImVec2& min, ImVec2& max) {
    CS2::Vector3 min3D = { FLT_MAX, FLT_MAX, FLT_MAX };
    CS2::Vector3 max3D = { -FLT_MAX, -FLT_MAX, -FLT_MAX };

    for (auto boneIndex : boneIndices) {
        const auto& pos = boneData[boneIndex].pos;
        if (pos.x < min3D.x) min3D.x = pos.x;
        if (pos.y < min3D.y) min3D.y = pos.y;
        if (pos.z < min3D.z) min3D.z = pos.z;
        if (pos.x > max3D.x) max3D.x = pos.x;
        if (pos.y > max3D.y) max3D.y = pos.y;
        if (pos.z > max3D.z) max3D.z = pos.z;
    }

    const float padding3D = 5.0f;
    min3D.x -= padding3D;
    min3D.y -= padding3D;
    min3D.z -= padding3D;
    max3D.x += padding3D;
    max3D.y += padding3D;
    max3D.z += padding3D;

    const CS2::Vector3 corners[8] = {
        {min3D.x, min3D.y, min3D.z},
        {min3D.x, min3D.y, max3D.z},
        {min3D.x, max3D.y, min3D.z},
        {min3D.x, max3D.y, max3D.z},
        {max3D.x, min3D.y, min3D.z},
        {max3D.x, min3D.y, max3D.z},
        {max3D.x, max3D.y, min3D.z},
        {max3D.x, max3D.y, max3D.z},
    };

    bool visible = true;
    ImVec2 projected;
    min = { FLT_MAX, FLT_MAX };
    max = { -FLT_MAX, -FLT_MAX };

    for (const auto& corner : corners) {
        if (W2S(projected, corner)) {
            if (projected.x < min.x) min.x = projected.x;
            if (projected.y < min.y) min.y = projected.y;
            if (projected.x > max.x) max.x = projected.x;
            if (projected.y > max.y) max.y = projected.y;
        }
        else {
            visible = false;
        }
    }

    return visible;
}

void PlayerESP::drawBox(std::span<BoneJointData> boneData, ImVec2* oMin, ImVec2* oMax, ImColor color) {
    ImVec2 min = ImVec2(FLT_MAX, FLT_MAX);
    ImVec2 max = ImVec2(-FLT_MAX, -FLT_MAX);
    if (!calcBoxSize(boneData, min, max)) return;
    float boxWidth = max.x - min.x;
    float boxHeight = max.y - min.y;

    ImDrawList* drawList = ImGui::GetBackgroundDrawList();
    float cornerLength = 0.2f;
    
    drawList->AddLine(ImVec2(min.x, min.y), ImVec2(min.x + boxWidth * cornerLength, min.y), color, 1.5f);
    drawList->AddLine(ImVec2(min.x, min.y), ImVec2(min.x, min.y + boxHeight * cornerLength), color, 1.5f);
    drawList->AddLine(ImVec2(max.x, min.y), ImVec2(max.x - boxWidth * cornerLength, min.y), color, 1.5f);
    drawList->AddLine(ImVec2(max.x, min.y), ImVec2(max.x, min.y + boxHeight * cornerLength), color, 1.5f);
    drawList->AddLine(ImVec2(min.x, max.y), ImVec2(min.x + boxWidth * cornerLength, max.y), color, 1.5f);
    drawList->AddLine(ImVec2(min.x, max.y), ImVec2(min.x, max.y - boxHeight * cornerLength), color, 1.5f);
    drawList->AddLine(ImVec2(max.x, max.y), ImVec2(max.x - boxWidth * cornerLength, max.y), color, 1.5f);
    drawList->AddLine(ImVec2(max.x, max.y), ImVec2(max.x, max.y - boxHeight * cornerLength), color, 1.5f);

    ImColor boxColor(255, 255, 255, 50);
    drawList->AddRectFilled(ImVec2(min.x, min.y), ImVec2(max.x, max.y), boxColor);

    if (oMin) *oMin = min;
    if (oMax) *oMax = max;
}

void PlayerESP::update(bool menuOpen) {
    static auto& entSys = CS2::Interfaces::GGameResourceService->m_pGameEntitySystem;

    for (int i = 1; i < 64; i++) {
        CS2::C_BaseEntity* baseEnt = entSys->Get(i);
        if (!baseEnt) continue;

        CS2::CEntityIdentity* identity = baseEnt->m_pGameSceneNode()->m_pOwner()->m_pEntity();
        if (!identity) continue;

        constexpr auto expectedName = "cs_player_controller";
        if (std::strcmp(identity->GetDesignerName(), expectedName) != 0)
            continue;

        CS2::CCSPlayerController* con = reinterpret_cast<CS2::CCSPlayerController*>(identity->pInstance);
        if (!con) continue;

        auto& hPawn = con->m_hPlayerPawn();
        if (!hPawn.IsValid()) continue;
        auto* playerPawn = CS2::Interfaces::GGameResourceService->m_pGameEntitySystem->Get<CS2::C_CSPlayerPawn>(hPawn);
        if (!playerPawn) continue;

        auto gsn = con->m_pGameSceneNode();
        auto& pos = playerPawn->m_pGameSceneNode()->m_vecAbsOrigin();

        CS2::C_CSPlayerPawn* localPlayer = *reinterpret_cast<CS2::C_CSPlayerPawn**>(CS2::Offsets::dwLocalPlayerPawn);
        if (playerPawn == localPlayer) continue;

        if (con->m_iTeamNum() == localPlayer->m_iTeamNum()) continue;

        int health = (int)playerPawn->m_iHealth();
        bool isDead = (health <= 0);
        auto deathIt = m_deathStates.find(i);
        
        if (isDead) {
            if (deathIt == m_deathStates.end()) {
                DeathState state;
                state.timestamp = SteadyClock::now();
                state.fadedOut = false;
                m_deathStates[i] = state;
                deathIt = m_deathStates.find(i);
            } else if (deathIt->second.fadedOut) {
                continue;
            }
        } else {
            if (deathIt != m_deathStates.end()) {
                m_deathStates.erase(deathIt);
                deathIt = m_deathStates.end();
            }
        }

        float skeletonAlpha = 1.0f;
        bool drawMoreThanSkele = true;
        
        if (isDead && deathIt != m_deathStates.end() && !deathIt->second.fadedOut) {
            auto now = SteadyClock::now();
            float secondsSinceDeath = std::chrono::duration<float>(now - deathIt->second.timestamp).count();
            
            if (secondsSinceDeath >= SKELETON_FADE_DURATION) {
                deathIt->second.fadedOut = true;
                continue;
            }
            
            skeletonAlpha = 1.0f - (secondsSinceDeath / SKELETON_FADE_DURATION);
            drawMoreThanSkele = false;
        }

        CS2::CGameSceneNode* pNode = playerPawn->m_pGameSceneNode();
        if (!pNode) continue;

        uintptr_t nodeAddr = reinterpret_cast<uintptr_t>(pNode);
        uintptr_t boneArrayPtrAddr = nodeAddr + 0x190 + 0x80;
        BoneJointData* pBoneArray = nullptr;
        
        pBoneArray = *reinterpret_cast<BoneJointData**>(boneArrayPtrAddr);
        if (!pBoneArray)
            continue;

        ImVec2 bonePositions[28];
        for (int idx = 0; idx < 28; idx++) {
            bonePositions[idx] = ImVec2(-10.0f, 0.0f);
        }

        auto& bonePairs = CS2::bones;

        for (int boneIndex : boneIndices) {
            if (!W2S(bonePositions[boneIndex], pBoneArray[boneIndex].pos)) {
                bonePositions[boneIndex] = ImVec2(-10.0f, -10.0f);
            }
        }

        for (const auto& [start, end] : bonePairs) {
            if (bonePositions[start].x >= 0 && bonePositions[end].x >= 0) {
                uint8_t alpha = static_cast<uint8_t>(255 * skeletonAlpha);
                ImGui::GetBackgroundDrawList()->AddLine(
                    bonePositions[start],
                    bonePositions[end],
                    IM_COL32(255, 255, 255, alpha), 2.0f
                );
            }
        }

        if (!drawMoreThanSkele)
            continue;

        ImVec2 min, max;
        drawBox(std::span<BoneJointData>(pBoneArray, 28), &min, &max);

        if (bonePositions[6].x >= 0) {
            float headRadius = (max.y - min.y) * 0.08f;
            ImGui::GetBackgroundDrawList()->AddCircle(
                bonePositions[CS2::HEAD],
                headRadius,
                IM_COL32(255, 255, 255, 255),
                0, 2.0f
            );
        }

        float healthPerc = (float)playerPawn->m_iHealth() / (float)playerPawn->m_iMaxHealth();
        float barWidth = 3.0f;
        float barOffset = 6.0f;
        
        float healthHeight = (max.y - min.y) * healthPerc;
        ImColor healthColor;
        if (healthPerc > 0.75f) {
            healthColor = ImColor(50, 255, 50, 255);
        } else if (healthPerc > 0.5f) {
            healthColor = ImColor(255, 255, 100, 255);
        } else if (healthPerc > 0.25f) {
            healthColor = ImColor(255, 150, 0, 255);
        } else {
            healthColor = ImColor(255, 50, 50, 255);
        }

        ImGui::GetBackgroundDrawList()->AddRectFilled(
            ImVec2(min.x, max.y + barOffset),
            ImVec2(max.x - 4, max.y + barOffset + barWidth),
            IM_COL32(0, 0, 0, 200)
        );
        ImGui::GetBackgroundDrawList()->AddRectFilled(
            ImVec2(min.x, max.y + barOffset),
            ImVec2(min.x - 4 + (max.x - min.x) * healthPerc, max.y + barOffset + barWidth),
            healthColor
        );

        bool hasArmor = playerPawn->m_ArmorValue() > 0;
        ImGui::GetBackgroundDrawList()->AddRectFilled(
            ImVec2(max.x - 2, max.y + barOffset),
            ImVec2(max.x + 2, max.y + barOffset + barWidth),
            hasArmor ? IM_COL32(50, 150, 255, 255) : IM_COL32(0, 0, 0, 200)
        );

        const char* name = con->m_sSanitizedPlayerName();
        ImVec2 nameSize = ImGui::CalcTextSize(name);
        ImGui::GetBackgroundDrawList()->AddText(
            ImVec2(min.x + ((max.x - min.x) / 2) - (nameSize.x / 2), min.y - nameSize.y - 4),
            IM_COL32(255, 255, 255, 255),
            name
        );
    }
}

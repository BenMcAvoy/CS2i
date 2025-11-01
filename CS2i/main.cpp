#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <algorithm>
#include <format>
#include <chrono>
#include <unordered_map>
#include <bitset>

#include "sdk.h"
#include "sdk-gen.h"

#include <minhook.h>

// Death tracking
using SteadyClock = std::chrono::steady_clock;
using TimePoint = SteadyClock::time_point;
struct DeathState {
	TimePoint timestamp;
	bool fadedOut = false;
};
std::unordered_map<int, DeathState> g_deathStates; // entity index -> death state
constexpr float SKELETON_FADE_DURATION = 2.0f;

bool W2S(ImVec2& out, const CS2::Vector3& in) {
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

struct BoneJointData {
	CS2::Vector3 pos;
	float scale;
	char pad[16];
};

constexpr auto boneIndices = {
	CS2::PELVIS, CS2::NECK, CS2::HEAD, CS2::LEFT_SHOULDER, CS2::LEFT_ELBOW, CS2::LEFT_HAND,
	CS2::RIGHT_SHOULDER, CS2::RIGHT_ELBOW, CS2::RIGHT_HAND, CS2::LEFT_LEG, CS2::LEFT_KNEE, CS2::LEFT_FOOT,
	CS2::RIGHT_LEG, CS2::RIGHT_KNEE, CS2::RIGHT_FOOT
};

bool calcBoxSize(std::span<BoneJointData> boneData, ImVec2& min, ImVec2& max) {
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

void drawBox(std::span<BoneJointData> boneData, ImVec2* oMin = nullptr, ImVec2* oMax = nullptr, ImColor color = ImColor(255, 255, 255, 255)) {
	ImVec2 min = ImVec2(FLT_MAX, FLT_MAX);
	ImVec2 max = ImVec2(-FLT_MAX, -FLT_MAX);
	if (!calcBoxSize(boneData, min, max)) return;
	float boxWidth = max.x - min.x;
	float boxHeight = max.y - min.y;

	ImDrawList* drawList = ImGui::GetBackgroundDrawList();
	float cornerLength = 0.2f;
	
	// Top-left
	drawList->AddLine(ImVec2(min.x, min.y), ImVec2(min.x + boxWidth * cornerLength, min.y), color, 1.5f);
	drawList->AddLine(ImVec2(min.x, min.y), ImVec2(min.x, min.y + boxHeight * cornerLength), color, 1.5f);
	// Top-right
	drawList->AddLine(ImVec2(max.x, min.y), ImVec2(max.x - boxWidth * cornerLength, min.y), color, 1.5f);
	drawList->AddLine(ImVec2(max.x, min.y), ImVec2(max.x, min.y + boxHeight * cornerLength), color, 1.5f);
	// Bottom-left
	drawList->AddLine(ImVec2(min.x, max.y), ImVec2(min.x + boxWidth * cornerLength, max.y), color, 1.5f);
	drawList->AddLine(ImVec2(min.x, max.y), ImVec2(min.x, max.y - boxHeight * cornerLength), color, 1.5f);
	// Bottom-right
	drawList->AddLine(ImVec2(max.x, max.y), ImVec2(max.x - boxWidth * cornerLength, max.y), color, 1.5f);
	drawList->AddLine(ImVec2(max.x, max.y), ImVec2(max.x, max.y - boxHeight * cornerLength), color, 1.5f);

	ImColor boxColor(255, 255, 255, 50);
	drawList->AddRectFilled(ImVec2(min.x, min.y), ImVec2(max.x, max.y), boxColor);

	if (oMin) *oMin = min;
	if (oMax) *oMax = max;
}

DWORD WINAPI MainThread(LPVOID lpParam) {
	CS2::initPtrs();
	CS2::Interfaces::setupInterfaces();

#if 0
	CS2::Pattern patCreateMove("48 89 05 ? ? ? ? 0F 57 C0 0F 11 05");
	auto pCSGOInput = reinterpret_cast<CS2::CSGOInput*>(patCreateMove.scanNow("client.dll").getRIP().getAddress());
	void* pCreateMove = pCSGOInput->getCreateMovePtr();
#endif

	CS2::Pattern patRenderBatchList("4C 8B DC 53 48 81 EC ? ? ? ? 83 79");
	auto pRenderBatchList = patRenderBatchList.scanNow("scenesystem.dll").getAddress();

	MH_Initialize();
	//MH_CreateHook(pCreateMove, &hkCreateMove, reinterpret_cast<void**>(&originalCreateMove));
	//MH_EnableHook(pCreateMove);

	static bool* outerTakesFocus = nullptr;
	
	// UI State
	static char scopeSearchBuf[256] = "";
	static char classSearchBuf[256] = "";
	static char fieldSearchBuf[256] = "";
	static int currentTab = 0;
	static int requestedTab = -1; 
	static char offsetTestModule[128] = "client.dll";
	static char offsetTestClass[128] = "C_BaseEntity";
	static char offsetTestField[128] = "m_iHealth";
	static std::string navigateToClass = ""; 
	static std::string navigateToField = ""; 
	static int navigationFrameDelay = 0; 
	static char fieldNameSearchBuf[256] = "";
	static char fieldTypeSearchBuf[256] = "";
	
	// ESP Settings
	static bool enableEntityESP = false;
	
	// World Tint Settings
	static bool enableWorldTint = false;
	static float tintColor[3] = { 1.0f, 0.5f, 1.0f }; // Purple by default (R, G, B)
	static char fieldScopeSearchBuf[256] = "";
	static char fieldClassSearchBuf[256] = "";

	auto& presentManager = CS2::PresentManager_t::get();
	presentManager.setOnPresentCallback([](bool& takesFocus, IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags) {
		outerTakesFocus = &takesFocus;

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

			// Track death times
			int health = (int)playerPawn->m_iHealth();
			bool isDead = (health <= 0);
			auto deathIt = g_deathStates.find(i);
			
			if (isDead) {
				// If not already tracked or if they respawned and died again
				if (deathIt == g_deathStates.end()) {
					DeathState state;
					state.timestamp = SteadyClock::now();
					state.fadedOut = false;
					g_deathStates[i] = state;
					deathIt = g_deathStates.find(i);
				} else if (deathIt->second.fadedOut) {
					// Already faded out, skip rendering
					continue;
				}
			} else {
				// Alive - clear any death record (respawned)
				if (deathIt != g_deathStates.end()) {
					g_deathStates.erase(deathIt);
					deathIt = g_deathStates.end();
				}
			}

			// Calculate fade alpha for dead players
			float skeletonAlpha = 1.0f;
			bool drawMoreThanSkele = true;
			
			if (isDead && deathIt != g_deathStates.end() && !deathIt->second.fadedOut) {
				auto now = SteadyClock::now();
				float secondsSinceDeath = std::chrono::duration<float>(now - deathIt->second.timestamp).count();
				
				// Fade out over SKELETON_FADE_DURATION seconds
				if (secondsSinceDeath >= SKELETON_FADE_DURATION) {
					// Completely faded - mark as faded out and skip rendering
					deathIt->second.fadedOut = true;
					continue;
				}
				
				// Linear fade: 1.0 -> 0.0 over fade duration
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
					// Apply fade alpha to skeleton lines
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
				healthColor = ImColor(50, 255, 50, 255); // White for high health
			} else if (healthPerc > 0.5f) {
				healthColor = ImColor(255, 255, 100, 255); // Yellow for medium
			} else if (healthPerc > 0.25f) {
				healthColor = ImColor(255, 150, 0, 255); // Orange for low
			} else {
				healthColor = ImColor(255, 50, 50, 255); // Red for critical
			}

			// Draw healthbar along bottom side of the box (horizontal)
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

			// If armour, draw blue square, else draw black square (with the extra 4px we created)
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


			/*auto ID = localPlayer->m_hController().ID();
			uint64_t mSpotted;
			memcpy(&mSpotted, playerPawn->m_entitySpottedState().m_bSpottedByMask(), sizeof(uint64_t));
			bool spotted = (mSpotted & (1ULL << ID)) != 0;*/
		}

		if (enableEntityESP) {
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
				auto& pos = gameSceneNode->m_vecAbsOrigin();

				ImVec2 screenPos;
				if (!W2S(screenPos, pos)) continue;

				ImVec2 textSize = ImGui::CalcTextSize(designerName);
				ImVec2 textPos = ImVec2(screenPos.x - textSize.x / 2, screenPos.y);
				
				ImGui::GetBackgroundDrawList()->AddRectFilled(
					ImVec2(textPos.x - 2, textPos.y - 2),
					ImVec2(textPos.x + textSize.x + 2, textPos.y + textSize.y + 2),
					IM_COL32(0, 0, 0, 150)
				);
				ImGui::GetBackgroundDrawList()->AddText(
					textPos,
					IM_COL32(200, 200, 255, 255),
					designerName
				);
			}
		}

		if (takesFocus) {
			ImGui::SetNextWindowSize(ImVec2(800, 600), ImGuiCond_FirstUseEver);
			ImGui::Begin("CS2 Schema Explorer", nullptr, ImGuiWindowFlags_MenuBar);

			if (ImGui::BeginMenuBar()) {
				if (ImGui::BeginMenu("View")) {
					if (ImGui::MenuItem("Entity Debug")) requestedTab = 0;
					if (ImGui::MenuItem("Type Browser")) requestedTab = 1;
					if (ImGui::MenuItem("Field Search")) requestedTab = 2;
					ImGui::EndMenu();
				}
				ImGui::EndMenuBar();
			}

			if (ImGui::BeginTabBar("MainTabs")) {
				ImGuiTabItemFlags entityFlags = (requestedTab == 0) ? ImGuiTabItemFlags_SetSelected : ImGuiTabItemFlags_None;
				if (requestedTab == 0) requestedTab = -1;
				
				if (ImGui::BeginTabItem("Entity Debug", nullptr, entityFlags)) {
					auto& eSys = CS2::Interfaces::GGameResourceService->m_pGameEntitySystem;

					ImGui::Spacing();
					ImGui::Checkbox("Enable Entity ESP", &enableEntityESP);
					ImGui::SameLine();
					ImGui::TextColored(ImVec4(0.7f, 0.7f, 0.7f, 1.0f), "(Shows entity names in-game)");
					ImGui::Spacing();
					ImGui::Text("Entity List Debug:");
					ImGui::Separator();
					ImGui::Spacing();
					
					ImGui::BeginChild("EntityList", ImVec2(0, 0), false);
					
					if (ImGui::CollapsingHeader("Players")) {
						if (ImGui::BeginTable("EntityTable", 6, ImGuiTableFlags_Resizable | ImGuiTableFlags_RowBg | ImGuiTableFlags_Borders | ImGuiTableFlags_ScrollY | ImGuiTableFlags_SizingFixedFit)) {
							// Table headers
							ImGui::TableSetupColumn("Name");
							ImGui::TableSetupColumn("Index");
							ImGui::TableSetupColumn("Health");
							ImGui::TableSetupColumn("Ping");
							ImGui::TableSetupColumn("Position");
							ImGui::TableSetupColumn("Extras");
							ImGui::TableHeadersRow();

							for (int i = 1; i < 64; i++) {
								auto* entityController = CS2::Interfaces::GGameResourceService->m_pGameEntitySystem->Get<CS2::CCSPlayerController>(i);
								if (!entityController) continue;

								auto& hPawn = entityController->m_hPlayerPawn();
								if (!hPawn.IsValid()) continue;
								auto* playerPawn = CS2::Interfaces::GGameResourceService->m_pGameEntitySystem->Get<CS2::C_CSPlayerPawn>(hPawn);
								if (!playerPawn) continue;

								auto& pos = playerPawn->m_pGameSceneNode()->m_vecAbsOrigin();

								const char* sanitizedName = entityController->m_sSanitizedPlayerName();

								auto test = playerPawn->m_nSimulationTick();
								auto test2 = playerPawn->m_flSimulationTime();

								auto lifetime = entityController->m_iPawnLifetimeEnd();

								ImGui::TableNextRow();
								ImGui::TableNextColumn();
								ImGui::Text("%s", sanitizedName ? sanitizedName : "N/A");
								ImGui::TableNextColumn();
								ImGui::Text("%d", i);
								ImGui::TableNextColumn();
								ImGui::Text("%d", playerPawn->m_iHealth());
								ImGui::TableNextColumn();
								ImGui::Text("%d", entityController->m_iPing());
								ImGui::TableNextColumn();
								ImGui::Text("(%.2f, %.2f, %.2f)", pos.x, pos.y, pos.z);
								ImGui::TableNextColumn();
								ImGui::Text("death time %d.  Test %d %f", lifetime, test, test2);
							}
							ImGui::EndTable();
						}
					}

					if (ImGui::CollapsingHeader("World Tint")) {
						ImGui::Checkbox("Enable World Tint", &enableWorldTint);
						ImGui::ColorEdit3("Tint Color", tintColor);
						
						if (enableWorldTint) {
							auto& eSys = CS2::Interfaces::GGameResourceService->m_pGameEntitySystem;
							if (!eSys) {
								ImGui::TextColored(ImVec4(1.0f, 0.5f, 0.5f, 1.0f), "Error: Entity system not available!");
							} else {
								auto localPlayer = *reinterpret_cast<CS2::C_CSPlayerPawn**>(CS2::Offsets::dwLocalPlayerPawn);
								
								// Convert float colors (0-1) to byte colors (0-255) - MUST BE STATIC!
								static CS2::Color tintCol = CS2::Color(255, 128, 255, 255);
								tintCol = CS2::Color(
									static_cast<uint8_t>(tintColor[0] * 255),
									static_cast<uint8_t>(tintColor[1] * 255),
									static_cast<uint8_t>(tintColor[2] * 255),
									255
								);
								
								// Apply fog tint via camera services
								if (localPlayer && localPlayer->m_pCameraServices()) {
									auto* fogColor = localPlayer->m_pCameraServices()->m_OverrideFogColor();
									auto* fogEnabled = localPlayer->m_pCameraServices()->m_bOverrideFogColor();
									if (fogColor && fogEnabled) {
										*fogColor = tintCol;
										*fogEnabled = true;
									}
								}
								
								// Find and tint sky
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

									// Tint sky
									if (std::strcmp(designerName, "env_sky") == 0) {
										CS2::C_EnvSky* pSky = reinterpret_cast<CS2::C_EnvSky*>(identity->pInstance);

										LOGINFO("Found sky entity at index %d, applying tint", i);

										if (pSky) {
											pSky->m_bEnabled() = true;
											pSky->m_vTintColor() = tintCol;
											pSky->m_vTintColorLightingOnly() = tintCol;
										}
									} else
									if (std::strcmp(designerName, "env_combined_light_probe_volume") == 0) {
										CS2::C_EnvCombinedLightProbeVolume* pProbe = reinterpret_cast<CS2::C_EnvCombinedLightProbeVolume*>(baseEnt);
										LOGINFO("Found light probe entity at index %d, applying tint", i);
										if (pProbe) {
											pProbe->m_Entity_Color() = tintCol;
										}
									} else
									if (std::strcmp(designerName, "light_barn") == 0) {
										CS2::C_BarnLight* pBarnLight = reinterpret_cast<CS2::C_BarnLight*>(baseEnt);
										pBarnLight->m_Color() = tintCol;
									} else
									if (std::strcmp(designerName, "light_rect") == 0) {
										CS2::C_RectLight* pRectLight = reinterpret_cast<CS2::C_RectLight*>(baseEnt);
										LOGINFO("Found rect light entity at index %d, applying tint", i);
										pRectLight->m_Color() = tintCol;
									} 
								}
							
							ImGui::TextColored(ImVec4(0.5f, 1.0f, 0.5f, 1.0f), "World tint active!");
							ImGui::Text("Note: Restart map or toggle off/on to see changes");
							}
						} else {
							// Reset when disabled
							auto localPlayer = *reinterpret_cast<CS2::C_CSPlayerPawn**>(CS2::Offsets::dwLocalPlayerPawn);
							if (localPlayer && localPlayer->m_pCameraServices()) {
								auto* fogEnabled = localPlayer->m_pCameraServices()->m_bOverrideFogColor();
								if (fogEnabled) {
									*fogEnabled = false;
								}
							}
						}
					}

					if (ImGui::CollapsingHeader("All Entities", ImGuiTreeNodeFlags_DefaultOpen)) {
						static char entitySearchBuf[256] = "";
						
						ImGui::SetNextItemWidth(400);
						ImGui::InputTextWithHint("##EntitySearch", "Search entities by name...", entitySearchBuf, sizeof(entitySearchBuf));
						
						ImGui::Spacing();
						
						std::string entitySearch = entitySearchBuf;
						std::transform(entitySearch.begin(), entitySearch.end(), entitySearch.begin(), ::tolower);
						
						auto& eSys = CS2::Interfaces::GGameResourceService->m_pGameEntitySystem;
						
						struct EntityInfo {
							int index;
							const char* name;
							CS2::Vector3 pos;
							bool hasValidData;
							uintptr_t baseEntPtr;
						};
						std::vector<EntityInfo> entities;
						
						int validCount = 0;
						int totalSlots = 0;
						
						for (int i = 0; i < 0xFFFF; i++) {
							auto* baseEnt = eSys->Get(i);
							
							if (!baseEnt) continue;
							
							totalSlots++;
							
							EntityInfo info{};
							info.index = i;
							info.name = nullptr;
							info.pos = CS2::Vector3{0, 0, 0};
							info.hasValidData = false;
							info.baseEntPtr = reinterpret_cast<uintptr_t>(baseEnt);
							
							auto* gameSceneNode = baseEnt->m_pGameSceneNode();
							if (gameSceneNode && gameSceneNode->m_pOwner()) {
								auto* identity = gameSceneNode->m_pOwner()->m_pEntity();
								if (identity) {
									const char* designerName = identity->GetDesignerName();
									if (designerName) {
										info.name = designerName;
										info.hasValidData = true;
										info.pos = gameSceneNode->m_vecAbsOrigin();
										validCount++;
									}
								}
							}
							
							if (!entitySearch.empty()) {
								std::string nameLower = info.name ? info.name : "";
								std::transform(nameLower.begin(), nameLower.end(), nameLower.begin(), ::tolower);
								if (nameLower.find(entitySearch) == std::string::npos) continue;
							}
							
							entities.push_back(info);
						}
						
						ImGui::TextColored(ImVec4(0.7f, 0.9f, 1.0f, 1.0f), "Found %d entities with data / %d occupied slots", validCount, totalSlots);
						ImGui::TextColored(ImVec4(0.9f, 0.7f, 0.5f, 1.0f), "Note: Many entities may not have GetDesignerName() - they still exist but show as 'N/A'");
						ImGui::Separator();
						ImGui::Spacing();

						if (ImGui::BeginTable("AllEntitiesTable", 5, ImGuiTableFlags_Resizable | ImGuiTableFlags_RowBg | ImGuiTableFlags_Borders | ImGuiTableFlags_ScrollY | ImGuiTableFlags_SizingFixedFit | ImGuiTableFlags_Sortable)) {
							ImGui::TableSetupColumn("Index", ImGuiTableColumnFlags_DefaultSort | ImGuiTableColumnFlags_WidthFixed, 60.0f);
							ImGui::TableSetupColumn("Entity Type", ImGuiTableColumnFlags_WidthStretch);
							ImGui::TableSetupColumn("Position", ImGuiTableColumnFlags_WidthFixed, 200.0f);
							ImGui::TableSetupColumn("Pointer", ImGuiTableColumnFlags_WidthFixed, 120.0f);
							ImGui::TableSetupColumn("Valid", ImGuiTableColumnFlags_WidthFixed, 50.0f);
							ImGui::TableHeadersRow();
							
							if (ImGuiTableSortSpecs* sortSpecs = ImGui::TableGetSortSpecs()) {
								if (sortSpecs->SpecsDirty) {
									if (sortSpecs->SpecsCount > 0) {
										const ImGuiTableColumnSortSpecs& spec = sortSpecs->Specs[0];
										
										std::sort(entities.begin(), entities.end(), [&](const EntityInfo& a, const EntityInfo& b) {
											int result = 0;
											switch (spec.ColumnIndex) {
												case 0: // Index
													result = a.index - b.index;
													break;
												case 1: // Entity Type
													result = strcmp(a.name ? a.name : "", b.name ? b.name : "");
													break;
												case 4: // Valid
													result = (int)a.hasValidData - (int)b.hasValidData;
													break;
											}
											return spec.SortDirection == ImGuiSortDirection_Ascending ? (result < 0) : (result > 0);
										});
									}
									sortSpecs->SpecsDirty = false;
								}
							}
							
							for (const auto& entity : entities) {
								ImGui::TableNextRow();
								
								ImGui::TableNextColumn();
								ImGui::Text("%d", entity.index);
								
								ImGui::TableNextColumn();
								if (entity.name) {
									ImGui::TextColored(ImVec4(0.7f, 0.9f, 0.7f, 1.0f), "%s", entity.name);
								} else {
									ImGui::TextColored(ImVec4(0.7f, 0.7f, 0.7f, 1.0f), "N/A");
								}
								
								if (ImGui::BeginPopupContextItem()) {
									if (entity.name && ImGui::MenuItem("Copy Entity Type")) {
										ImGui::SetClipboardText(entity.name);
									}
									if (ImGui::MenuItem("Copy Index")) {
										char indexStr[32];
										sprintf_s(indexStr, "%d", entity.index);
										ImGui::SetClipboardText(indexStr);
									}
									if (ImGui::MenuItem("Copy Pointer")) {
										char ptrStr[32];
										sprintf_s(ptrStr, "0x%llX", entity.baseEntPtr);
										ImGui::SetClipboardText(ptrStr);
									}
									ImGui::EndPopup();
								}
								
								ImGui::TableNextColumn();
								if (entity.hasValidData) {
									ImGui::Text("(%.1f, %.1f, %.1f)", entity.pos.x, entity.pos.y, entity.pos.z);
								} else {
									ImGui::TextDisabled("N/A");
								}
								
								ImGui::TableNextColumn();
								ImGui::TextColored(ImVec4(0.6f, 0.6f, 0.8f, 1.0f), "0x%llX", entity.baseEntPtr);
								
								ImGui::TableNextColumn();
								if (entity.hasValidData) {
									ImGui::TextColored(ImVec4(0.5f, 1.0f, 0.5f, 1.0f), "Yes");
								} else {
									ImGui::TextColored(ImVec4(1.0f, 0.5f, 0.5f, 1.0f), "No");
								}
							}
							
							ImGui::EndTable();
						}
					}

					ImGui::EndChild();
					ImGui::EndTabItem();
				}
				
				// Type Browser Tab
				ImGuiTabItemFlags browserFlags = (requestedTab == 1) ? ImGuiTabItemFlags_SetSelected : ImGuiTabItemFlags_None;
				if (requestedTab == 1) requestedTab = -1;
				
				if (ImGui::BeginTabItem("Type Browser", nullptr, browserFlags)) {
					ImGui::Spacing();
					
					// Search bars
					ImGui::Text("Filters:");
					ImGui::SetNextItemWidth(250);
					ImGui::InputTextWithHint("##ScopeSearch", "Search scopes...", scopeSearchBuf, sizeof(scopeSearchBuf));
					ImGui::SameLine();
					ImGui::SetNextItemWidth(250);
					ImGui::InputTextWithHint("##ClassSearch", "Search classes...", classSearchBuf, sizeof(classSearchBuf));
					ImGui::SameLine();
					ImGui::SetNextItemWidth(250);
					ImGui::InputTextWithHint("##FieldSearch", "Search fields...", fieldSearchBuf, sizeof(fieldSearchBuf));
					
					ImGui::Separator();
					ImGui::Spacing();

					// Convert search terms to lowercase for case-insensitive search
					std::string scopeSearch = scopeSearchBuf;
					std::string classSearch = classSearchBuf;
					std::string fieldSearch = fieldSearchBuf;
					std::transform(scopeSearch.begin(), scopeSearch.end(), scopeSearch.begin(), ::tolower);
					std::transform(classSearch.begin(), classSearch.end(), classSearch.begin(), ::tolower);
					std::transform(fieldSearch.begin(), fieldSearch.end(), fieldSearch.begin(), ::tolower);

					// Type scope tree
					ImGui::BeginChild("TypeTree", ImVec2(0, 0), false);
					auto schema = CS2::Interfaces::GSchemaSystem;
					int visibleScopes = 0;
					
					if (navigationFrameDelay > 0) {
						navigationFrameDelay--;
					}
					
					for (auto& typeScope : schema->typeScopes.ToSpan()) {
						std::string scopeName = typeScope->name;
						std::string scopeNameLower = scopeName;
						std::transform(scopeNameLower.begin(), scopeNameLower.end(), scopeNameLower.begin(), ::tolower);
						
						if (!scopeSearch.empty() && scopeNameLower.find(scopeSearch) == std::string::npos) {
							continue;
						}
						
						visibleScopes++;
						char scopeLabel[512];
						int classCount = 0;
						
						for (const auto& classInfo : typeScope->declaredClasses) {
							std::string className = classInfo.name;
							std::string classNameLower = className;
							std::transform(classNameLower.begin(), classNameLower.end(), classNameLower.begin(), ::tolower);
							if (classSearch.empty() || classNameLower.find(classSearch) != std::string::npos) {
								classCount++;
							}
						}
						
						sprintf_s(scopeLabel, "%s (%d classes)", typeScope->name, classCount);
						
						bool shouldExpandScope = false;
						if (!navigateToClass.empty() && navigationFrameDelay == 0) {
							for (const auto& classInfo : typeScope->declaredClasses) {
								if (classInfo.name == navigateToClass) {
									shouldExpandScope = true;
									break;
								}
							}
						}
						
						ImGuiTreeNodeFlags scopeFlags = ImGuiTreeNodeFlags_None;
						if (shouldExpandScope) {
							scopeFlags |= ImGuiTreeNodeFlags_DefaultOpen;
							ImGui::SetNextItemOpen(true);
						}
						
						if (ImGui::TreeNodeEx(typeScope->name, scopeFlags, "%s", scopeLabel)) {
							if (ImGui::BeginPopupContextItem()) {
								if (ImGui::MenuItem("Copy Scope Name")) {
									ImGui::SetClipboardText(typeScope->name);
								}
							ImGui::Separator();
							if (ImGui::MenuItem("Generate SDK for Scope")) {
								std::string sdkOutput;
								
								std::vector<std::string> declaredClasses;
								for (const auto& classInfo : typeScope->declaredClasses) {
									std::string className = classInfo.name;
									if (className.find("::") == std::string::npos) {
										declaredClasses.push_back(className);
									}
								}
								
							std::vector<std::string> referencedTypes;
							for (const auto& classInfo : typeScope->declaredClasses) {
								std::string className = classInfo.name;
								if (className.find("::") != std::string::npos) {
									continue;
								}
								
								auto bc = classInfo.baseClasses;
								if (bc && bc->info && bc->info->name) {
									std::string baseClassName = bc->info->name;
									if (std::find(declaredClasses.begin(), declaredClasses.end(), baseClassName) == declaredClasses.end() &&
										std::find(referencedTypes.begin(), referencedTypes.end(), baseClassName) == referencedTypes.end()) {
										referencedTypes.push_back(baseClassName);
									}
								}
								
								if (classInfo.fieldsCount > 0) {
										for (const auto& field : classInfo.fieldsSpan()) {
											std::string typeName = field.schemaType->typeName;
											
											std::string cleanTypeName = typeName;
											size_t ptrPos = cleanTypeName.find('*');
											if (ptrPos != std::string::npos) {
												cleanTypeName = cleanTypeName.substr(0, ptrPos);
											}
											size_t refPos = cleanTypeName.find('&');
											if (refPos != std::string::npos) {
												cleanTypeName = cleanTypeName.substr(0, refPos);
											}
											size_t templatePos = cleanTypeName.find('<');
											if (templatePos != std::string::npos) {
												cleanTypeName = cleanTypeName.substr(0, templatePos);
											}
											
											cleanTypeName.erase(0, cleanTypeName.find_first_not_of(" \t"));
											cleanTypeName.erase(cleanTypeName.find_last_not_of(" \t") + 1);
											
											if (!cleanTypeName.empty() && 
												cleanTypeName != "void" &&
												cleanTypeName != "bool" &&
												cleanTypeName != "char" &&
												cleanTypeName != "int" &&
												cleanTypeName != "int8" &&
												cleanTypeName != "int16" &&
												cleanTypeName != "int32" &&
												cleanTypeName != "int64" &&
												cleanTypeName != "uint8" &&
												cleanTypeName != "uint16" &&
												cleanTypeName != "uint32" &&
												cleanTypeName != "uint64" &&
												cleanTypeName != "float" &&
												cleanTypeName != "double" &&
												std::find(declaredClasses.begin(), declaredClasses.end(), cleanTypeName) == declaredClasses.end() &&
												std::find(referencedTypes.begin(), referencedTypes.end(), cleanTypeName) == referencedTypes.end()) {
												referencedTypes.push_back(cleanTypeName);
											}
										}
									}
								}
								
								sdkOutput += "// Forward declarations\n";
								for (const auto& className : declaredClasses) {
									sdkOutput += std::format("class {};\n", className);
								}
								
								if (!referencedTypes.empty()) {
									sdkOutput += "\n// Referenced types (not in this scope)\n";
									for (const auto& typeName : referencedTypes) {
										sdkOutput += std::format("class {};\n", typeName);
									}
								}
								sdkOutput += "\n";
								for (const auto& classInfo : typeScope->declaredClasses) {
									std::string className = classInfo.name;
									
									if (className.find("::") != std::string::npos) {
										continue;
									}
									
									if (classInfo.fieldsCount == 0) {
										continue;
									}
									
									sdkOutput += std::format("// Class: {} (Size: 0x{:X})\n", className, classInfo.size);
									
									auto bc = classInfo.baseClasses;
									if (bc && bc->info && bc->info->name) {
										sdkOutput += std::format("class {} : public {} {{\n", className, bc->info->name);
									} else {
										sdkOutput += std::format("class {} {{\n", className);
									}
									
									sdkOutput += "public:\n";
									
									for (const auto& field : classInfo.fieldsSpan()) {
										sdkOutput += std::format("\tSCHEMA({}, {}, \"{}\", \"{}\", \"{}\");\n",
											field.schemaType->typeName,
											field.fieldName,
											field.fieldName,
											className,
											typeScope->name);
									}
									
									sdkOutput += "};\n\n";
								}
									
									ImGui::SetClipboardText(sdkOutput.c_str());
								}
								ImGui::EndPopup();
							}
							
							for (const auto& classInfo : typeScope->declaredClasses) {
								std::string className = classInfo.name;
								std::string classNameLower = className;
								std::transform(classNameLower.begin(), classNameLower.end(), classNameLower.begin(), ::tolower);
								
								if (!classSearch.empty() && classNameLower.find(classSearch) == std::string::npos) {
									continue;
								}
								
								std::string baseClasses;
								auto bc = classInfo.baseClasses;
								bool hasBaseClass = (bc && bc->info && bc->info->name);
								if (hasBaseClass) {
									baseClasses = bc->info->name;
								}

								ImGuiTreeNodeFlags flags = ImGuiTreeNodeFlags_None;
								
								bool isNavigationTarget = (!navigateToClass.empty() && classInfo.name == navigateToClass && navigationFrameDelay == 0);
								if (isNavigationTarget) {
									flags |= ImGuiTreeNodeFlags_DefaultOpen;
									ImGui::SetNextItemOpen(true);
								}
								
							bool nodeOpen = ImGui::TreeNodeEx(classInfo.name, flags, "%s", classInfo.name);
							
							std::string classContextMenuID = std::format("ClassContextMenu_{}", classInfo.name);
							if (ImGui::BeginPopupContextItem(classContextMenuID.c_str())) {
								if (ImGui::MenuItem("Copy Class Name")) {
									ImGui::SetClipboardText(classInfo.name);
								}
								if (ImGui::MenuItem("Copy Module Name")) {
									ImGui::SetClipboardText(classInfo.moduleName);
								}
								if (ImGui::MenuItem("Copy Size")) {
									char sizeStr[32];
									sprintf_s(sizeStr, "0x%X", classInfo.size);
									ImGui::SetClipboardText(sizeStr);
								}
								if (hasBaseClass && ImGui::MenuItem("Copy Base Class Name")) {
									ImGui::SetClipboardText(baseClasses.c_str());
								}
								ImGui::Separator();
								if (ImGui::MenuItem("Copy All as SCHEMA")) {
									std::string allSchemas;
									if (classInfo.fieldsCount > 0) {
										for (const auto& field : classInfo.fieldsSpan()) {
											std::string schemaLine = std::format("SCHEMA({}, {}, \"{}\", \"{}\", \"{}\");\n",
												field.schemaType->typeName,
												field.fieldName,
												field.fieldName,
												classInfo.name,
												typeScope->name);
											allSchemas += schemaLine;
										}
									}
									ImGui::SetClipboardText(allSchemas.c_str());
								}
								ImGui::EndPopup();
							}
							
							if (isNavigationTarget) {
								ImGui::SetScrollHereY(0.3f); 
								navigateToClass = ""; 
							}
								if (hasBaseClass) {
									ImGui::SameLine(0, 5);
									ImGui::TextColored(ImVec4(0.6f, 0.6f, 0.6f, 1.0f), ":");
									ImGui::SameLine(0, 5);
									
									ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0, 0, 0, 0));
									ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.7f, 0.6f, 0.8f, 0.3f));
									ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.7f, 0.6f, 0.8f, 0.5f));
									ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(0, 0));
									
									ImVec2 textSize = ImGui::CalcTextSize(baseClasses.c_str());
									
									if (ImGui::Button(std::format("##baseclass_{}", classInfo.name).c_str(), textSize)) {
										navigateToClass = baseClasses;
										navigationFrameDelay = 2;
									}
									
									// Draw colored text over button
									ImVec2 buttonMin = ImGui::GetItemRectMin();
									ImGui::GetWindowDrawList()->AddText(buttonMin, ImGui::GetColorU32(ImVec4(0.7f, 0.6f, 0.8f, 1.0f)), baseClasses.c_str());
									
									// Show tooltip on hover
									if (ImGui::IsItemHovered()) {
										ImGui::BeginTooltip();
										ImGui::Text("Click to navigate to %s", baseClasses.c_str());
										ImGui::EndTooltip();
									}
									
									ImGui::PopStyleVar();
									ImGui::PopStyleColor(3);
								}
								
								// Add colored metadata on the same line
								ImGui::SameLine();
								ImGui::TextColored(ImVec4(0.5f, 0.5f, 0.5f, 1.0f), "(");
								ImGui::SameLine(0, 0);
								ImGui::TextColored(ImVec4(0.8f, 0.7f, 0.5f, 1.0f), "Size: 0x%X", classInfo.size);
								ImGui::SameLine(0, 0);
								ImGui::TextColored(ImVec4(0.5f, 0.5f, 0.5f, 1.0f), ", ");
								ImGui::SameLine(0, 0);
								ImGui::TextColored(ImVec4(0.6f, 0.8f, 0.6f, 1.0f), "Fields: %d", classInfo.fieldsCount);
								ImGui::SameLine(0, 0);
								ImGui::TextColored(ImVec4(0.5f, 0.5f, 0.5f, 1.0f), ")");

							if (nodeOpen) {
								if (classInfo.fieldsCount > 0) {
									for (const auto& field : classInfo.fieldsSpan()) {
											std::string fieldName = field.fieldName;
											std::string fieldNameLower = fieldName;
											std::transform(fieldNameLower.begin(), fieldNameLower.end(), fieldNameLower.begin(), ::tolower);
											
											// Filter fields
											if (!fieldSearch.empty() && fieldNameLower.find(fieldSearch) == std::string::npos) {
												continue;
											}
											
											// Check if this is the navigation target field
											bool isFieldTarget = (!navigateToField.empty() && fieldName == navigateToField && classInfo.name == navigateToClass && navigationFrameDelay == 0);
											
											ImGui::PushID(&field);
											
											// Highlight the target field with a colored background
											if (isFieldTarget) {
												ImVec2 lineStartHighlight = ImGui::GetCursorScreenPos();
												ImVec2 lineSizeHighlight = ImVec2(ImGui::GetWindowContentRegionMax().x - ImGui::GetWindowContentRegionMin().x, ImGui::GetTextLineHeightWithSpacing());
												ImGui::GetWindowDrawList()->AddRectFilled(lineStartHighlight, ImVec2(lineStartHighlight.x + lineSizeHighlight.x, lineStartHighlight.y + lineSizeHighlight.y), ImGui::GetColorU32(ImVec4(0.3f, 0.5f, 0.3f, 0.3f)));
											}
											
											// Store cursor position for invisible button
											ImVec2 lineStart = ImGui::GetCursorScreenPos();
											
											// Color-coded field display (more subtle colors)
											// Offset in light cyan
											ImGui::TextColored(ImVec4(0.5f, 0.7f, 0.7f, 1.0f), "[0x%04X]", field.offset);
											ImGui::SameLine(0, 5);
											
											// Type name in light green
											ImGui::TextColored(ImVec4(0.6f, 0.8f, 0.6f, 1.0f), "%s", field.schemaType->typeName);
											ImGui::SameLine(0, 5);
											
											// Field name in white/default
											ImGui::Text("%s", field.fieldName);
											
											// Scroll to the navigation target field
											if (isFieldTarget) {
												ImGui::SetScrollHereY(0.3f); // Scroll so field is 30% from top
												navigateToField = ""; // Clear field navigation target
											}
											
											// Get line dimensions for hover detection
											ImVec2 lineEnd = ImGui::GetItemRectMax();
											lineEnd.x = ImGui::GetWindowPos().x + ImGui::GetWindowContentRegionMax().x;
											
											// Invisible button covering the entire line for hover and right-click
											ImGui::SetCursorScreenPos(lineStart);
											ImGui::InvisibleButton("##fieldline", ImVec2(lineEnd.x - lineStart.x, lineEnd.y - lineStart.y));
											
											// Tooltip with additional details (works anywhere on the line)
											if (ImGui::IsItemHovered()) {
												ImGui::BeginTooltip();
												ImGui::TextColored(ImVec4(0.7f, 0.9f, 0.7f, 1.0f), "Field: %s", field.fieldName);
												ImGui::Separator();
												ImGui::Text("Type: %s", field.schemaType->typeName);
												ImGui::Text("Offset: 0x%04X (%d bytes)", field.offset, field.offset);
												ImGui::Text("Type Category: %d", static_cast<int>(field.schemaType->typeCategory));
												ImGui::Text("Atomic Category: %d", static_cast<int>(field.schemaType->atomicCategory));
												ImGui::Separator();
												ImGui::TextColored(ImVec4(0.5f, 0.5f, 0.5f, 1.0f), "Right-click for options");
												ImGui::EndTooltip();
											}
											
										// Right-click context menu
										if (ImGui::BeginPopupContextItem()) {
											if (ImGui::MenuItem("Copy Offset")) {
												char offsetStr[32];
												sprintf_s(offsetStr, "0x%X", field.offset);
												ImGui::SetClipboardText(offsetStr);
											}
											if (ImGui::MenuItem("Copy Field Name")) {
												ImGui::SetClipboardText(field.fieldName);
											}
											if (ImGui::MenuItem("Copy Type")) {
												ImGui::SetClipboardText(field.schemaType->typeName);
											}
											ImGui::Separator();
											if (ImGui::MenuItem("Copy as SCHEMA")) {
												std::string schemaDefine = std::format("SCHEMA({}, {}, \"{}\", \"{}\", \"{}\")",
													field.schemaType->typeName,
													field.fieldName,
													field.fieldName,
													classInfo.name,
													typeScope->name);
												ImGui::SetClipboardText(schemaDefine.c_str());
											}
											ImGui::EndPopup();
										}											ImGui::PopID();
										}
									}
									
									ImGui::TreePop();
								}
							}
							ImGui::TreePop();
						}
					}
					
					if (visibleScopes == 0) {
						ImGui::TextColored(ImVec4(1.0f, 1.0f, 0.0f, 1.0f), "No results found matching your filters.");
					}
					
					ImGui::EndChild();
					ImGui::EndTabItem();
				}

				// Field Search Tab
				ImGuiTabItemFlags searchFlags = (requestedTab == 2) ? ImGuiTabItemFlags_SetSelected : ImGuiTabItemFlags_None;
				if (requestedTab == 2) requestedTab = -1;
				
				if (ImGui::BeginTabItem("Field Search", nullptr, searchFlags)) {
					ImGui::Spacing();
					ImGui::Text("Search for fields across all classes:");
					ImGui::Spacing();
					
					// Search inputs - two rows
					ImGui::SetNextItemWidth(350);
					ImGui::InputTextWithHint("##FieldNameSearch", "Search by field name (e.g., m_iHealth)...", fieldNameSearchBuf, sizeof(fieldNameSearchBuf));
					ImGui::SameLine();
					ImGui::SetNextItemWidth(350);
					ImGui::InputTextWithHint("##FieldTypeSearch", "Search by field type (e.g., int32)...", fieldTypeSearchBuf, sizeof(fieldTypeSearchBuf));
					
					ImGui::SetNextItemWidth(350);
					ImGui::InputTextWithHint("##FieldScopeSearch", "Search by scope (e.g., client.dll)...", fieldScopeSearchBuf, sizeof(fieldScopeSearchBuf));
					ImGui::SameLine();
					ImGui::SetNextItemWidth(350);
					ImGui::InputTextWithHint("##FieldClassSearch", "Search by class name (e.g., C_BaseEntity)...", fieldClassSearchBuf, sizeof(fieldClassSearchBuf));
					
					ImGui::Separator();
					ImGui::Spacing();
					
					// Convert search terms to lowercase
					std::string fieldNameSearch = fieldNameSearchBuf;
					std::string fieldTypeSearch = fieldTypeSearchBuf;
					std::string fieldScopeSearch = fieldScopeSearchBuf;
					std::string fieldClassSearch = fieldClassSearchBuf;
					std::transform(fieldNameSearch.begin(), fieldNameSearch.end(), fieldNameSearch.begin(), ::tolower);
					std::transform(fieldTypeSearch.begin(), fieldTypeSearch.end(), fieldTypeSearch.begin(), ::tolower);
					std::transform(fieldScopeSearch.begin(), fieldScopeSearch.end(), fieldScopeSearch.begin(), ::tolower);
					std::transform(fieldClassSearch.begin(), fieldClassSearch.end(), fieldClassSearch.begin(), ::tolower);
					
					// Count active filters
					int activeFilters = 0;
					if (!fieldNameSearch.empty()) activeFilters++;
					if (!fieldTypeSearch.empty()) activeFilters++;
					if (!fieldScopeSearch.empty()) activeFilters++;
					if (!fieldClassSearch.empty()) activeFilters++;
					
					// Show search mode
					if (activeFilters == 0) {
						ImGui::TextColored(ImVec4(0.8f, 0.8f, 0.8f, 1.0f), "Enter search criteria to find fields");
					} else {
						ImGui::TextColored(ImVec4(0.7f, 0.9f, 1.0f, 1.0f), "Active filters: %d", activeFilters);
						ImGui::SameLine();
						ImGui::TextColored(ImVec4(0.6f, 0.6f, 0.6f, 1.0f), "(all filters must match)");
					}
					
					ImGui::Spacing();
					ImGui::Separator();
					ImGui::Spacing();
					
					// Results
					ImGui::BeginChild("FieldSearchResults", ImVec2(0, 0), false);
					
					auto schema = CS2::Interfaces::GSchemaSystem;
					int resultsCount = 0;
					
					// Search through all scopes, classes, and fields
					for (auto& typeScope : schema->typeScopes.ToSpan()) {
						std::string scopeName = typeScope->name;
						std::string scopeNameLower = scopeName;
						std::transform(scopeNameLower.begin(), scopeNameLower.end(), scopeNameLower.begin(), ::tolower);
						
						// Filter by scope
						if (!fieldScopeSearch.empty() && scopeNameLower.find(fieldScopeSearch) == std::string::npos) {
							continue;
						}
						
						for (const auto& classInfo : typeScope->declaredClasses) {
							std::string className = classInfo.name;
							std::string classNameLower = className;
							std::transform(classNameLower.begin(), classNameLower.end(), classNameLower.begin(), ::tolower);
							
							// Filter by class name
							if (!fieldClassSearch.empty() && classNameLower.find(fieldClassSearch) == std::string::npos) {
								continue;
							}
							
							if (classInfo.fieldsCount > 0) {
								for (const auto& field : classInfo.fieldsSpan()) {
									std::string fieldName = field.fieldName;
									std::string fieldType = field.schemaType->typeName;
									std::string fieldNameLower = fieldName;
									std::string fieldTypeLower = fieldType;
									std::transform(fieldNameLower.begin(), fieldNameLower.end(), fieldNameLower.begin(), ::tolower);
									std::transform(fieldTypeLower.begin(), fieldTypeLower.end(), fieldTypeLower.begin(), ::tolower);
									
									// Filter by name and/or type
									bool nameMatches = fieldNameSearch.empty() || fieldNameLower.find(fieldNameSearch) != std::string::npos;
									bool typeMatches = fieldTypeSearch.empty() || fieldTypeLower.find(fieldTypeSearch) != std::string::npos;
									
									if (nameMatches && typeMatches) {
										resultsCount++;
										
										ImGui::PushID(&field);
										
										// Display result with scope, class, and field info
										ImGui::TextColored(ImVec4(0.7f, 0.7f, 0.9f, 1.0f), "%s", typeScope->name);
										ImGui::SameLine(0, 5);
										ImGui::TextColored(ImVec4(0.6f, 0.6f, 0.6f, 1.0f), "::");
										ImGui::SameLine(0, 5);
										
										// Make class name clickable for navigation
										ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0, 0, 0, 0));
										ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.8f, 0.7f, 0.6f, 0.3f));
										ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.8f, 0.7f, 0.6f, 0.5f));
										ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(0, 0));
										
									std::string className = classInfo.name;
									ImVec2 classTextSize = ImGui::CalcTextSize(className.c_str());
									
									if (ImGui::Button(std::format("##class_{}_{}", typeScope->name, className).c_str(), classTextSize)) {
										// Switch to Type Browser tab and navigate to this class
										requestedTab = 1;
										navigateToClass = className;
										navigationFrameDelay = 2;
									}										// Draw colored text over button
										ImVec2 buttonMin = ImGui::GetItemRectMin();
										ImGui::GetWindowDrawList()->AddText(buttonMin, ImGui::GetColorU32(ImVec4(0.8f, 0.7f, 0.6f, 1.0f)), className.c_str());
										
										// Show tooltip on hover
										if (ImGui::IsItemHovered()) {
											ImGui::BeginTooltip();
											ImGui::Text("Click to navigate to class %s in Type Browser", className.c_str());
											ImGui::EndTooltip();
										}
										
										ImGui::PopStyleVar();
										ImGui::PopStyleColor(3);
										
									ImGui::SameLine(0, 5);
									ImGui::TextColored(ImVec4(0.6f, 0.6f, 0.6f, 1.0f), ".");
									ImGui::SameLine(0, 5);
									ImGui::Text("%s", fieldName.c_str());
									
									// Field details on new line with indentation - make it clickable
									ImGui::Indent(20.0f);
									
									// Store position for clickable area
									ImVec2 fieldLineStart = ImGui::GetCursorScreenPos();
									
									ImGui::TextColored(ImVec4(0.5f, 0.7f, 0.7f, 1.0f), "[0x%04X]", field.offset);
									ImGui::SameLine(0, 5);
									ImGui::TextColored(ImVec4(0.6f, 0.8f, 0.6f, 1.0f), "%s", fieldType.c_str());
									
									// Make the field line clickable
									ImVec2 fieldLineEnd = ImGui::GetItemRectMax();
									fieldLineEnd.x = ImGui::GetWindowPos().x + ImGui::GetWindowContentRegionMax().x;
									
									ImGui::SetCursorScreenPos(fieldLineStart);
									ImGui::InvisibleButton(std::format("##fieldclick_{}_{}", className, fieldName).c_str(), ImVec2(fieldLineEnd.x - fieldLineStart.x, fieldLineEnd.y - fieldLineStart.y));
									
									if (ImGui::IsItemClicked()) {
										// Navigate to this field in Type Browser
										requestedTab = 1;
										navigateToClass = className;
										navigateToField = fieldName;
										navigationFrameDelay = 2;
									}
									
									if (ImGui::IsItemHovered()) {
										ImGui::BeginTooltip();
										ImGui::Text("Click to navigate to this field in Type Browser");
										ImGui::EndTooltip();
									}										// Context menu
										if (ImGui::BeginPopupContextItem()) {
											if (ImGui::MenuItem("Copy Field Name")) {
												ImGui::SetClipboardText(field.fieldName);
											}
											if (ImGui::MenuItem("Copy Class Name")) {
												ImGui::SetClipboardText(classInfo.name);
											}
											if (ImGui::MenuItem("Copy Scope Name")) {
												ImGui::SetClipboardText(typeScope->name);
											}
											if (ImGui::MenuItem("Copy Offset")) {
												char offsetStr[32];
												sprintf_s(offsetStr, "0x%X", field.offset);
												ImGui::SetClipboardText(offsetStr);
											}
											if (ImGui::MenuItem("Copy Type")) {
												ImGui::SetClipboardText(field.schemaType->typeName);
											}
										if (ImGui::MenuItem("Copy Full Path")) {
											std::string fullPath = std::format("{}::{}::{}", typeScope->name, classInfo.name, field.fieldName);
											ImGui::SetClipboardText(fullPath.c_str());
										}
										if (ImGui::MenuItem("Copy as SCHEMA")) {
											std::string schemaDefine = std::format("SCHEMA({}, {}, \"{}\", \"{}\", \"{}\")",
												field.schemaType->typeName,
												field.fieldName,
												field.fieldName,
												classInfo.name,
												typeScope->name);
											ImGui::SetClipboardText(schemaDefine.c_str());
										}
										ImGui::Separator();
										if (ImGui::MenuItem("Navigate to Class")) {
											requestedTab = 1;
											navigateToClass = className;
											navigationFrameDelay = 2;
										}
										if (ImGui::MenuItem("Navigate to Field")) {
											requestedTab = 1;
											navigateToClass = className;
											navigateToField = fieldName;
											navigationFrameDelay = 2;
										}
										ImGui::EndPopup();
										}
										
										// Tooltip with details
										if (ImGui::IsItemHovered()) {
											ImGui::BeginTooltip();
											ImGui::TextColored(ImVec4(0.7f, 0.9f, 0.7f, 1.0f), "Field Details");
											ImGui::Separator();
											ImGui::Text("Scope: %s", typeScope->name);
											ImGui::Text("Class: %s", classInfo.name);
											ImGui::Text("Field: %s", field.fieldName);
											ImGui::Text("Type: %s", fieldType.c_str());
											ImGui::Text("Offset: 0x%04X (%d bytes)", field.offset, field.offset);
											ImGui::Separator();
											ImGui::TextColored(ImVec4(0.5f, 0.5f, 0.5f, 1.0f), "Right-click for options");
											ImGui::EndTooltip();
										}
										
										ImGui::Unindent(20.0f);
										ImGui::Spacing();
										
										ImGui::PopID();
									}
								}
							}
						}
					}
					
					if (resultsCount == 0 && (activeFilters > 0)) {
						ImGui::TextColored(ImVec4(1.0f, 1.0f, 0.0f, 1.0f), "No fields found matching your search criteria.");
					} else if (resultsCount > 0) {
						ImGui::Separator();
						ImGui::TextColored(ImVec4(0.7f, 0.7f, 0.7f, 1.0f), "Found %d matching field(s)", resultsCount);
					}
					
					ImGui::EndChild();
					ImGui::EndTabItem();
				}

				ImGui::EndTabBar();
			}

			ImGui::End();
		}
		});

	while (!GetAsyncKeyState(VK_END)) {
		if (GetAsyncKeyState(VK_INSERT) & 1) {
			*outerTakesFocus = !*outerTakesFocus;
		}

		Sleep(100);
	}

	MH_Uninitialize();

	presentManager.shutdown();
	return 0;
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {
	if (fdwReason == DLL_PROCESS_ATTACH) {
		DisableThreadLibraryCalls(hinstDLL);
		CreateThread(nullptr, 0, MainThread, nullptr, 0, nullptr);
	}

	return TRUE;
}
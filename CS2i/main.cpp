#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <algorithm>
#include <format>

#include "sdk.h"
#include "sdk-gen.h"

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

bool calcBoxSize(std::span<BoneJointData> boneData, ImVec2& min, ImVec2& max) {
	auto& bones = CS2::bonesToRead;
	bool canDraw = true;
	ImVec2 screenPos;
	for (auto bone : bones) {
		auto pos = boneData[bone].pos;
		if (W2S(screenPos, pos)) {
			if (screenPos.x < min.x) min.x = screenPos.x;
			if (screenPos.y < min.y) min.y = screenPos.y;
			if (screenPos.x > max.x) max.x = screenPos.x;
			if (screenPos.y > max.y) max.y = screenPos.y;
		}
		else {
			canDraw = false;
			break;
		}
	}

	// Padding +/- x pixels
	const float padding = 5.0f;
	min.x -= padding;
	min.y -= padding;
	max.x += padding;
	max.y += padding;

	return canDraw;
}

void drawBox(std::span<BoneJointData> boneData, ImVec2* oMin = nullptr, ImVec2* oMax = nullptr, ImColor color = ImColor(100, 255, 100, 200)) {
	ImVec2 min = ImVec2(FLT_MAX, FLT_MAX);
	ImVec2 max = ImVec2(-FLT_MAX, -FLT_MAX);
	if (!calcBoxSize(boneData, min, max)) return;
	float boxWidth = max.x - min.x;
	float boxHeight = max.y - min.y;

	// Just draw corners
	ImDrawList* drawList = ImGui::GetBackgroundDrawList();
	float lineThickness = 2.0f;
	// Top-left
	drawList->AddLine(ImVec2(min.x, min.y), ImVec2(min.x + boxWidth * 0.2f, min.y), color, lineThickness);
	drawList->AddLine(ImVec2(min.x, min.y), ImVec2(min.x, min.y + boxHeight * 0.2f), color, lineThickness);
	// Top-right
	drawList->AddLine(ImVec2(max.x, min.y), ImVec2(max.x - boxWidth * 0.2f, min.y), color, lineThickness);
	drawList->AddLine(ImVec2(max.x, min.y), ImVec2(max.x, min.y + boxHeight * 0.2f), color, lineThickness);
	// Bottom-left
	drawList->AddLine(ImVec2(min.x, max.y), ImVec2(min.x + boxWidth * 0.2f, max.y), color, lineThickness);
	drawList->AddLine(ImVec2(min.x, max.y), ImVec2(min.x, max.y - boxHeight * 0.2f), color, lineThickness);
	// Bottom-right
	drawList->AddLine(ImVec2(max.x, max.y), ImVec2(max.x - boxWidth * 0.2f, max.y), color, lineThickness);
	drawList->AddLine(ImVec2(max.x, max.y), ImVec2(max.x, max.y - boxHeight * 0.2f), color, lineThickness);

	if (oMin) *oMin = min;
	if (oMax) *oMax = max;
}

DWORD WINAPI MainThread(LPVOID lpParam) {
	CS2::initPtrs();
	CS2::Interfaces::setupInterfaces();

	static bool* outerTakesFocus = nullptr;
	
	// UI State
	static char scopeSearchBuf[256] = "";
	static char classSearchBuf[256] = "";
	static char fieldSearchBuf[256] = "";
	static int currentTab = 0;
	static int requestedTab = -1; // For programmatic tab switching
	static char offsetTestModule[128] = "client.dll";
	static char offsetTestClass[128] = "C_BaseEntity";
	static char offsetTestField[128] = "m_iHealth";
	static std::string navigateToClass = ""; // For base class navigation
	static std::string navigateToField = ""; // For field navigation within a class
	static int navigationFrameDelay = 0; // Frame delay for smooth navigation
	// Field Search Tab
	static char fieldNameSearchBuf[256] = "";
	static char fieldTypeSearchBuf[256] = "";
	static char fieldScopeSearchBuf[256] = "";
	static char fieldClassSearchBuf[256] = "";

	auto& presentManager = CS2::PresentManager_t::get();
	presentManager.setOnPresentCallback([](bool& takesFocus, IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags) {
		outerTakesFocus = &takesFocus;

		for (int i = 1; i < 64; i++) {
			auto* entityController = CS2::CEntityList::GetEntityByIndex<CS2::CCSPlayerController>(i);
			if (!entityController) continue;

			auto& hPawn = entityController->m_hPlayerPawn();
			if (!hPawn.IsValid()) continue;
			auto* playerPawn = CS2::CEntityList::GetEntityByHandle<CS2::C_CSPlayerPawn>(hPawn);
			if (!playerPawn) continue;

			auto& pos = playerPawn->m_pGameSceneNode()->m_vecAbsOrigin();

			CS2::C_CSPlayerPawn* localPlayer = *reinterpret_cast<CS2::C_CSPlayerPawn**>(CS2::Offsets::dwLocalPlayerPawn);
			if (playerPawn == localPlayer) continue;
			if (entityController->m_iTeamNum() == localPlayer->m_iTeamNum()) continue;
			if ((int)playerPawn->m_iHealth() <= 0) continue;
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
			auto& boneIndices = CS2::bonesToRead;

			for (int boneIndex : boneIndices) {
				if (!W2S(bonePositions[boneIndex], pBoneArray[boneIndex].pos)) {
					bonePositions[boneIndex] = ImVec2(-10.0f, -10.0f); // Off-screen
				}
			}

			// Draw bones using bonePairs
			for (const auto& [start, end] : bonePairs) {
				if (bonePositions[start].x >= 0 && bonePositions[end].x >= 0) {
					ImGui::GetBackgroundDrawList()->AddLine(
						bonePositions[start],
						bonePositions[end],
						IM_COL32(100, 255, 100, 200), 2.0f
					);
				}
			}

			ImVec2 min, max;
			drawBox(std::span<BoneJointData>(pBoneArray, 28), &min, &max);

			float healthPerc = (float)playerPawn->m_iHealth() / (float)playerPawn->m_iMaxHealth();
			ImGui::GetBackgroundDrawList()->AddRectFilled(
				ImVec2(min.x - 4.0f, min.y),
				ImVec2(min.x - 2.0f, max.y),
				IM_COL32(0, 0, 0, 150)
			);
			ImGui::GetBackgroundDrawList()->AddRectFilled(
				ImVec2(min.x - 4.0f, max.y - (max.y - min.y) * healthPerc),
				ImVec2(min.x - 2.0f, max.y),
				IM_COL32(255 - (int)(255 * healthPerc), (int)(255 * healthPerc), 0, 255)
			);

			float armorPerc = (float)playerPawn->m_ArmorValue() / 100.0f;
			ImGui::GetBackgroundDrawList()->AddRectFilled(
				ImVec2(max.x + 2.0f, min.y),
				ImVec2(max.x + 4.0f, max.y),
				IM_COL32(0, 0, 0, 150)
			);
			ImGui::GetBackgroundDrawList()->AddRectFilled(
				ImVec2(max.x + 2.0f, max.y - (max.y - min.y) * armorPerc),
				ImVec2(max.x + 4.0f, max.y),
				IM_COL32(100, 100, 255, 255)
			);

			auto name = entityController->m_sSanitizedPlayerName();
			if (name) {
				ImGui::GetBackgroundDrawList()->AddText(
					ImVec2(min.x + ((max.x - min.x) / 2) - (ImGui::CalcTextSize(name).x / 2), max.y + 2.0f),
					IM_COL32(255, 255, 255, 255),
					name
				);
			}
		}

		if (takesFocus) {
			ImGui::SetNextWindowSize(ImVec2(800, 600), ImGuiCond_FirstUseEver);
			ImGui::Begin("CS2 Schema Explorer", nullptr, ImGuiWindowFlags_MenuBar);

			// Menu Bar
			if (ImGui::BeginMenuBar()) {
				if (ImGui::BeginMenu("View")) {
					if (ImGui::MenuItem("Entity Debug")) requestedTab = 0;
					if (ImGui::MenuItem("Type Browser")) requestedTab = 1;
					if (ImGui::MenuItem("Field Search")) requestedTab = 2;
					ImGui::EndMenu();
				}
				ImGui::EndMenuBar();
			}

			// Tab Bar
			if (ImGui::BeginTabBar("MainTabs")) {
				ImGuiTabItemFlags entityFlags = (requestedTab == 0) ? ImGuiTabItemFlags_SetSelected : ImGuiTabItemFlags_None;
				if (requestedTab == 0) requestedTab = -1;
				
				if (ImGui::BeginTabItem("Entity Debug", nullptr, entityFlags)) {
					ImGui::Spacing();
					ImGui::Text("Entity List Debug:");
					ImGui::Separator();
					ImGui::Spacing();
					
					ImGui::BeginChild("EntityList", ImVec2(0, 0), false);

					// Table layout
					if (ImGui::BeginTable("EntityTable", 5, ImGuiTableFlags_Resizable | ImGuiTableFlags_RowBg | ImGuiTableFlags_Borders | ImGuiTableFlags_ScrollY | ImGuiTableFlags_SizingFixedFit)) {
						// Table headers
						ImGui::TableSetupColumn("Name");
						ImGui::TableSetupColumn("Index");
						ImGui::TableSetupColumn("Health");
						ImGui::TableSetupColumn("Ping");
						ImGui::TableSetupColumn("Position");
						ImGui::TableHeadersRow();

						for (int i = 1; i < 64; i++) {
							auto* entityController = CS2::CEntityList::GetEntityByIndex<CS2::CCSPlayerController>(i);
							if (!entityController) continue;

							auto& hPawn = entityController->m_hPlayerPawn();
							if (!hPawn.IsValid()) continue;
							auto* playerPawn = CS2::CEntityList::GetEntityByHandle<CS2::C_CSPlayerPawn>(hPawn);
							if (!playerPawn) continue;

							auto& pos = playerPawn->m_pGameSceneNode()->m_vecAbsOrigin();

							const char* sanitizedName = entityController->m_sSanitizedPlayerName();

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
						}
						ImGui::EndTable();
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
					
					// Handle delayed navigation
					if (navigationFrameDelay > 0) {
						navigationFrameDelay--;
					}
					
					for (auto& typeScope : schema->typeScopes.ToSpan()) {
						std::string scopeName = typeScope->name;
						std::string scopeNameLower = scopeName;
						std::transform(scopeNameLower.begin(), scopeNameLower.end(), scopeNameLower.begin(), ::tolower);
						
						// Filter scopes
						if (!scopeSearch.empty() && scopeNameLower.find(scopeSearch) == std::string::npos) {
							continue;
						}
						
						visibleScopes++;
						char scopeLabel[512];
						int classCount = 0;
						
						// Count visible classes in this scope
						for (const auto& classInfo : typeScope->declaredClasses) {
							std::string className = classInfo.name;
							std::string classNameLower = className;
							std::transform(classNameLower.begin(), classNameLower.end(), classNameLower.begin(), ::tolower);
							if (classSearch.empty() || classNameLower.find(classSearch) != std::string::npos) {
								classCount++;
							}
						}
						
						sprintf_s(scopeLabel, "%s (%d classes)", typeScope->name, classCount);
						
						// Auto-expand scope if we're navigating to a class in it
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
							// Right-click context menu for scope
							if (ImGui::BeginPopupContextItem()) {
								if (ImGui::MenuItem("Copy Scope Name")) {
									ImGui::SetClipboardText(typeScope->name);
								}
							ImGui::Separator();
							if (ImGui::MenuItem("Generate SDK for Scope")) {
								std::string sdkOutput;
								
								// Collect all class names in this scope
								std::vector<std::string> declaredClasses;
								for (const auto& classInfo : typeScope->declaredClasses) {
									std::string className = classInfo.name;
									if (className.find("::") == std::string::npos) {
										declaredClasses.push_back(className);
									}
								}
								
							// Collect all referenced types from fields
							std::vector<std::string> referencedTypes;
							for (const auto& classInfo : typeScope->declaredClasses) {
								std::string className = classInfo.name;
								if (className.find("::") != std::string::npos) {
									continue;
								}
								
								// Check base class
								auto bc = classInfo.baseClasses;
								if (bc && bc->info && bc->info->name) {
									std::string baseClassName = bc->info->name;
									// Add base class if not already declared in this scope
									if (std::find(declaredClasses.begin(), declaredClasses.end(), baseClassName) == declaredClasses.end() &&
										std::find(referencedTypes.begin(), referencedTypes.end(), baseClassName) == referencedTypes.end()) {
										referencedTypes.push_back(baseClassName);
									}
								}
								
								if (classInfo.fieldsCount > 0) {
										for (const auto& field : classInfo.fieldsSpan()) {
											std::string typeName = field.schemaType->typeName;
											
											// Remove pointer/reference markers and template parameters for checking
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
											
											// Trim whitespace
											cleanTypeName.erase(0, cleanTypeName.find_first_not_of(" \t"));
											cleanTypeName.erase(cleanTypeName.find_last_not_of(" \t") + 1);
											
											// Check if this type is not already declared and not a primitive
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
								
								// Forward declarations
								sdkOutput += "// Forward declarations\n";
								for (const auto& className : declaredClasses) {
									sdkOutput += std::format("class {};\n", className);
								}
								
								// Forward declare referenced but not defined types
								if (!referencedTypes.empty()) {
									sdkOutput += "\n// Referenced types (not in this scope)\n";
									for (const auto& typeName : referencedTypes) {
										sdkOutput += std::format("class {};\n", typeName);
									}
								}
								sdkOutput += "\n";								// Generate class definitions
								for (const auto& classInfo : typeScope->declaredClasses) {
									std::string className = classInfo.name;
									
									// Skip classes with :: in the name
									if (className.find("::") != std::string::npos) {
										continue;
									}
									
									// If class has no fields, skip full definition (already forward declared)
									if (classInfo.fieldsCount == 0) {
										continue;
									}
									
									sdkOutput += std::format("// Class: {} (Size: 0x{:X})\n", className, classInfo.size);
									
									// Class declaration with base class if it exists
									auto bc = classInfo.baseClasses;
									if (bc && bc->info && bc->info->name) {
										sdkOutput += std::format("class {} : public {} {{\n", className, bc->info->name);
									} else {
										sdkOutput += std::format("class {} {{\n", className);
									}
									
									sdkOutput += "public:\n";
									
									// Generate SCHEMA macros for all fields
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
								
								// Filter classes
								if (!classSearch.empty() && classNameLower.find(classSearch) == std::string::npos) {
									continue;
								}
								
								std::string baseClasses;
								auto bc = classInfo.baseClasses;
								bool hasBaseClass = (bc && bc->info && bc->info->name);
								if (hasBaseClass) {
									baseClasses = bc->info->name;
								}

								// Use colored TreeNodeEx for better control
								ImGuiTreeNodeFlags flags = ImGuiTreeNodeFlags_None;
								
								// Auto-expand and scroll to class if we're navigating to it
								bool isNavigationTarget = (!navigateToClass.empty() && classInfo.name == navigateToClass && navigationFrameDelay == 0);
								if (isNavigationTarget) {
									flags |= ImGuiTreeNodeFlags_DefaultOpen;
									ImGui::SetNextItemOpen(true);
								}
								
							bool nodeOpen = ImGui::TreeNodeEx(classInfo.name, flags, "%s", classInfo.name);
							
							// Right-click context menu for class - must be right after TreeNodeEx
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
							
							// Scroll to the navigation target
							if (isNavigationTarget) {
								ImGui::SetScrollHereY(0.3f); // Scroll so item is 30% from top
								navigateToClass = ""; // Clear navigation target
							}								// Add base class in color on the same line if it exists - make it clickable
								if (hasBaseClass) {
									ImGui::SameLine(0, 5);
									ImGui::TextColored(ImVec4(0.6f, 0.6f, 0.6f, 1.0f), ":");
									ImGui::SameLine(0, 5);
									
									// Make base class name clickable
									ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0, 0, 0, 0));
									ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.7f, 0.6f, 0.8f, 0.3f));
									ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.7f, 0.6f, 0.8f, 0.5f));
									ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(0, 0));
									
									// Calculate text size for button
									ImVec2 textSize = ImGui::CalcTextSize(baseClasses.c_str());
									
									if (ImGui::Button(std::format("##baseclass_{}", classInfo.name).c_str(), textSize)) {
										// Navigate to base class
										navigateToClass = baseClasses;
										navigationFrameDelay = 2; // Small delay for smooth transition
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
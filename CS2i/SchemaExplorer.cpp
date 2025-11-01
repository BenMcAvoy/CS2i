#include "SchemaExplorer.h"
#include <algorithm>
#include <format>
#include <vector>

void SchemaExplorer::update(bool menuOpen) {
    if (!menuOpen) return;
    
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
            renderEntityDebugTab();
            ImGui::EndTabItem();
        }
        
        ImGuiTabItemFlags browserFlags = (requestedTab == 1) ? ImGuiTabItemFlags_SetSelected : ImGuiTabItemFlags_None;
        if (requestedTab == 1) requestedTab = -1;
        
        if (ImGui::BeginTabItem("Type Browser", nullptr, browserFlags)) {
            renderTypeBrowserTab();
            ImGui::EndTabItem();
        }

        ImGuiTabItemFlags searchFlags = (requestedTab == 2) ? ImGuiTabItemFlags_SetSelected : ImGuiTabItemFlags_None;
        if (requestedTab == 2) requestedTab = -1;
        
        if (ImGui::BeginTabItem("Field Search", nullptr, searchFlags)) {
            renderFieldSearchTab();
            ImGui::EndTabItem();
        }

        ImGui::EndTabBar();
    }

    ImGui::End();
}

void SchemaExplorer::renderEntityDebugTab() {
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
                ImGui::TextColored(ImVec4(0.5f, 1.0f, 0.5f, 1.0f), "World tint active!");
                ImGui::Text("Note: Restart map or toggle off/on to see changes");
            }
        }
    }

    if (ImGui::CollapsingHeader("All Entities", ImGuiTreeNodeFlags_DefaultOpen)) {
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
                                case 0:
                                    result = a.index - b.index;
                                    break;
                                case 1:
                                    result = strcmp(a.name ? a.name : "", b.name ? b.name : "");
                                    break;
                                case 4:
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
}

void SchemaExplorer::renderTypeBrowserTab() {
    ImGui::Spacing();
    
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

    std::string scopeSearch = scopeSearchBuf;
    std::string classSearch = classSearchBuf;
    std::string fieldSearch = fieldSearchBuf;
    std::transform(scopeSearch.begin(), scopeSearch.end(), scopeSearch.begin(), ::tolower);
    std::transform(classSearch.begin(), classSearch.end(), classSearch.begin(), ::tolower);
    std::transform(fieldSearch.begin(), fieldSearch.end(), fieldSearch.begin(), ::tolower);

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
                    
                    ImVec2 buttonMin = ImGui::GetItemRectMin();
                    ImGui::GetWindowDrawList()->AddText(buttonMin, ImGui::GetColorU32(ImVec4(0.7f, 0.6f, 0.8f, 1.0f)), baseClasses.c_str());
                    
                    if (ImGui::IsItemHovered()) {
                        ImGui::BeginTooltip();
                        ImGui::Text("Click to navigate to %s", baseClasses.c_str());
                        ImGui::EndTooltip();
                    }
                    
                    ImGui::PopStyleVar();
                    ImGui::PopStyleColor(3);
                }
                
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
                            
                            if (!fieldSearch.empty() && fieldNameLower.find(fieldSearch) == std::string::npos) {
                                continue;
                            }
                            
                            bool isFieldTarget = (!navigateToField.empty() && fieldName == navigateToField && classInfo.name == navigateToClass && navigationFrameDelay == 0);
                            
                            ImGui::PushID(&field);
                            
                            if (isFieldTarget) {
                                ImVec2 lineStartHighlight = ImGui::GetCursorScreenPos();
                                ImVec2 lineSizeHighlight = ImVec2(ImGui::GetWindowContentRegionMax().x - ImGui::GetWindowContentRegionMin().x, ImGui::GetTextLineHeightWithSpacing());
                                ImGui::GetWindowDrawList()->AddRectFilled(lineStartHighlight, ImVec2(lineStartHighlight.x + lineSizeHighlight.x, lineStartHighlight.y + lineSizeHighlight.y), ImGui::GetColorU32(ImVec4(0.3f, 0.5f, 0.3f, 0.3f)));
                            }
                            
                            ImVec2 lineStart = ImGui::GetCursorScreenPos();
                            
                            ImGui::TextColored(ImVec4(0.5f, 0.7f, 0.7f, 1.0f), "[0x%04X]", field.offset);
                            ImGui::SameLine(0, 5);
                            
                            ImGui::TextColored(ImVec4(0.6f, 0.8f, 0.6f, 1.0f), "%s", field.schemaType->typeName);
                            ImGui::SameLine(0, 5);
                            
                            ImGui::Text("%s", field.fieldName);
                            
                            if (isFieldTarget) {
                                ImGui::SetScrollHereY(0.3f);
                                navigateToField = "";
                            }
                            
                            ImVec2 lineEnd = ImGui::GetItemRectMax();
                            lineEnd.x = ImGui::GetWindowPos().x + ImGui::GetWindowContentRegionMax().x;
                            
                            ImGui::SetCursorScreenPos(lineStart);
                            ImGui::InvisibleButton("##fieldline", ImVec2(lineEnd.x - lineStart.x, lineEnd.y - lineStart.y));
                            
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
                            }
                            
                            ImGui::PopID();
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
}

void SchemaExplorer::renderFieldSearchTab() {
    ImGui::Spacing();
    ImGui::Text("Search for fields across all classes:");
    ImGui::Spacing();
    
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
    
    std::string fieldNameSearch = fieldNameSearchBuf;
    std::string fieldTypeSearch = fieldTypeSearchBuf;
    std::string fieldScopeSearch = fieldScopeSearchBuf;
    std::string fieldClassSearch = fieldClassSearchBuf;
    std::transform(fieldNameSearch.begin(), fieldNameSearch.end(), fieldNameSearch.begin(), ::tolower);
    std::transform(fieldTypeSearch.begin(), fieldTypeSearch.end(), fieldTypeSearch.begin(), ::tolower);
    std::transform(fieldScopeSearch.begin(), fieldScopeSearch.end(), fieldScopeSearch.begin(), ::tolower);
    std::transform(fieldClassSearch.begin(), fieldClassSearch.end(), fieldClassSearch.begin(), ::tolower);
    
    int activeFilters = 0;
    if (!fieldNameSearch.empty()) activeFilters++;
    if (!fieldTypeSearch.empty()) activeFilters++;
    if (!fieldScopeSearch.empty()) activeFilters++;
    if (!fieldClassSearch.empty()) activeFilters++;
    
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
    
    ImGui::BeginChild("FieldSearchResults", ImVec2(0, 0), false);
    
    auto schema = CS2::Interfaces::GSchemaSystem;
    int resultsCount = 0;
    
    for (auto& typeScope : schema->typeScopes.ToSpan()) {
        std::string scopeName = typeScope->name;
        std::string scopeNameLower = scopeName;
        std::transform(scopeNameLower.begin(), scopeNameLower.end(), scopeNameLower.begin(), ::tolower);
        
        if (!fieldScopeSearch.empty() && scopeNameLower.find(fieldScopeSearch) == std::string::npos) {
            continue;
        }
        
        for (const auto& classInfo : typeScope->declaredClasses) {
            std::string className = classInfo.name;
            std::string classNameLower = className;
            std::transform(classNameLower.begin(), classNameLower.end(), classNameLower.begin(), ::tolower);
            
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
                    
                    bool nameMatches = fieldNameSearch.empty() || fieldNameLower.find(fieldNameSearch) != std::string::npos;
                    bool typeMatches = fieldTypeSearch.empty() || fieldTypeLower.find(fieldTypeSearch) != std::string::npos;
                    
                    if (nameMatches && typeMatches) {
                        resultsCount++;
                        
                        ImGui::PushID(&field);
                        
                        ImGui::TextColored(ImVec4(0.7f, 0.7f, 0.9f, 1.0f), "%s", typeScope->name);
                        ImGui::SameLine(0, 5);
                        ImGui::TextColored(ImVec4(0.6f, 0.6f, 0.6f, 1.0f), "::");
                        ImGui::SameLine(0, 5);
                        
                        ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0, 0, 0, 0));
                        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.8f, 0.7f, 0.6f, 0.3f));
                        ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.8f, 0.7f, 0.6f, 0.5f));
                        ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(0, 0));
                        
                        std::string className = classInfo.name;
                        ImVec2 classTextSize = ImGui::CalcTextSize(className.c_str());
                        
                        if (ImGui::Button(std::format("##class_{}_{}", typeScope->name, className).c_str(), classTextSize)) {
                            requestedTab = 1;
                            navigateToClass = className;
                            navigationFrameDelay = 2;
                        }
                        
                        ImVec2 buttonMin = ImGui::GetItemRectMin();
                        ImGui::GetWindowDrawList()->AddText(buttonMin, ImGui::GetColorU32(ImVec4(0.8f, 0.7f, 0.6f, 1.0f)), className.c_str());
                        
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
                        
                        ImGui::Indent(20.0f);
                        
                        ImVec2 fieldLineStart = ImGui::GetCursorScreenPos();
                        
                        ImGui::TextColored(ImVec4(0.5f, 0.7f, 0.7f, 1.0f), "[0x%04X]", field.offset);
                        ImGui::SameLine(0, 5);
                        ImGui::TextColored(ImVec4(0.6f, 0.8f, 0.6f, 1.0f), "%s", fieldType.c_str());
                        
                        ImVec2 fieldLineEnd = ImGui::GetItemRectMax();
                        fieldLineEnd.x = ImGui::GetWindowPos().x + ImGui::GetWindowContentRegionMax().x;
                        
                        ImGui::SetCursorScreenPos(fieldLineStart);
                        ImGui::InvisibleButton(std::format("##fieldclick_{}_{}", className, fieldName).c_str(), ImVec2(fieldLineEnd.x - fieldLineStart.x, fieldLineEnd.y - fieldLineStart.y));
                        
                        if (ImGui::IsItemClicked()) {
                            requestedTab = 1;
                            navigateToClass = className;
                            navigateToField = fieldName;
                            navigationFrameDelay = 2;
                        }
                        
                        if (ImGui::IsItemHovered()) {
                            ImGui::BeginTooltip();
                            ImGui::Text("Click to navigate to this field in Type Browser");
                            ImGui::EndTooltip();
                        }
                        
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
}

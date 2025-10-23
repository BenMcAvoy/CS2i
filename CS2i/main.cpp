#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "sdk.h"

static void tryMe() {
	auto s = CS2::Interfaces::GSchemaSystem->typeScopes.ToSpan();
	LOGINFO("Number of type scopes: %zu", s.size());
	
	// Test finding a specific class instead of iterating all
	for (CS2::CSchemaSystemTypeScope* scope : s) {
		LOGINFO("Type scope name: %s", scope->name);
		
		for (const auto& classInfo : scope->declaredClasses) {
			LOGINFO("  Class name: %s", classInfo.name);

			for (const auto& field : classInfo.fieldsSpan()) {
				LOGINFO("    /* 0x%03X */ %s %s", field.offset, field.schemaType->typeName, field.fieldName);
			}
		}
	}
}

DWORD WINAPI MainThread(LPVOID lpParam) {
	CS2::initPtrs();
	CS2::Interfaces::setupInterfaces();

	static bool* outerTakesFocus = nullptr;
	auto& presentManager = CS2::PresentManager_t::get();
	presentManager.setOnPresentCallback([](bool& takesFocus, IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags) {
		outerTakesFocus = &takesFocus;

		if (takesFocus) {
			ImGui::Begin("Type explorer");

			auto schema = CS2::Interfaces::GSchemaSystem;
			for (auto& typeScope : schema->typeScopes.ToSpan()) {
				if (ImGui::TreeNode(typeScope->name)) {
					for (const auto& classInfo : typeScope->declaredClasses) {
						if (ImGui::TreeNode(classInfo.name)) {
							for (const auto& field : classInfo.fieldsSpan()) {
								if (ImGui::TreeNode(field.fieldName)) {
									ImGui::Text("Offset: 0x%03X", field.offset);
									ImGui::Text("Type name: %s", field.schemaType->typeName);
									ImGui::Text("Type category: %d", static_cast<int>(field.schemaType->typeCategory));
									ImGui::Text("Atomic category: %d", static_cast<int>(field.schemaType->atomicCategory));
									ImGui::TreePop();
								}
							}
							ImGui::TreePop();
						}
					}
					ImGui::TreePop();
				}
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
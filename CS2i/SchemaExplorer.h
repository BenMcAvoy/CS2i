#pragma once
#include "Feature.h"
#include "sdk.h"
#include "sdk-gen.h"
#include <string>

class SchemaExplorer : public Feature {
public:
    const char* getName() const override { return "SchemaExplorer"; }
    
    void update(bool menuOpen) override;

private:
    char scopeSearchBuf[256] = "";
    char classSearchBuf[256] = "";
    char fieldSearchBuf[256] = "";
    int currentTab = 0;
    int requestedTab = -1;
    char offsetTestModule[128] = "client.dll";
    char offsetTestClass[128] = "C_BaseEntity";
    char offsetTestField[128] = "m_iHealth";
    std::string navigateToClass = "";
    std::string navigateToField = "";
    int navigationFrameDelay = 0;
    char fieldNameSearchBuf[256] = "";
    char fieldTypeSearchBuf[256] = "";
    char fieldScopeSearchBuf[256] = "";
    char fieldClassSearchBuf[256] = "";
    bool enableEntityESP = false;
    bool enableWorldTint = false;
    float tintColor[3] = { 1.0f, 0.5f, 1.0f };
    char entitySearchBuf[256] = "";
    
    void renderEntityDebugTab();
    void renderTypeBrowserTab();
    void renderFieldSearchTab();
};

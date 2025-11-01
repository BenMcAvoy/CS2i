#pragma once
#include "Feature.h"
#include "sdk.h"

class WorldTint : public Feature {
public:
    const char* getName() const override { return "WorldTint"; }
    
    void update(bool menuOpen) override;
    
    bool enabled = false;
    float tintColor[3] = { 1.0f, 0.5f, 1.0f };
};

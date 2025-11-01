#pragma once
#include "Feature.h"
#include "sdk.h"

class WeaponESP : public Feature {
public:
    const char* getName() const override { return "WeaponESP"; }
    
    void update(bool menuOpen) override;
    
    bool enabled = true;

private:
    bool W2S(ImVec2& out, const CS2::Vector3& in);
};

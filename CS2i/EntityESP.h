#pragma once
#include "Feature.h"
#include "sdk.h"

class EntityESP : public Feature {
public:
    const char* getName() const override { return "EntityESP"; }
    
    void update(bool menuOpen) override;
    
    bool enabled = false;

private:
    bool W2S(ImVec2& out, const CS2::Vector3& in);
};

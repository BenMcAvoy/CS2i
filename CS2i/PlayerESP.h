#pragma once
#include "Feature.h"
#include "sdk.h"
#include "sdk-gen.h"
#include <chrono>
#include <unordered_map>

using SteadyClock = std::chrono::steady_clock;
using TimePoint = SteadyClock::time_point;

struct DeathState {
    TimePoint timestamp;
    bool fadedOut = false;
};

struct BoneJointData {
    CS2::Vector3 pos;
    float scale;
    char pad[16];
};

class PlayerESP : public Feature {
public:
    const char* getName() const override { return "PlayerESP"; }
    
    void update(bool menuOpen) override;

private:
    std::unordered_map<int, DeathState> m_deathStates;
    static constexpr float SKELETON_FADE_DURATION = 2.0f;
    
    static constexpr auto boneIndices = {
        CS2::PELVIS, CS2::NECK, CS2::HEAD, CS2::LEFT_SHOULDER, CS2::LEFT_ELBOW, CS2::LEFT_HAND,
        CS2::RIGHT_SHOULDER, CS2::RIGHT_ELBOW, CS2::RIGHT_HAND, CS2::LEFT_LEG, CS2::LEFT_KNEE, CS2::LEFT_FOOT,
        CS2::RIGHT_LEG, CS2::RIGHT_KNEE, CS2::RIGHT_FOOT
    };
    
    bool W2S(ImVec2& out, const CS2::Vector3& in);
    bool calcBoxSize(std::span<BoneJointData> boneData, ImVec2& min, ImVec2& max);
    void drawBox(std::span<BoneJointData> boneData, ImVec2* oMin = nullptr, ImVec2* oMax = nullptr, ImColor color = ImColor(255, 255, 255, 255));
};

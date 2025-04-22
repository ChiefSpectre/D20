#pragma once

#include "imgui.h"
#include <vector>
#include <string>
#include <map>
#include <algorithm>

static inline void D20FeetTraitToggleButton()
{
    static bool showFeetTrait = false;
    static int characterLevel = 1;

    static std::vector<std::pair<int, std::string>> selectedFeatures;
    static int selectedFeatureIndex = 0;
    static bool showFeaturePicker = false;

    // Full feature pool by level
    static std::map<int, std::vector<std::string>> featureChoicesByLevel = {
        {1, {"Rogue Proficiencies", "Expertise", "Sneak Attack", "Thieves' Cant"}},
        {2, {"Cunning Action", "Action Surge", "Darkvision", "Fey Ancestry", "Trance", "Fighting Style", "Sneak Attack"}},
        {3, {"Roguish Archetype", "Martial Archetype", "Metamagic"}},
        {4, {"ASI / Feat"}},
        {5, {"Uncanny Dodge", "Extra Attack"}},
        {6, {"Archetype Feature"}},
        {7, {"Evasion", "Remarkable Athlete"}},
        {8, {"ASI / Feat"}},
        {9, {"Indomitable", "Magical Ambush"}},
        {10, {"Archetype Feature"}},
        {11, {"Reliable Talent", "Improved Extra Attack"}},
        {12, {"ASI / Feat"}},
        {13, {"Steady Aim", "Indomitable (2 uses)"}},
        {14, {"Blindsense", "Cleansing Touch"}},
        {15, {"Slippery Mind", "Persistent Rage"}},
        {16, {"ASI / Feat"}},
        {17, {"Archetype Feature"}},
        {18, {"Elusive", "Survivor"}},
        {19, {"ASI / Feat"}},
        {20, {"Stroke of Luck", "Archmage's Might"}}
    };

    auto grantsFeatureAtLevel = [](int level) {
        return featureChoicesByLevel.find(level) != featureChoicesByLevel.end();
        };

    if (ImGui::Button("Class Feat"))
    {
        showFeetTrait = !showFeetTrait;
    }

    ImGui::SameLine();
    if (ImGui::ArrowButton("LevelDown", ImGuiDir_Down)) {
        if (characterLevel > 1) {
            if (grantsFeatureAtLevel(characterLevel)) {
                selectedFeatures.erase(
                    std::remove_if(selectedFeatures.begin(), selectedFeatures.end(),
                        [&](const std::pair<int, std::string>& f) {
                            return f.first == characterLevel;
                        }),
                    selectedFeatures.end()
                );
            }
            characterLevel--;
        }
    }

    ImGui::SameLine();
    if (ImGui::ArrowButton("LevelUp", ImGuiDir_Up)) {
        if (characterLevel < 20) {
            characterLevel++;
            if (grantsFeatureAtLevel(characterLevel)) {
                showFeaturePicker = true;
                selectedFeatureIndex = 0;
            }
        }
    }

    ImGui::SameLine();
    ImGui::Text("Level: %d", characterLevel);

    // Feature Picker Modal
    if (showFeaturePicker) {
        ImGui::OpenPopup("Choose a Feature");
        showFeaturePicker = false;
    }

    if (ImGui::BeginPopupModal("Choose a Feature", NULL, ImGuiWindowFlags_AlwaysAutoResize)) {
        const auto& features = featureChoicesByLevel[characterLevel];
        ImGui::Text("Pick a feature for level %d:", characterLevel);
        ImGui::Separator();

        std::vector<const char*> featureNames;
        for (const auto& f : features) featureNames.push_back(f.c_str());

        ImGui::Combo("Available Features", &selectedFeatureIndex, featureNames.data(), static_cast<int>(featureNames.size()));

        if (ImGui::Button("Confirm")) {
            selectedFeatures.emplace_back(characterLevel, features[selectedFeatureIndex]);
            ImGui::CloseCurrentPopup();
        }

        ImGui::SameLine();
        if (ImGui::Button("Cancel")) {
            ImGui::CloseCurrentPopup();
        }

        ImGui::EndPopup();
    }

    if (showFeetTrait)
    {
        ImGui::Separator();
        ImGui::BeginChild("FeatureTraitWindow", ImVec2(320, 300), true);

        ImGui::Text("Acquired Features:");
        for (const auto& f : selectedFeatures) {
            ImGui::BulletText("Level %d: %s", f.first, f.second.c_str());
        }

        ImGui::Spacing();
        ImGui::Separator();
        ImGui::Text("Static Traits:");
        ImGui::BulletText("Keen Senses");
        ImGui::BulletText("Elf Weapon Training");
        ImGui::BulletText("Fleet of Foot");

        ImGui::EndChild();
    }
}

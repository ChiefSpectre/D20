#pragma once
#ifndef D20_FEET_TRAIT_H
#define D20_FEET_TRAIT_H

#include "imgui.h"

static inline void D20FeetTraitToggleButton()
{
    static bool showFeetTrait = false;

    if (ImGui::Button("Class Feat"))
    {
        showFeetTrait = !showFeetTrait;
    }

    if (showFeetTrait)
    {
        ImGui::Separator();
        ImGui::BeginChild("FeatureTraitWindow", ImVec2(300, 250), true);
        ImGui::Text("Features:");
        ImGui::BulletText("Darkvision");
        ImGui::BulletText("Fey Ancestry");
        ImGui::BulletText("Trance");

        ImGui::Spacing();
        ImGui::Text("Traits:");
        ImGui::BulletText("Keen Senses");
        ImGui::BulletText("Elf Weapon Training");
        ImGui::BulletText("Fleet of Foot");
        ImGui::EndChild();
    }
}

#endif // D20_FEET_TRAIT_H

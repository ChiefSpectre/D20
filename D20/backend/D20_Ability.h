#pragma once
#ifndef D20_ABILITY_H
#define D20_ABILITY_H

#include "imgui.h"

// Doc: When writing the container_size, if set to 0, it automatically adjusts.

static inline void D20AbilityBlock()
{
    char charaName[35] = "";
    ImVec2 container_size(580, 100);  // Fixed width and height.
    ImGui::BeginChild("Container_2", container_size, true, ImGuiWindowFlags_None);

    ImGui::Text("Strength\tDexterity\tConstitution\tIntelligence\tWisdom\tCharisma");
    ImGui::SameLine();
    if (ImGui::Button("Edit")) {

    }
    if (ImGui::Button("Str")) {

    }
    ImGui::SameLine(0, 51);
    if (ImGui::Button("Dex")) {

    }
    ImGui::SameLine(0, 64);
    if (ImGui::Button("Con")) {

    }
    ImGui::SameLine(0, 81);
    if (ImGui::Button("Int")) {

    }
    ImGui::SameLine(0, 75);
    if (ImGui::Button("Wis")) {

    }
    ImGui::SameLine(0, 65);
    if (ImGui::Button("Cha")) {

    }
    ImGui::EndChild();
}

#endif // D20_Ability_H

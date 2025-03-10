#ifndef D20_SKILLS_H
#define D20_SKILLS_H

#include "imgui.h"

// Doc: When writing the container_size, if set to 0, it automatically adjusts.

static inline void D20SkillBlock()
{
    ImGui::BeginChild("Container_3", ImVec2(200, 0), true, ImGuiWindowFlags_None);

    ImGui::Text("Acrobatics");
    ImGui::Text("Animal Handling");
    ImGui::Text("Arcana");
    ImGui::Text("Athletics");
    ImGui::Text("Deception");
    ImGui::Text("History");
    ImGui::Text("Insight");
    ImGui::Text("Intimidation");
    ImGui::Text("Investigation");
    ImGui::Text("Medicine");
    ImGui::Text("Nature");
    ImGui::Text("Perception");
    ImGui::Text("Performance");
    ImGui::Spacing();
    ImGui::EndChild();
    
}

#endif // D20_Skills_H

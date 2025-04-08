#ifndef D20_Main_H
#define D20_Main_H

#include "imgui.h"

// Doc: When writing the container_size, if set to 0, it automatically adjusts.

static inline void D20MainBlock()
{
    ImVec2 container_size(0, 0);  // Fixed width and height.
    ImGui::SetCursorPosX(216);
    ImGui::SetCursorPosY(216);
    ImGui::BeginChild("Container_Main", container_size, true, ImGuiWindowFlags_None);
    ImGui::Text("Combat");

    ImGui::Spacing();
    ImGui::EndChild();


}

#endif // D20_HP_H

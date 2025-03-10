#ifndef D20_ACS_H
#define D20_ACS_H

#include "imgui.h"

// Doc: When writing the container_size, if set to 0, it automatically adjusts.

static inline void D20ACSBlock()
{
    ImVec2 container_size(0, 100);  // Fixed width and height.
    ImGui::BeginChild("Container_5", container_size, true, ImGuiWindowFlags_None);
    ImGui::Text("AC/SPEED");

    ImGui::Spacing();
    ImGui::EndChild();
    ImGui::SetNextItemWidth(0);

}

#endif // D20_ACS_H

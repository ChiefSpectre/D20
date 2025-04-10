#ifndef D20_HP_H
#define D20_HP_H

#include "imgui.h"

// Doc: When writing the container_size, if set to 0, it automatically adjusts.

static inline void D20HPBlock()
{
    ImVec2 container_size(500, 100);  // Fixed width and height.
    ImGui::BeginChild("Container_4", container_size, true, ImGuiWindowFlags_None);
    ImGui::Text("Hit Points");

    ImGui::Spacing();
    ImGui::EndChild();


}

#endif // D20_HP_H

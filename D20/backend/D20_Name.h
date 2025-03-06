#pragma once
#ifndef D20_NAME_H
#define D20_NAME_H

#include "imgui.h"

static inline void ShowWrappedContainer()
{
    ImVec2 container_size(200, 0);  // Fixed width, auto-height
    ImGui::BeginChild("Container", container_size, true, ImGuiWindowFlags_None);

    ImGui::Text("Item 1");
    ImGui::Button("Button 1");
    ImGui::Text("Item 2");
    ImGui::Button("Button 2");

    ImGui::EndChild();
}

#endif // D20_NAME_H

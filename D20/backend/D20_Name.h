#ifndef D20_NAME_H
#define D20_NAME_H

#include "imgui.h"

// Doc: When writing the container_size, if set to 0, it automatically adjusts.
    char charaName[35] = "";
static inline void D20NameBlock()
{


    ImVec2 container_size(500, 100);  // Fixed width and height.
    ImGui::BeginChild("Container_1", container_size, true, ImGuiWindowFlags_None);

    ImGui::Text("Character Name");
    ImGui::InputText("##charaName",charaName,sizeof(charaName));
    ImGui::Spacing();
    ImGui::EndChild();

    
}

#endif // D20_NAME_H

#ifndef D20_NAME_H
#define D20_NAME_H

#include "imgui.h"

// Doc: When writing the container_size, if set to 0, it automatically adjusts.
    char charaName[35] = "";
    char raceName[35] = "";
    char className[15] = "";
static inline void D20NameBlock()
{
    static bool editName = false;

    ImVec2 container_size(500, 100);  // Fixed width and height.
    ImGui::BeginChild("Container_1", container_size, true, ImGuiWindowFlags_None);
    // Toggle Edit Name
    if (ImGui::Button("Edit")) {
        editName = !editName;
    }
    if (editName) {
        ImGui::InputText("##charaName", charaName, sizeof(charaName));
        ImGui::InputText("##raceName", raceName, sizeof(raceName));
        ImGui::InputText("##className", className, sizeof(className));

    }
    else {
        ImGui::Text(charaName);
        ImGui::Text(raceName);
        ImGui::Text(className);

    }
    
    
    ImGui::Spacing();
    ImGui::EndChild();

    
}

#endif // D20_NAME_H

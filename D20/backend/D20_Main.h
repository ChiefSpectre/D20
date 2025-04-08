#ifndef D20_Main_H
#define D20_Main_H

#include "imgui.h"
#include "D20_RNG.h"
// Doc: When writing the container_size, if set to 0, it automatically adjusts.
    int y = 0;
    int num = 0;
    int diceSides = 0; // Default in case of an invalid selection
    int diceResult = 0;
static inline void D20MainBlock()
{
    
    ImVec2 container_size(0, 0);  // Fixed width and height.
    ImGui::SetCursorPosX(216);
    ImGui::SetCursorPosY(216);
    ImGui::BeginChild("Container_Main", container_size, true, ImGuiWindowFlags_None);
    ImGui::Text("Combat");
    ImGui::NewLine();
    if (ImGui::Button("Roll")) {
        diceResult = RollDice(num, diceSides, y);
    }
    ImGui::SameLine();
    ImGui::SetNextItemWidth(80);
    ImGui::InputInt("Num", &num, 1, 100, ImGuiInputTextFlags_CharsDecimal);
    ImGui::SameLine();
    static int current_item = 0;
    const char* items[] = { "D4", "D6", "D8", "D10", "D12", "D20", "D100" };

    // Set the width of the combo box
    ImGui::SetNextItemWidth(52);
    ImGui::Combo("D", &current_item, items, IM_ARRAYSIZE(items));

    // Map the selected item to the corresponding dice number using a switch case
    
    switch (current_item)
    {
    case 0: diceSides = 4;  break; // "D4"
    case 1: diceSides = 6;  break; // "D6"
    case 2: diceSides = 8;  break; // "D8"
    case 3: diceSides = 10; break; // "D10"
    case 4: diceSides = 12; break; // "D12"
    case 5: diceSides = 20; break; // "D20"
    case 6: diceSides = 100; break; // "D100"
    default: diceSides = 0; break;  // In case something goes wrong
    }

    // Now, diceSides holds the value of the selected dice
    ImGui::SameLine();
    ImGui::Text("+");
    ImGui::SameLine();
    ImGui::SetNextItemWidth(80);
    ImGui::InputInt("Mod", &y, 1, 100, ImGuiInputTextFlags_CharsDecimal);
    ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "%d", diceResult);
    ImGui::Spacing();
    ImGui::EndChild();


}

#endif // D20_HP_H

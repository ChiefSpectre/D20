#ifndef D20_Main_H
#define D20_Main_H

#include "imgui.h"
#include "D20_RNG.h"
#include "D20_Spells.h"
#include "D20_Inventory.h"
#include "../D20_Inventory.h"
#include "D20_feet&trait.h"
#include "../d20_feet&trait.h"
int y = 0;
int num = 0;
int diceSides = 0; // Default in case of an invalid selection
int diceResult = 0;

// New enum to handle toggling between UI panels
enum D20Panel {
    PANEL_NONE,
    PANEL_SPELLBOOK,
    PANEL_INVENTORY,
	PANEL_FEATURE_TRAIT
};

static D20Panel currentPanel = PANEL_NONE; // Only one visible at a time

static inline void D20MainBlock()
{
    ImVec2 container_size(0, 0);  // Auto-sizing
    ImGui::SetCursorPosX(216);
    ImGui::SetCursorPosY(216);
    ImGui::BeginChild("Container_Main", container_size, true, ImGuiWindowFlags_None);

    ImGui::Text("Combat");
    ImGui::SameLine();

    // Toggle Spellbook
    if (ImGui::Button("Spellbook")) {
        currentPanel = (currentPanel == PANEL_SPELLBOOK) ? PANEL_NONE : PANEL_SPELLBOOK;
    }

    ImGui::SameLine();

    // Toggle Inventory
    if (ImGui::Button("Inventory")) {
        currentPanel = (currentPanel == PANEL_INVENTORY) ? PANEL_NONE : PANEL_INVENTORY;
    }
    ImGui::SameLine();
    //toggle trait
    if (ImGui::Button("Feature & Trait")) {
        currentPanel = (currentPanel == PANEL_FEATURE_TRAIT) ? PANEL_NONE : PANEL_FEATURE_TRAIT;
    }
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

    ImGui::SetNextItemWidth(52);
    ImGui::Combo("D", &current_item, items, IM_ARRAYSIZE(items));

    switch (current_item)
    {
    case 0: diceSides = 4;  break;
    case 1: diceSides = 6;  break;
    case 2: diceSides = 8;  break;
    case 3: diceSides = 10; break;
    case 4: diceSides = 12; break;
    case 5: diceSides = 20; break;
    case 6: diceSides = 100; break;
    default: diceSides = 0; break;
    }

    ImGui::SameLine();
    ImGui::Text("+");
    ImGui::SameLine();
    ImGui::SetNextItemWidth(80);
    ImGui::InputInt("Mod", &y, 1, 100, ImGuiInputTextFlags_CharsDecimal);

    ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "%d", diceResult);
    ImGui::Spacing();

    // === Show the selected panel only ===
    if (currentPanel == PANEL_SPELLBOOK) {
        ImGui::Separator();
        ImGui::Text("Spellbook:");
        D20SpellBlock();
    }
    else if (currentPanel == PANEL_INVENTORY) {
        ImGui::Separator();
        ImGui::Text("Inventory:");
        D20InventoryToggleButton(); // Or your actual inventory UI function
    }
    else if (currentPanel == PANEL_FEATURE_TRAIT) {
        ImGui::Separator();
        ImGui::Text("Feature:");
        D20FeetTraitToggleButton(); // Or your actual inventory UI function
    }
    ImGui::EndChild();
}

#endif // D20_Main_H

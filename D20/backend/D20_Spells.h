#ifndef D20_SPELLS_H
#define D20_SPELLS_H

#include "imgui.h"

// Function to display a list of spells in a child window
static inline void D20SpellBlock()
{
    // Begin a child window with a fixed width of 200 and auto-adjusting height
    ImGui::BeginChild("Spell_Container", ImVec2(200, 0), true);

    // Display spell names
    ImGui::Text("Magic Missile");
    ImGui::Text("Fireball");
    ImGui::Text("Lightning Bolt");
    ImGui::Text("Cure Wounds");
    ImGui::Text("Invisibility");
    ImGui::Text("Shield");
    ImGui::Text("Detect Magic");
    ImGui::Text("Mage Armor");
    ImGui::Text("Teleport");
    ImGui::Text("Fly");
    ImGui::Text("Charm Person");
    ImGui::Text("Dispel Magic");
    ImGui::Text("Counterspell");
    ImGui::Text("Polymorph");
    ImGui::Text("Haste");

    // Add spacing at the end of the list
    ImGui::Spacing();

    // End the child window
    ImGui::EndChild();
}

#endif // D20_SPELLS_H

#pragma once
#ifndef D20_INVENTORY_H
#define D20_INVENTORY_H

#include "imgui.h"

// Function to toggle and display the inventory
static inline void D20InventoryToggleButton()
{
    // Static state variable to show/hide inventory
    static bool showInventory = false;

    // Unique ID for the button to avoid conflicts
    if (ImGui::Button("Equipment"))
    {
        showInventory = !showInventory;
    }

    if (showInventory)
    {
        ImGui::Separator();
        ImGui::BeginChild("InventoryWindow", ImVec2(300, 250), true);

        ImGui::Text(" Backpack:");
        ImGui::BulletText("Rope (50 ft)");
        ImGui::BulletText("Rations (5 days)");
        ImGui::BulletText("Waterskin");
        ImGui::BulletText("Flint and Steel");
        ImGui::BulletText("Torches x3");

        ImGui::Spacing();

        ImGui::Text(" Weapons:");
        ImGui::BulletText("Shortsword");
        ImGui::BulletText("Longbow + 20 arrows");
        ImGui::BulletText("Dagger x2");

        ImGui::Spacing();

        ImGui::Text(" Magic Items:");
        ImGui::BulletText("Potion of Healing x2");
        ImGui::BulletText("Bag of Holding");
        ImGui::BulletText("Ring of Protection");

        ImGui::EndChild();
    }
}

#endif // D20_INVENTORY_H

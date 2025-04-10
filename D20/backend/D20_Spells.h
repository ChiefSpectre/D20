#ifndef D20_SPELLS_H
#define D20_SPELLS_H

#include "imgui.h"

// Function to display a list of spells in a child window
static inline void D20SpellBlock()
{
    // Begin a child window with a fixed width of 200 and auto-adjusting height
    //ImGui::BeginChild("Spell_Container", ImVec2(200, 0), true);
    static bool showCantrip = false; 
    static bool level1 = false;
    static bool level2 = false;
    static bool level3 = false;
    static bool level4 = false;
    static bool level5 = false;
    static bool level6 = false;
    static bool level7 = false;
    static bool level8 = false;
    static bool level9 = false;
    if (ImGui::Button("Cantrips")) {
        showCantrip = !showCantrip;
    }
    ImGui::SameLine();
    if (ImGui::Button("Level 1")) {
        level1 = !level1;
    }
    ImGui::SameLine();
    if (ImGui::Button("Level 2")) {
        level2 = !level2;
    }
    ImGui::SameLine();
    if (ImGui::Button("Level 3")) {
        level3 = !level3;
    }
    ImGui::SameLine();
    if (ImGui::Button("Level 4")) {
        level4= !level4;
    }
    ImGui::SameLine();
    if (ImGui::Button("Level 5")) {
        level5 = !level5;
    }
    ImGui::SameLine();
    if (ImGui::Button("Level 6")) {
        level6 = !level6;
    }
    ImGui::SameLine();
    if (ImGui::Button("Level 7")) {
        level7 = !level7;
    }
    ImGui::SameLine();
    if (ImGui::Button("Level 8")) {
        level8 = !level8;
    }
    ImGui::SameLine();
    if (ImGui::Button("Level 9")) {
        level9 = !level9;
    }

    if (showCantrip)
    {
       
        // Display spell names
        ImGui::Text("");
        ImGui::Text("Cantrip");
        ImGui::Text("Acid Splash");
        ImGui::Text("Blade Ward");
        ImGui::Text("Booming blade");
     
    }
	if (level1) {
		// Display spell names
        ImGui::Text(""); 
        ImGui::Text("level 1");
		ImGui::Text("Asborb Element");
		ImGui::Text("Acid Stream");
		ImGui::Text("Alarm");
	
	}
    if (level2) {
        // Display spell names
        ImGui::Text("");
        ImGui::Text("Level 2");
        ImGui::Text("Aganazzar's Scorcher");
        ImGui::Text("Aid");
        ImGui::Text("Air Bubble");

    }
    if (level3) {
        // Display spell names
        ImGui::Text("");
        ImGui::Text("Level 3");
        ImGui::Text("Animate Dead");
        ImGui::Text("Antagonize");
        ImGui::Text("Antagonize (AU)");

    }
    if (level4) {
        // Display spell names
        ImGui::Text("");
        ImGui::Text("Level 4");
        ImGui::Text("Arcane Eye");
        ImGui::Text("Aura of Life");
        ImGui::Text("Aura of Purity");

    }
    if (level5) {
        // Display spell names
        ImGui::Text("");
        ImGui::Text("Level 5");
        ImGui::Text("Animate Objects");
        ImGui::Text("Antilife Shell");
        ImGui::Text("Awaken");

    }
    if (level6) {
        // Display spell names
        ImGui::Text(""); 
        ImGui::Text("Level 6");
        ImGui::Text("Arcane Gate");
        ImGui::Text("Blade Barrier");
        ImGui::Text("Bones of the Earth");

    }
    if (level7) {
        // Display spell names
        ImGui::Text("");
        ImGui::Text("Level 7");
        ImGui::Text("Conjure Celestial");
        ImGui::Text("Conjure Hezrou (UA)");
        ImGui::Text("Create Magen");

    }
   
	if (level8) {
		// Display spell names
        ImGui::Text("");
        ImGui::Text("Level 8");
        ImGui::Text("Abi-Dalzim's Horrid Wilting");
		ImGui::Text("Animal Shapes");
		ImGui::Text("Antimagic Field");
	}
	if (level9) {
		// Display spell names
        ImGui::Text("");
        ImGui::Text("Level 9");
		ImGui::Text("Astral Projection");
		ImGui::Text("Blade of Disaster");
		ImGui::Text("Foresight");
	}
    // Add spacing at the end of the list
    ImGui::Spacing();

}

#endif // D20_SPELLS_H

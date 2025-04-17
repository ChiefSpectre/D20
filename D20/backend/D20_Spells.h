#ifndef D20_SPELLS_H
#define D20_SPELLS_H

#include "imgui.h"

static inline void D20SpellBlock()
{
    static int visibleLevel = -1; // -1 = none, 0 = cantrip, 1-9 = spell levels

    // Spell level buttons
    const char* labels[] = {
        "Cantrips", "Level 1", "Level 2", "Level 3", "Level 4",
        "Level 5", "Level 6", "Level 7", "Level 8", "Level 9"
    };

    for (int i = 0; i < 10; ++i)
    {
        if (i > 0) ImGui::SameLine();
        if (ImGui::Button(labels[i]))
        {
            visibleLevel = (visibleLevel == i) ? -1 : i; // toggle
        }
    }

    ImGui::Separator();

    // Spell lists based on visibleLevel
    switch (visibleLevel)
    {
    case 0: // Cantrips
        ImGui::Text("Cantrips");
        ImGui::BulletText("Acid Splash");
        ImGui::BulletText("Blade Ward");
        ImGui::BulletText("Booming Blade");
        break;
    case 1:
        ImGui::Text("Level 1 Spells");
        ImGui::BulletText("Absorb Elements");
        ImGui::BulletText("Acid Stream");
        ImGui::BulletText("Alarm");
        break;
    case 2:
        ImGui::Text("Level 2 Spells");
        ImGui::BulletText("Aganazzar's Scorcher");
        ImGui::BulletText("Aid");
        ImGui::BulletText("Air Bubble");
        break;
    case 3:
        ImGui::Text("Level 3 Spells");
        ImGui::BulletText("Animate Dead");
        ImGui::BulletText("Antagonize");
        ImGui::BulletText("Antagonize (UA)");
        break;
    case 4:
        ImGui::Text("Level 4 Spells");
        ImGui::BulletText("Arcane Eye");
        ImGui::BulletText("Aura of Life");
        ImGui::BulletText("Aura of Purity");
        break;
    case 5:
        ImGui::Text("Level 5 Spells");
        ImGui::BulletText("Animate Objects");
        ImGui::BulletText("Antilife Shell");
        ImGui::BulletText("Awaken");
        break;
    case 6:
        ImGui::Text("Level 6 Spells");
        ImGui::BulletText("Arcane Gate");
        ImGui::BulletText("Blade Barrier");
        ImGui::BulletText("Bones of the Earth");
        break;
    case 7:
        ImGui::Text("Level 7 Spells");
        ImGui::BulletText("Conjure Celestial");
        ImGui::BulletText("Conjure Hezrou (UA)");
        ImGui::BulletText("Create Magen");
        break;
    case 8:
        ImGui::Text("Level 8 Spells");
        ImGui::BulletText("Abi-Dalzim's Horrid Wilting");
        ImGui::BulletText("Animal Shapes");
        ImGui::BulletText("Antimagic Field");
        break;
    case 9:
        ImGui::Text("Level 9 Spells");
        ImGui::BulletText("Astral Projection");
        ImGui::BulletText("Blade of Disaster");
        ImGui::BulletText("Foresight");
        break;
    }

    ImGui::Spacing();
}

#endif // D20_SPELLS_H

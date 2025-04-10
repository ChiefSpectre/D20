#ifndef D20_RNG_H
#define D20_RNG_H

#include "imgui.h"
#include <random>

inline int RollDice(int numDice, int max, int modifier)
{
    static int lastFrame = -1;
    static std::mt19937 rng;
    int currentFrame = ImGui::GetFrameCount();

    if (currentFrame != lastFrame)
    {
        rng.seed(currentFrame);
        lastFrame = currentFrame;
    }

    std::uniform_int_distribution<int> dist(1, max);
    int total = 0;

    for (int i = 0; i < numDice; ++i)
    {
        total += dist(rng);
    }

    return total + modifier;
}

#endif // D20_RNG_H

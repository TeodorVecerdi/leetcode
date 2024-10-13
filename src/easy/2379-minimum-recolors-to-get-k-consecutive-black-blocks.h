#pragma once

#include <bits/stdc++.h>
#include "problem_runner.h"

inline size_t solve(const std::string& blocks, const size_t k) {
    size_t minimum = std::numeric_limits<size_t>::max();

    // Calculate initial sliding window
    size_t recolors = 0;
    for (size_t i = 0; i < k; ++i) {
        if (blocks[i] != 'B')
            ++recolors;
    }
    minimum = std::min(minimum, recolors);

    // Slide the window
    for (size_t i = k; i < blocks.size(); ++i) {
        if (blocks[i - k] != 'B')
            --recolors;
        if (blocks[i] != 'B')
            ++recolors;

        minimum = std::min(minimum, recolors);
    }

    return minimum;
}

DEFINE_PROBLEM(MinimumRecolorsToGetKConsecutiveBlackBlocks, L(std::pair<std::string, size_t>), size_t) {
    const auto& [blocks, k] = input;
    return solve(blocks, k);
})

TEST_CASE(L({"WBBWWBBWBW", 7}), 3)
TEST_CASE(L({"WBWBBBW", 2}), 0)

BUILD_PROBLEM;

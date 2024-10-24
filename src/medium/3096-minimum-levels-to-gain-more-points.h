#pragma once

#include <bits/stdc++.h>
#include "problem_runner.h"

inline int32_t solve(const std::vector<int32_t>& input) {
    const auto operation = [](const int32_t a, const int32_t b) { return a + (b == 0 ? -1 : 1); };
    const int32_t sum = std::accumulate(input.begin(), input.end(), 0, operation);

    int32_t score = 0;
    for (int32_t i = 0; i < input.size() - 1; ++i) {
        score += input[i] == 0 ? -1 : 1;
        if (score > sum - score) {
            return i + 1;
        }
    }

    return -1;
}

DEFINE_PROBLEM(MinimumLevelsToGainMorePoints, std::vector<int32_t>, int32_t) {
    return solve(input);
})

TEST_CASE(L({1,0,1,0}), 1)
TEST_CASE(L({1,1,1,1,1}), 3)
TEST_CASE(L({0,0}), -1)

BUILD_PROBLEM;

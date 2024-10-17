#pragma once

#include <bits/stdc++.h>
#include "problem_runner.h"

inline int32_t solve(const int32_t num) {
    std::string numStr = std::to_string(num);
    std::vector last_seen(10, -1);
    for (int32_t i = 0; i < numStr.size(); ++i) {
        last_seen[numStr[i] - '0'] = i;
    }

    for (int32_t i = 0; i < numStr.size(); ++i) {
        for (int32_t d = 9; d > numStr[i] - '0'; --d) {
            if (last_seen[d] > i) {
                std::swap(numStr[i], numStr[last_seen[d]]);
                return std::stoi(numStr);
            }
        }
    }

    return num;
}

DEFINE_PROBLEM(MaximumSwap, int32_t, int32_t) {
    return solve(input);
})

TEST_CASE(2736, 7236)
TEST_CASE(9973, 9973)

BUILD_PROBLEM;

#pragma once

#include <bits/stdc++.h>
#include "problem_runner.h"

inline size_t solve(const std::string& input) {
    size_t result = 0;
    size_t counter = 0;
    const auto n = static_cast<int32_t>(input.size());
    for (int32_t i = n - 1; i >= 0; --i) {
        if (input[i] == '0') {
            ++counter;
        } else {
            result += counter;
        }
    }

    return result;
}

DEFINE_PROBLEM(SeparateBlackAndWhiteBalls, std::string, size_t) {
    return solve(input);
})

TEST_CASE("101", 1)
TEST_CASE("100", 2)
TEST_CASE("0111", 0)

BUILD_PROBLEM;

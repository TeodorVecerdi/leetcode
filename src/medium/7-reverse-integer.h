#pragma once

#include <bits/stdc++.h>
#include "problem_runner.h"

inline int32_t solve(int32_t value) {
    constexpr int32_t max = std::numeric_limits<int32_t>::max();
    constexpr int32_t min = std::numeric_limits<int32_t>::min();

    int32_t result = 0;
    while (value) {
        if (result > max / 10 || result < min / 10)
            return 0;

        result *= 10;
        result += value % 10;
        value /= 10;
    }

    return result;
}

DEFINE_PROBLEM(ReverseInteger, int32_t, int32_t) {
    return solve(input);
})

TEST_CASE(123, 321)
TEST_CASE(-123, -321)
TEST_CASE(120, 21)

BUILD_PROBLEM;

#pragma once

#include <bits/stdc++.h>
#include "problem_runner.h"

// Given a binary string s, return the minimum number of character swaps to make it alternating, or -1 if it is impossible.
// The string is called alternating if no two adjacent characters are equal. For example, the strings "010" and "1010" are alternating, while the string "0100" is not.
// Any two characters may be swapped, even if they are not adjacent.

inline int32_t solve(const std::string& s) {
    const auto n = static_cast<int32_t>(s.size());

    // Count mismatches for both patterns (010101... and 101010...)
    int32_t zeros = 0;
    int32_t mismatch0 = 0, mismatch1 = 0;
    for (size_t i = 0; i < n; ++i) {
        if (s[i] == '0') zeros++;

        if (s[i] == '0' + i % 2)
            mismatch0++;
        else
            mismatch1++;
    }

    // If the counts differ by more than 1, it's impossible
    const int32_t ones = n - zeros;
    if (std::abs(zeros - ones) > 1)
        return -1;

    // Choose the pattern that matches the counts
    if (zeros == ones)
        return std::min(mismatch0, mismatch1) / 2;
    if (zeros > ones)
        return mismatch1 / 2;
    return mismatch0 / 2;
}

DEFINE_PROBLEM(MinimumSwapsToMakeBinaryStringAlternating, std::string, int) {
    return solve(input);
})

TEST_CASE("111000", 1)
TEST_CASE("010", 0)
TEST_CASE("1110", -1)
TEST_CASE("1100", 1)
TEST_CASE("10", 0)
TEST_CASE("1", 0)
TEST_CASE("100", 1)
TEST_CASE("01000", -1)

BUILD_PROBLEM;

#pragma once

#include <bits/stdc++.h>
#include "problem_runner.h"

// You are given a 0-indexed string s of even length n. The string consists of exactly n / 2 opening brackets '['
// and n / 2 closing brackets ']'.
//
// A string is called balanced if and only if:
// - It is the empty string, or
// - It can be written as AB, where both A and B are balanced strings, or
// - It can be written as [C], where C is a balanced string.
//
// You may swap the brackets at any two indices any number of times.
//
// Return the minimum number of swaps to make s balanced.

inline int32_t seekOpen(const std::string& s, int32_t start, const int32_t end) {
    while (start > end && s[start] != '[') {
        start--;
    }

    return start;
}

inline int32_t solve(std::string s) {
    const auto n = static_cast<int32_t>(s.size());
    int32_t start = 0, end = n - 1;
    int32_t swaps = 0, open = 0;

    std::cout << std::endl << std::endl;

    while (start <= end) {
        if (s[start] == '[') {
            // std::cout << "open++" << std::endl;
            open++;
        } else if (open > 0) {
            // std::cout << "open--" << std::endl;
            open--;
        } else {
            const int32_t close = seekOpen(s, end, start);
            if (close == start) {
                break;
            }

            end = close;
            // std::cout << "swap " << start << " " << close << "; " << s;
            std::swap(s[start], s[close]);
            // std::cout << " -> " << s << std::endl;
            swaps++;
            open++;
        }

        start++;
    }

    return swaps;
}

DEFINE_PROBLEM(MinimumSwapsToMakeStringBalanced, std::string, int) {
    return solve(input);
})

TEST_CASE("][][", 1)
TEST_CASE("]]][[[", 2)
TEST_CASE("[]", 0)
TEST_CASE("]]]][[][[][[[]]][[]][[[[][]]][[]]]]]][]][[][][[]][][[]]]][[[[[[[", 4)

BUILD_PROBLEM;
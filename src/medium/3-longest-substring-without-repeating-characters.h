#pragma once

#include <bits/stdc++.h>
#include "problem_runner.h"

inline size_t solve(const std::string& input) {
    std::array<size_t, 256> occurrences{};
    size_t left = 0, right = 0, max = 0;
    while (right < input.size()) {
        occurrences[input[right]]++;

        // If the current character is repeated, move the left pointer to the right until the current character is no longer repeated
        if (occurrences[input[right]] > 1) {
            while (occurrences[input[right]] > 1) {
                occurrences[input[left]]--;
                left++;
            }
        }

        // Update the maximum length
        max = std::max(max, right - left + 1);

        // Move the right pointer to the right
        right++;
    }

    return max;
}

DEFINE_PROBLEM(LongestSubstringWithoutRepeatingCharacters, std::string, size_t) {
            return solve(input);
        })

TEST_CASE("abcabcbb", 3)
TEST_CASE("bbbbb", 1)
TEST_CASE("pwwkew", 3)

BUILD_PROBLEM;

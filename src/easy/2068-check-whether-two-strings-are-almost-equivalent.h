#pragma once

#include <bits/stdc++.h>
#include "problem_runner.h"

// Two strings word1 and word2 are considered almost equivalent if the differences between
// the frequencies of each letter from 'a' to 'z' between word1 and word2 is at most 3.
//
// Given two strings word1 and word2, each of length n, return true if word1 and word2 are almost equivalent, or false otherwise.
//
// The frequency of a letter x is the number of times it occurs in the string.

inline std::array<int32_t, 26> getFrequency(const std::string& word) {
    std::array<int32_t, 26> frequency{};
    for (const auto& c: word) {
        frequency[c - 'a']++;
    }
    return frequency;
}

inline bool solve(const std::string& word1, const std::string& word2) {
    if (std::abs(static_cast<int32_t>(word1.size() - word2.size())) > 3) {
        return false;
    }

    const std::array<int32_t, 26> frequency1 = getFrequency(word1);
    const std::array<int32_t, 26> frequency2 = getFrequency(word2);
    for (size_t i = 0; i < 26; i++) {
        if (std::abs(frequency1[i] - frequency2[i]) > 3) {
            return false;
        }
    }

    return true;
}

DEFINE_PROBLEM(CheckWhetherTwoStringsAreAlmostEquivalent, L(std::pair<std::string, std::string>), bool) {
    const auto [word1, word2] = input;
    return solve(word1, word2);
})

TEST_CASE(L({"aaaa", "bccb"}), false)
TEST_CASE(L({ "abcdeef", "abaaacc"}), true)
TEST_CASE(L({"cccddabba", "babababab"}), true)

BUILD_PROBLEM;

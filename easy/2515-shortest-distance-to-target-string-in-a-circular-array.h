#pragma once

#include <bits/stdc++.h>
#include "../problem_runner.h"

// You are given a 0-indexed circular string array words and a string target. A circular array means that the array's end connects to the array's beginning.
// Starting from startIndex, you can move to either the next word or the previous word with 1 step at a time.
// Return the shortest distance needed to reach the string target. If the string target does not exist in words, return -1.

inline int32_t seek(const std::vector<std::string>& words, const std::string& target, int32_t startIndex, int32_t direction) {
    const int32_t size = words.size();
    int32_t index = startIndex;
    int32_t distance = 0;
    do {
        if (words[index] == target) {
            return distance;
        }

        distance++;
        index = (index + direction + size) % size;
    } while (index != startIndex);

    return -1;
}

inline int32_t solve_single_pass(const std::vector<std::string>& words, const std::string& target, int32_t startIndex) {
    const int32_t size = words.size();
    int32_t distance = std::numeric_limits<int32_t>::max();

    for (int32_t i = 0; i < size; ++i) {
        if (words[i] == target) {
            distance = std::min(distance, std::abs(startIndex - i));
            distance = std::min(distance, std::abs(startIndex - i + size));
            distance = std::min(distance, std::abs(startIndex - i - size));
        }
    }

    return distance == std::numeric_limits<int32_t>::max() ? -1 : distance;
}

DEFINE_PROBLEM(ShortestDistanceToTarget, L(std::tuple<std::vector<std::string>, std::string, int>), int) {
    const auto& [words, target, startIndex] = input;
    return solve_single_pass(words, target, startIndex);
    // return std::min(seek(words, target, startIndex, 1), seek(words, target, startIndex, -1));
})

TEST_CASE(L({{"hello", "i", "am", "leetcode", "hello"}, "hello", 1}), 1)
TEST_CASE(L({{"a", "b", "leetcode"}, "leetcode", 0}), 1)
TEST_CASE(L({{"i", "eat", "leetcode"}, "ate", 0}), -1)
TEST_CASE(L({{"a", "b", "c", "d", "e"}, "c", 0}), 2)
TEST_CASE(L({{"a", "b", "c", "d", "e"}, "a", 4}), 1)

BUILD_PROBLEM;

#pragma once

#include <bits/stdc++.h>
#include "problem_runner.h"

// Given a string s and a character c that occurs in s, return an array of integers `answer`
// where answer.length == s.length and answer[i] is the distance from index i to the
// closest occurrence of character c in s.
//
// The distance between two indices i and j is abs(i - j), where abs is the absolute value function.
inline int32_t seekNext(const std::string& s, const char c, const int32_t startingIndex) {
    for (int32_t i = startingIndex; i < s.size(); ++i) {
        if (s[i] == c) {
            return i;
        }
    }

    return static_cast<int32_t>(s.size());
}

inline std::vector<int32_t> solve(const std::string& s, const char c) {
    // Plan
    // 1. Seek first `c`; fill from that point towards the left with increasing values
    // 2. Repeat until the end of the string:
    // 2a. Seek next `c` from the current index
    // 2b. Fill from the current index towards the next index with the minimum distance
    // 3. Fill from the last `c` towards the right with increasing values

    std::vector<int32_t> answer(s.size());

    // Fill from the first `c` towards the left with increasing values
    const int32_t firstIndex = seekNext(s, c, 0);
    for (int32_t i = 0; i < firstIndex; ++i) {
        answer[i] = firstIndex - i;
    }

    // Repeat until the end of the string
    int32_t currentIndex = firstIndex;
    while (currentIndex < s.size()) {
        // Seek next `c` from the current index
        const int32_t nextIndex = seekNext(s, c, currentIndex + 1);
        if (nextIndex == s.size()) {
            // No more `c` found
            break;
        }

        // Fill from the current index towards the next index with the minimum distance
        for (int32_t i = currentIndex; i < nextIndex && i < s.size(); ++i) {
            answer[i] = std::min(i - currentIndex, nextIndex - i);
        }

        currentIndex = nextIndex;
    }

    // Fill from the last `c` towards the right with increasing values
    for (int32_t i = currentIndex; i < s.size(); ++i) {
        answer[i] = i - currentIndex;
    }

    return answer;
}

DEFINE_PROBLEM(ShortestDistanceToChar, L(std::pair<std::string, char>), std::vector<int>) {
    const auto& [s, c] = input;
    return solve(s, c);
})

TEST_CASE(L({"loveleetcode", 'e'}), L({3,2,1,0,1,0,0,1,2,2,1,0}))
TEST_CASE(L({"aaab", 'b'}), L({3,2,1,0}))
TEST_CASE(L({"abba", 'a'}), L({0,1,1,0}))
TEST_CASE(L({"aaba", 'b'}), L({2,1,0,1}))
TEST_CASE(L({"a", 'a'}), L({0}))
TEST_CASE(L({"abcdefg", 'd'}), L({3,2,1,0,1,2,3}))

BUILD_PROBLEM;
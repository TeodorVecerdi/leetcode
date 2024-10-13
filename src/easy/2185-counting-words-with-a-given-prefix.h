#pragma once

#include <bits/stdc++.h>
#include "problem_runner.h"

inline bool starts_with(const std::string& word, const std::string& prefix) {
    size_t i = 0;
    while (i < word.size() && i < prefix.size() && word[i] == prefix[i])
        i++;

    return i == prefix.size();
}

inline size_t solve(const std::vector<std::string>& words, const std::string& prefix) {
    return std::ranges::count_if(words, [&](const std::string& word) {
        return starts_with(word, prefix);
    });
}

DEFINE_PROBLEM(CountingWordsWithGivenPrefix, L(std::pair<std::vector<std::string>, std::string>), size_t) {
    const auto [words, prefix] = input;
    return solve(words, prefix);
})

TEST_CASE(L({{"pay","attention","practice","attend"}, "at"}), 2)
TEST_CASE(L({{"leetcode","win","loops","success"}, "code"}), 0)

BUILD_PROBLEM;

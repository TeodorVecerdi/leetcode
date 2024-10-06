#pragma once

#include <bits/stdc++.h>
#include "../problem_runner.h"

// Given two strings ransomNote and magazine, return true if ransomNote can be constructed
// by using the letters from magazine and false otherwise. Each letter in magazine can only
// be used once in ransomNote.

DEFINE_PROBLEM(RansomNote, L(std::pair<std::string, std::string>), bool) {
    auto ransomNote = input.first;
    auto magazine = input.second;

    if (ransomNote.size() > magazine.size()) {
        return false;
    }

    std::unordered_map<char, int> magazine_chars;
    for (const char c : magazine) {
        ++magazine_chars[c];
    }

    for (const char c : ransomNote) {
        if (--magazine_chars[c] < 0) {
            return false;
        }
    }

    return true;
})

TEST_CASE(L({"a", "b"}), false)
TEST_CASE(L({"aa", "ab"}), false)
TEST_CASE(L({"aa", "aab"}), true)

BUILD_PROBLEM;
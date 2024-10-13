#pragma once

#include <bits/stdc++.h>
#include "../problem_runner.h"

// Given an input string s, reverse the order of the words.
// A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
// Return a string of the words in reverse order concatenated by a single space.
// Note: s may contain leading or trailing spaces or multiple spaces between two words.
// The returned string should only have a single space separating the words. Do not include any extra spaces.

inline void seekWordEnd(const std::string& s, int32_t& index) {
    while (index > 0 && s[index] == ' ') {
        index--;
    }
}

inline void seekWordStart(const std::string& s, int32_t& index) {
    while (index >= 0 && s[index] != ' ') {
        index--;
    }
}

DEFINE_PROBLEM(ReverseWordsInString, std::string, std::string) {
    std::string s = input;

    const size_t size = s.size();
    char dst[size];
    int32_t dstIndex = 0;
    int32_t srcIndex = static_cast<int32_t>(size) - 1;

    while(srcIndex > 0) {
        // Find word boundaries
        seekWordEnd(s, srcIndex);
        const int32_t wordEnd = srcIndex;
        seekWordStart(s, srcIndex);
        const int32_t wordStart = srcIndex;

        // Break if we reached the beginning of the string
        if (wordStart == 0 && wordEnd == 0 || wordStart == wordEnd) {
            break;
        }

        // Copy word to buffer
        std::copy(s.begin() + wordStart + 1, s.begin() + wordEnd + 1, dst + dstIndex);
        dstIndex += wordEnd - wordStart;

        // Add space if not at the end of the string
        if (dstIndex < size)
            dst[dstIndex] = ' ';
        ++dstIndex;
    }

    // If we didn't copy anything, return the original string (we didn't find any space)
    if (dstIndex == 0)
        return s;

    // Remove trailing space
    dstIndex = std::max(0, dstIndex - 1);

    return std::string(dst, dstIndex);
})

TEST_CASE("the sky is blue", "blue is sky the")
TEST_CASE("  hello world  ", "world hello")
TEST_CASE("a good   example", "example good a")
TEST_CASE("  Bob    Loves  Alice   ", "Alice Loves Bob")
TEST_CASE("Alice", "Alice")
TEST_CASE("a", "a")

BUILD_PROBLEM;
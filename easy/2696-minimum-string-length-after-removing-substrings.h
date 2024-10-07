#pragma once

#include <bits/stdc++.h>
#include "problem_runner.h"

// You are given a string s consisting only of uppercase English letters.
// You can apply some operations to this string where, in one operation, you can remove any
// occurrence of one of the substrings "AB" or "CD" from s.
// Return the minimum possible length of the resulting string that you can obtain.
// Note that the string concatenates after removing the substring and could produce new "AB" or "CD" substrings.

inline int32_t solve(const std::string& s) {
    // Plan
    // 1. Create a stack to store the characters
    // 2. Iterate through the string
    // 3. If the current character is 'B' and the stack is not empty and the top of the stack is 'A',
    //    pop the stack
    // 4. If the current character is 'D' and the stack is not empty and the top of the stack is 'C',
    //    pop the stack
    // 5. Otherwise, push the current character to the stack
    // 6. Return the size of the stack

    std::stack<char> stack;
    for (char c : s) {
        if (!stack.empty() && ((c == 'B' && stack.top() == 'A') || (c == 'D' && stack.top() == 'C'))) {
            stack.pop();
        } else {
            stack.push(c);
        }
    }

    return static_cast<int32_t>(stack.size());
}

DEFINE_PROBLEM(MinStringLengthAfterRemovingSubstrings, std::string, int32_t) {
    const std::string& s = input;
    return solve(s);
})

TEST_CASE("ABFCACDB", 2)
TEST_CASE("ACBBD", 5)
TEST_CASE("ABCDEFGH", 4)
TEST_CASE("ABAB", 0)
TEST_CASE("CDCD", 0)
TEST_CASE("ABCDABCD", 0)

BUILD_PROBLEM;

#pragma once

#include <bits/stdc++.h>
#include "problem_runner.h"

// A parentheses string is valid if and only if:
// - It is the empty string,
// - It can be written as AB (A concatenated with B), where A and B are valid strings, or
// - It can be written as (A), where A is a valid string.
//
// Given a parentheses string s, return the minimum number of parentheses we must add
// to make it valid.

inline int32_t solve(const std::string& s) {
    int32_t open = 0;
    int32_t close = 0;
    for (auto c : s) {
        if (c == '(') {
            ++open;
        } else if (open > 0) {
            --open;
        } else {
            ++close;
        }
    }

    return open + close;
}

DEFINE_PROBLEM(MinimumAddToMakeParenthesesValid, std::string, int32_t) {
    const std::string& s = input;
    return solve(input);
})

TEST_CASE("())", 1)
TEST_CASE("(((", 3)
TEST_CASE("", 0)
TEST_CASE("()())", 1)
TEST_CASE("((())", 1)
TEST_CASE("))()", 2)

BUILD_PROBLEM;

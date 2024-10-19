#pragma once

#include <bits/stdc++.h>
#include "problem_runner.h"

inline bool solve(const std::string& s1, const std::string& s2) {
    return ((s1[0] == s2[0] && s1[2] == s2[2]) || (s1[0] == s2[2] && s1[2] == s2[0])) &&
           ((s1[1] == s2[1] && s1[3] == s2[3]) || (s1[1] == s2[3] && s1[3] == s2[1]));
}

DEFINE_PROBLEM(CheckIfStringsCanBeMadeEqualWithOperationsI, L(std::pair<std::string, std::string>), bool) {
    const auto& [s1, s2] = input;
    return solve(s1, s2);
})

TEST_CASE(L({"abcd", "cdab"}), true)
TEST_CASE(L({"abcd", "dacb"}), false)

BUILD_PROBLEM;

#pragma once

#include <bits/stdc++.h>
#include "../problem_runner.h"

// Given a positive integer num represented as a string, return the integer num without trailing zeros as a string.

DEFINE_PROBLEM(RemoveTrailingZeros, std::string, std::string) {
    size_t size = input.size();
    while (size > 1 && input[size - 1] == '0') --size;
    return { input.c_str(), size };
})

TEST_CASE("51230100", "512301")
TEST_CASE("123", "123")
TEST_CASE("1000", "1")
TEST_CASE("100100", "1001")
TEST_CASE("1", "1")

BUILD_PROBLEM;
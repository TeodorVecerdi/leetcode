#pragma once

#include <bits/stdc++.h>
#include "../problem_runner.h"

// Given an integer num, return a string of its base 7 representation.

DEFINE_PROBLEM(Base7, int, std::string) {
    if (input == 0)
        return "0";

    char buffer[16];
    size_t i = 0;

    int32_t n = std::abs(input);
    while (n != 0) {
        buffer[16 - i++ - 1] = (n % 7) + '0';
        n /= 7;
    }

    if (input < 0) {
        buffer[16 - i++ - 1] = '-';
    }

    return std::string(buffer + 16 - i, i);
})

TEST_CASE(100, "202")
TEST_CASE(-7, "-10")
TEST_CASE(0, "0")
TEST_CASE(42, "60")
TEST_CASE(-42, "-60")
TEST_CASE(1000000, "11333311")

BUILD_PROBLEM;
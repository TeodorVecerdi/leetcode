#pragma once

#include <bits/stdc++.h>
#include "../problem_runner.h"

DEFINE_PROBLEM(ConvertNumberToHexadecimal, int, std::string) {
    if (input == 0) return "0";

    uint32_t n = input;
    char hex[8];
    int i = 0;
    while(n != 0) {
        const char rem = static_cast<char>(n % 16);
        hex[8 - i++ - 1] = rem < 10 ? rem + '0' : rem - 10 + 'a';
        n /= 16;
    }

    return std::string(hex + 8 - i, i);
})
TEST_CASE(26, "1a")
TEST_CASE(0, "0")
TEST_CASE(-1, "ffffffff")
BUILD_PROBLEM;

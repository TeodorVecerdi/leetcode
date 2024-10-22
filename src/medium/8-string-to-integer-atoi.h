#pragma once

#include <bits/stdc++.h>
#include "problem_runner.h"

inline int32_t solve(std::string_view input) {
    // Skip leading whitespace
    while (!input.empty() && input[0] == ' ')
        input.remove_prefix(1);

    if (input.empty() || (input[0] != '-' && input[0] != '+' && !std::isdigit(input[0])))
        return 0;

    // Get sign
    const bool negative = input[0] == '-';
    if (input[0] == '-' || input[0] == '+')
        input.remove_prefix(1);

    if (input.empty() || !std::isdigit(input[0]))
        return 0;

    // Find end of number
    size_t end = 0;
    while (end < input.size() && std::isdigit(input[end]))
        end++;

    // Convert to integer
    constexpr int32_t max = std::numeric_limits<int32_t>::max();
    constexpr int32_t min = std::numeric_limits<int32_t>::min();

    int32_t result = 0;
    for (size_t i = 0; i < end; i++) {
        const int32_t digit = input[i] - '0';

        // Check for overflow
        if (result > (max - digit) / 10)
            return negative ? min : max;

        result *= 10;
        result += digit;
    }

    return negative ? -result : result;
}

DEFINE_PROBLEM(StringToIntegerAtoi, std::string, int32_t) {
    return solve(input);
})

TEST_CASE("42", 42)
TEST_CASE(" -042", -42)
TEST_CASE("1337c0d3", 1337)
TEST_CASE("0-1", 0)
TEST_CASE("words and 987", 0)
TEST_CASE("-91283472332", -2147483648)

BUILD_PROBLEM;

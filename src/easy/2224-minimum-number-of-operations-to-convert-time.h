#pragma once

#include <bits/stdc++.h>
#include "problem_runner.h"

inline std::pair<int, int> parseTime(const std::string& time) {
    return {10 * (time[0] - '0') + (time[1] - '0'), 10 * (time[3] - '0') + (time[4] - '0')};
}

inline size_t solve(const std::string& start, const std::string& end) {
    if (start == end)
        return 0;

    const auto [startHour, startMinutes] = parseTime(start);
    const auto [endHour, endMinutes] = parseTime(end);

    size_t operations = endHour - startHour;
    size_t remainingTime = endMinutes - startMinutes;
    if (endMinutes < startMinutes) {
        operations--;
        remainingTime += 60;
    }

    while (remainingTime != 0) {
        ++operations;

        if (remainingTime >= 15) {
            remainingTime -= 15;
        } else if (remainingTime >= 5) {
            remainingTime -= 5;
        } else {
            remainingTime -= 1;
        }
    }

    return operations;
}

DEFINE_PROBLEM(MinimumNumberOfOperationsToConvertTime, L(std::pair<std::string, std::string>), size_t) {
    const auto [start, end] = input;
    return solve(start, end);
})

TEST_CASE(L({"02:30", "04:35"}), 3)
TEST_CASE(L({"11:00", "11:01"}), 1)
TEST_CASE(L({"12:00", "12:00"}), 0)
TEST_CASE(L({"04:45", "05:15"}), 2)

BUILD_PROBLEM;

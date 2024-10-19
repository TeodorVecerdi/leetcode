#pragma once

#include <bits/stdc++.h>
#include "problem_runner.h"

inline bool solve(std::vector<int32_t>& nums) {
    int32_t maxValue = -1;
    int32_t maxValueOccurrences = 0;
    for (const auto num: nums) {
        if (num > maxValue) {
            if (maxValueOccurrences > 1)
                return false;
            maxValue = num;
            maxValueOccurrences = 1;
        } else if (num == maxValue) {
            maxValueOccurrences++;
        }
    }

    if (maxValueOccurrences != 2 || maxValue != nums.size() - 1)
        return false;

    std::ranges::sort(nums);
    for (size_t i = 0; i < nums.size() - 1; ++i)
        if (nums[i] != i + 1)
            return false;

    return true;
}

DEFINE_PROBLEM(CheckIfArrayIsGood, std::vector<int32_t>, bool) {
    return solve(const_cast<std::vector<int32_t>&>(input));
})

TEST_CASE(L({2, 1, 3}), false)
TEST_CASE(L({1, 3, 3, 2}), true)
TEST_CASE(L({1, 1}), true)
TEST_CASE(L({3, 4, 4, 1, 2, 1}), false)

BUILD_PROBLEM;

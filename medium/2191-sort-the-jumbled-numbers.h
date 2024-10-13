#pragma once

#include <bits/stdc++.h>
#include "problem_runner.h"

inline int32_t convert(int32_t num, const std::vector<int32_t>& mapping) {
    if (num == 0) {
        return mapping[0];
    }

    int32_t result = 0;
    int32_t multiplier = 1;
    while (num > 0) {
        result += mapping[num % 10] * multiplier;
        multiplier *= 10;
        num /= 10;
    }

    return result;
}

inline std::vector<int32_t> solve(const std::vector<int32_t>& mapping, const std::vector<int32_t>& nums) {
    std::vector<std::pair<int32_t, int32_t>> converted_nums;
    converted_nums.reserve(nums.size());
    for (size_t i = 0; i < nums.size(); ++i) {
        const int32_t num = nums[i];
        converted_nums.emplace_back(convert(num, mapping), i);
    }

    std::ranges::sort(converted_nums);

    std::vector<int32_t> result;
    result.reserve(nums.size());
    for (const auto& [_, i] : converted_nums) {
        result.push_back(nums[i]);
    }

    return result;
}

DEFINE_PROBLEM(SortTheJumbledNumbers, L(std::pair<std::vector<int32_t>, std::vector<int32_t>>), std::vector<int32_t>) {
    const auto [mapping, nums] = input;
    return solve(mapping, nums);
})

TEST_CASE(L({{8,9,4,0,2,1,3,5,7,6}, {991,338,38}}), L({338,38,991}))
TEST_CASE(L({{0,1,2,3,4,5,6,7,8,9}, {789,456,123}}), L({123,456,789}))
TEST_CASE(L({{9,8,7,6,5,4,3,2,1,0}, {0,1,2,3,4,5,6,7,8,9}}), L({9,8,7,6,5,4,3,2,1,0}))

BUILD_PROBLEM;

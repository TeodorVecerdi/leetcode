#pragma once

#include <bits/stdc++.h>
#include "problem_runner.h"

inline size_t solve(const std::vector<int32_t>& nums, int32_t k) {
    if (nums.empty()) return 0;

    size_t score = 0;
    std::priority_queue queue(nums.begin(), nums.end());
    while(k != 0) {
        --k;

        const auto num = queue.top();
        if (num == 1) {
            score += k + 1;
            break;
        }

        queue.pop();
        queue.push((num + 2) / 3);

        score += num;
    }

    return score;
}

DEFINE_PROBLEM(MaximalScoreAfterApplyingKOperations, L(std::pair<std::vector<int32_t>, int32_t>), size_t) {
    const auto& [nums, k] = input;
    return solve(nums, k);
})

TEST_CASE(L({{10,10,10,10,10}, 5}), 50)
TEST_CASE(L({{1,10,3,3,3}, 3}), 17)
TEST_CASE(L({{1,1,1,1,1}, 3}), 3)

BUILD_PROBLEM;

#pragma once

#include <bits/stdc++.h>
#include "problem_runner.h"

inline std::string solve(int32_t a, int32_t b, int32_t c) {
    std::string result;

    std::priority_queue<std::pair<int, char>> queue;
    if (a) queue.emplace(a, 'a');
    if (b) queue.emplace(b, 'b');
    if (c) queue.emplace(c, 'c');

    while (!queue.empty()) {
        auto [count, ch] = queue.top();
        queue.pop();

        if (!result.empty() && result.back() == ch) {
            if (queue.empty()) {
                return result;
            }

            auto [nextCount, nextCh] = queue.top();
            queue.pop();
            result += nextCh;
            if (nextCount > 1) {
                queue.emplace(nextCount - 1, nextCh);
            }

            queue.emplace(count, ch);
            continue;
        }

        if (count >= 2) {
            result += ch;
            result += ch;
            count -= 2;
        } else {
            result += ch;
            count -= 1;
        }

        if (count > 0) {
            queue.emplace(count, ch);
        }
    }

    return result;
}

DEFINE_PROBLEM(LongestHappyString, L(std::tuple<int32_t, int32_t, int32_t>), size_t) {
    const auto& [a, b, c] = input;
    return solve(a, b, c).size();
})

TEST_CASE(L({1, 1, 7}), 8)
TEST_CASE(L({7, 1, 0}), 5)

BUILD_PROBLEM;

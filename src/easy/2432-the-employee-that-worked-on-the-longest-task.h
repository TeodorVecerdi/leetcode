#pragma once

#include <bits/stdc++.h>
#include "../problem_runner.h"

// There are n employees, each with a unique id from 0 to n - 1.
// You are given a 2D integer array logs where logs[i] = [idi, leaveTimei] indicates that the employee with idi worked on their ith task until time leaveTimei.
// Task i starts the moment right after the (i - 1)th task ends, and the 0th task starts at time 0.
// Return the id of the employee that worked the task with the longest time. If there is a tie, return the smallest id among them.

DEFINE_PROBLEM(LongestTaskEmployee, L(std::pair<int, std::vector<std::vector<int>>>), int) {
    const auto& [n, logs] = input;
    int32_t bestEmployee = logs[0][0];
    int32_t bestTime = logs[0][1];

    for(int32_t i = 1; i < logs.size(); ++i) {
        const int32_t time = logs[i][1] - logs[i-1][1];

        if(time > bestTime) {
            bestTime = time;
            bestEmployee = logs[i][0];
        } else if(time == bestTime) {
            bestEmployee = std::min(bestEmployee, logs[i][0]);
        }
    }

    return bestEmployee;
})

TEST_CASE(L({10, {{0,3},{2,5},{0,9},{1,15}}}), 1)
TEST_CASE(L({26, {{1,1},{3,7},{2,12},{7,17}}}), 3)
TEST_CASE(L({2, {{0,10},{1,20}}}), 0)
TEST_CASE(L({5, {{0,1},{1,2},{4,3},{3,4},{2,5}}}), 0)
TEST_CASE(L({3, {{0,5},{1,5},{2,5}}}), 0)

BUILD_PROBLEM;
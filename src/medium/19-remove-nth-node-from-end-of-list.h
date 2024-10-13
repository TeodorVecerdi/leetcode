#pragma once

#include <bits/stdc++.h>
#include "problem_runner.h"
#include "data/LinkedList.h"

using ListNode = LinkedList<int32_t>;

// Given the head of a linked list, remove the nth node from the end of the list and return its head.

inline ListNode* solve(ListNode* head, const int n) {
    ListNode dummy(0, head);
    ListNode* slow = &dummy;
    ListNode* fast = head;

    for (int i = 0; i < n; i++) {
        fast = fast->next;
    }

    while (fast != nullptr) {
        slow = slow->next;
        fast = fast->next;
    }

    ListNode* to_delete = slow->next;
    slow->next = slow->next->next;
    delete to_delete;

    return dummy.next;
}

DEFINE_PROBLEM(RemoveNthFromEnd, L(std::pair<std::vector<int>, int>), std::vector<int>) {
    const auto& [nums, n] = input;
    ListNode* head = ListNode::from_vector(nums);

    ListNode* result = solve(head, n);
    std::vector<int> output = ListNode::to_vector(result);

    ListNode::free(result);
    return output;
})

TEST_CASE(L({{1,2,3,4,5}, 2}), L({1,2,3,5}))
TEST_CASE(L({{1,2,3,4,5}, 5}), L({2,3,4,5}))
TEST_CASE(L({{1}, 1}), L({}))
TEST_CASE(L({{1,2}, 1}), L({1}))
TEST_CASE(L({{1,2}, 2}), L({2}))

BUILD_PROBLEM;

#pragma once

#include <bits/stdc++.h>
#include "problem_runner.h"
#include "data/LinkedList.h"

using ListNode = LinkedList<int32_t>;

inline ListNode* solve(const ListNode* l1, const ListNode* l2) {
    ListNode result;
    ListNode* current = &result;

    int32_t carry = 0;
    while (l1 || l2) {
        int32_t sum = carry;

        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;
        current->next = new ListNode(sum % 10);
        current = current->next;
    }

    if (carry) {
        current->next = new ListNode(carry);
    }

    return result.next;
}

DEFINE_PROBLEM(AddTwoNumbers, L(std::pair<std::vector<int>, std::vector<int>>), std::vector<int>) {
    const ListNode* l1 = ListNode::from_vector(input.first);
    const ListNode* l2 = ListNode::from_vector(input.second);

    const ListNode* result = solve(l1, l2);

    std::vector<int> output = ListNode::to_vector(result);

    ListNode::free(l1);
    ListNode::free(l2);
    ListNode::free(result);

    return output;
})

TEST_CASE(L({{2,4,3}, {5,6,4}}), L({7,0,8}))
TEST_CASE(L({{0}, {0}}), L({0}))
TEST_CASE(L({{9,9,9,9,9,9,9}, {9,9,9,9}}), L({8,9,9,9,0,0,0,1}))
TEST_CASE(L({{9,9,9,9}, {9,9,9,9,9,9,9}}), L({8,9,9,9,0,0,0,1}))

BUILD_PROBLEM;

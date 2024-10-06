#pragma once

#include <bits/stdc++.h>
#include "../problem_runner.h"

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;

    ListNode()
        : val(0), next(nullptr) {
    }

    explicit ListNode(int x)
        : val(x), next(nullptr) {
    }

    ListNode(int x, ListNode* next)
        : val(x), next(next) {
    }
};

// Function to build a linked list from a vector
inline ListNode* buildList(const std::vector<int>& nums) {
    ListNode dummy(0);
    ListNode* current = &dummy;
    for (const int num: nums) {
        current->next = new ListNode(num);
        current = current->next;
    }
    return dummy.next;
}

// Function to convert a linked list to a vector (for result checking)
inline std::vector<int> listToVector(const ListNode* head) {
    std::vector<int> result;
    while (head) {
        result.push_back(head->val);
        head = head->next;
    }
    return result;
}

// Function to delete the linked list (to prevent memory leaks)
inline void deleteList(const ListNode* head) {
    while (head) {
        const ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

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
    const ListNode* l1 = buildList(input.first);
    const ListNode* l2 = buildList(input.second);

    const ListNode* result = solve(l1, l2);

    std::vector<int> output = listToVector(result);

    deleteList(l1);
    deleteList(l2);
    deleteList(result);

    return output;
})

TEST_CASE(L({{2,4,3}, {5,6,4}}), L({7,0,8}))
TEST_CASE(L({{0}, {0}}), L({0}))
TEST_CASE(L({{9,9,9,9,9,9,9}, {9,9,9,9}}), L({8,9,9,9,0,0,0,1}))
TEST_CASE(L({{9,9,9,9}, {9,9,9,9,9,9,9}}), L({8,9,9,9,0,0,0,1}))

BUILD_PROBLEM;

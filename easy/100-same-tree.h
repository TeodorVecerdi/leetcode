#pragma once

#include <bits/stdc++.h>
#include "problem_runner.h"
#include "data/BTree.h"

// Given the roots of two binary trees p and q, write a function to check if they are the same or not.
// Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

inline bool solve(const BTreeNode<int32_t>* lhs, const BTreeNode<int32_t>* rhs) {
    if (lhs == nullptr && rhs == nullptr)
        return true;
    if (lhs == nullptr || rhs == nullptr)
        return false;
    if (lhs->val != rhs->val)
        return false;

    return solve(lhs->left, rhs->left) && solve(lhs->right, rhs->right);
}

DEFINE_PROBLEM(SameTree, L(std::pair<std::vector<std::optional<int>>, std::vector<std::optional<int>>>), bool) {
    BTreeNode<int32_t>* p = BTreeNode<int32_t>::create(input.first);
    BTreeNode<int32_t>* q = BTreeNode<int32_t>::create(input.second);

    const bool result = solve(p, q);

    BTreeNode<int32_t>::free(p);
    BTreeNode<int32_t>::free(q);
    return result;
})

TEST_CASE(L({{1,2,3}, {1,2,3}}), true)
TEST_CASE(L({{1,2}, {1,std::nullopt,2}}), false)
TEST_CASE(L({{1,2,1}, {1,1,2}}), false)

BUILD_PROBLEM;

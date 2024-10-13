#pragma once

#include <bits/stdc++.h>
#include "data/BinaryTree.h"
#include "problem_runner.h"

DEFINE_PROBLEM(RootEqualsSumOfChildren, std::vector<std::optional<int>>, bool) {
    BinaryTree<int32_t>* root = BinaryTree<int32_t>::create(input);
    const bool result = root->val == root->left->val + root->right->val;
    BinaryTree<int32_t>::free(root);
    return result;
})

TEST_CASE(L({10,4,6}), true)
TEST_CASE(L({5,3,1}), false)

BUILD_PROBLEM;

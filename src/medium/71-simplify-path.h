#pragma once

#include <bits/stdc++.h>
#include "../problem_runner.h"

// Given an absolute path for a Unix-style file system, simplify it to its canonical form.
// Rules:
// 1. The path starts with a single slash '/'.
// 2. Any two directories are separated by a single slash '/'.
// 3. The path does not end with a trailing '/' unless it's the root directory.
// 4. The path only contains the directories on the path from the root directory to the target file or directory

inline std::string canonicalize(const std::string& path) {
    std::stack<std::string_view> stack;
    std::string_view view(path);

    while (!view.empty()) {
        const size_t nextSlash = view.find('/');
        std::string_view token;

        if (nextSlash == std::string_view::npos) {
            token = view;
            view = {};
        } else {
            token = view.substr(0, nextSlash);
            view = view.substr(nextSlash + 1);
        }

        if (token.empty() || token == ".")
            continue;

        if (token == "..") {
            if (!stack.empty())
                stack.pop();
            continue;
        }

        stack.push(token);
    }

    if (stack.empty())
        return "/";

    std::string result;
    while (!stack.empty()) {
        result.insert(0, "/").insert(1, stack.top());
        stack.pop();
    }

    return result;
}

DEFINE_PROBLEM(SimplifyPath, std::string, std::string) {
    return canonicalize(input);
})

TEST_CASE("/home/", "/home")
TEST_CASE("/home//foo/", "/home/foo")
TEST_CASE("/home/user/Documents/../Pictures", "/home/user/Pictures")
TEST_CASE("/..", "/")
TEST_CASE("/../", "/")
TEST_CASE("/...////a/./b/../../c/../d/", "/.../d")
TEST_CASE("/.../a/../b/c/../d/./", "/.../b/d")

BUILD_PROBLEM;

﻿#pragma once

// # 1096. Brace Expansion II
//
// Under the grammar given below, strings can represent a set of lowercase words. Let `R(expr)` denote the set of words the expression represents.
//
// The grammar can best be understood through simple examples:
//
// - Single letters represent a singleton set containing that word.
//   - `R("a") = {"a"}`
//   - `R("w") = {"w"}`
//
// - When we take a comma-delimited list of two or more expressions, we take the union of possibilities.
//   - `R("{a,b,c}") = {"a", "b", "c"}`
//   - `R("{a,b},{b,c}") = {"a", "b", "c"}` (notice the final set only contains each word at most once)
//
// - When we concatenate two expressions, we take the set of possible concatenations between two words where the first word comes from the first expression and the second word comes from the second expression.
//   - `R("{a,b}{c,d}") = {"ac", "ad", "bc", "bd"}`
//   - `R("a{b,c}{d,e}f{g,h}") = {"abdfg", "abdfh", "abefg", "abefh", "acdfg", "acdfh", "acefg", "acefh"}`
//
// Formally, the three rules for our grammar:
//
// - For every lowercase letter `x`, we have `R(x) = {x}`.
// - For expressions `e1, e2, ..., ek` with `k &gt;= 2`, we have `R({e1, e2, ..., ek}) = R(e1) U R(e2) U ...`.
// - For expressions `e1` and `e2`, we have `R(e1 + e2) = {a + b for (a, b) in R(e1) x R(e2)}`, where `+` denotes concatenation, and `x` denotes the cartesian product.
//
// Given an expression representing a set of words under the given grammar, return the sorted list of words that the expression represents.
//
// ## Example 1:
//
// **Input:** expression = "{a,b}{c,{d,e}}"
//
// **Output:** ["ac","ad","ae","bc","bd","be"]
//
// ## Example 2:
//
// **Input:** expression = "{a,z},a{b,c},{ab,z}"
//
// **Output:** ["a","ab","ac","z"]
//
// **Explanation:** Each distinct word is written only once in the final answer.

#include <bits/stdc++.h>

#include "../problem_runner.h"

enum class OperationKind {
    Union,
    Concatenation
};

enum class TokenType {
    Letter,
    OpenBracket,
    CloseBracket
};

struct Token {
    TokenType type;
    char letter;
};

struct Operation {
    OperationKind kind;
    std::vector<std::variant<std::string, std::shared_ptr<Operation>>> operands;
};

class Tokenizer {
public:
    explicit Tokenizer(const std::string_view expression) :
        expression(expression) {}

    [[nodiscard]] std::vector<Token> tokenize() const {
        std::vector<Token> tokens;
        for (const char &i: expression) {
            if (i == '{') {
                tokens.push_back({TokenType::OpenBracket, 0});
            } else if (i == '}') {
                tokens.push_back({TokenType::CloseBracket, 0});
            } else {
                tokens.push_back({TokenType::Letter, i});
            }
        }
        return tokens;
    }

private:
    std::string_view expression;
};

class Parser {
public:
    explicit Parser(const std::vector<Token> &tokens) :
        tokens(tokens) {}

    [[nodiscard]] std::shared_ptr<Operation> parse() {
        return parseOperation(0, tokens.size());
    }

private:
    int index = 0;
    const std::vector<Token> &tokens;

    [[nodiscard]] Token peek() const {
        return tokens[index];
    }

    Token consume() {
        return tokens[index++];
    }

    Token consume(TokenType type) {
        if (peek().type != type) {
            throw std::runtime_error("Unexpected token");
        }

        return consume();
    }

    std::shared_ptr<Operation> parseOperation
};

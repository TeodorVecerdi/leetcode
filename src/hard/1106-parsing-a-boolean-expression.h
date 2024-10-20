#pragma once

#include <bits/stdc++.h>
#include "problem_runner.h"

inline bool solve(const std::string& expression);

DEFINE_PROBLEM(ParsingABooleanExpression, std::string, bool) {
    return solve(input);
})

TEST_CASE("&(|(f))", false)
TEST_CASE("|(f,f,f,t)", true)
TEST_CASE("!(&(f,t))", true)

BUILD_PROBLEM;

class Expression {
public:
    virtual ~Expression() = default;
    [[nodiscard]] virtual bool evaluate() const = 0;
};

class ConstantExpression final : public Expression {
public:
    explicit ConstantExpression(const bool value)
        : m_Value(value) {
    }

    [[nodiscard]] bool evaluate() const override { return m_Value; }

private:
    bool m_Value;
};

class NotExpression final : public Expression {
public:
    explicit NotExpression(std::unique_ptr<Expression> expression)
        : m_Expression(std::move(expression)) {
    }

    [[nodiscard]] bool evaluate() const override { return !m_Expression->evaluate(); }

private:
    std::unique_ptr<Expression> m_Expression;
};

class AndExpression final : public Expression {
public:
    explicit AndExpression(std::vector<std::unique_ptr<Expression>> expressions)
        : m_Expressions(std::move(expressions)) {
    }

    [[nodiscard]] bool evaluate() const override {
        for (const auto& expression: m_Expressions) {
            if (!expression->evaluate()) {
                return false;
            }
        }

        return true;
    }

private:
    std::vector<std::unique_ptr<Expression>> m_Expressions;
};

class OrExpression final : public Expression {
public:
    explicit OrExpression(std::vector<std::unique_ptr<Expression>> expressions)
        : m_Expressions(std::move(expressions)) {
    }

    [[nodiscard]] bool evaluate() const override {
        for (const auto& expression: m_Expressions) {
            if (expression->evaluate()) {
                return true;
            }
        }

        return false;
    }

private:
    std::vector<std::unique_ptr<Expression>> m_Expressions;
};

class Parser {
public:
    explicit Parser(const std::string& expression)
        : m_Expression(expression) {
    }

    std::unique_ptr<Expression> parse() {
        return parse_expression();
    }

private:
    std::unique_ptr<Expression> parse_expression() {
        if (peek('t') || peek('f'))
            [[likely]] return std::make_unique<ConstantExpression>(parse_constant());
        if (peek('!'))
            return std::make_unique<NotExpression>(parse_not());
        if (peek('&'))
            return std::make_unique<AndExpression>(parse_and());
        if (peek('|'))
            return std::make_unique<OrExpression>(parse_or());

        throw std::runtime_error(std::format("Unexpected character: {}", peek()));
    }

    AndExpression parse_and() {
        consume('&');
        consume('(');
        auto expressions = parse_expression_list();
        consume(')');
        return AndExpression(std::move(expressions));
    }

    OrExpression parse_or() {
        consume('|');
        consume('(');
        auto expressions = parse_expression_list();
        consume(')');
        return OrExpression(std::move(expressions));
    }

    NotExpression parse_not() {
        consume('!');
        consume('(');
        auto expression = parse_expression();
        consume(')');
        return NotExpression(std::move(expression));
    }

    ConstantExpression parse_constant() {
        const bool value = peek('t');
        ++m_Index;
        return ConstantExpression(value);
    }

    std::vector<std::unique_ptr<Expression>> parse_expression_list() {
        std::vector<std::unique_ptr<Expression>> expressions;
        while (peek() != ')') {
            expressions.push_back(parse_expression());
            if (!try_consume(',')) {
                break;
            }
        }

        return expressions;
    }

    [[nodiscard]] char peek() const {
        return m_Index < m_Expression.size() ? m_Expression[m_Index] : '\0';
    }

    [[nodiscard]] bool peek(const char expected) const {
        return peek() == expected;
    }

    bool try_consume(const char expected) {
        if (peek(expected)) {
            ++m_Index;
            return true;
        }

        return false;
    }

    void consume(const char expected) {
        if (m_Index < m_Expression.size() && m_Expression[m_Index] == expected) {
            ++m_Index;
            return;
        }

        throw std::runtime_error("Unexpected character");
    }

private:
    size_t m_Index{};
    const std::string& m_Expression;
};

inline bool solve(const std::string& expression) {
    return Parser(expression).parse()->evaluate();
}

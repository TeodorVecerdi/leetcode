#pragma once

#include <chrono>
#include <functional>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "stream_operators.h"

template<typename Input, typename Output>
class ProblemBuilder;

template<typename Input, typename Output>
class Problem {
private:
    friend class ProblemBuilder<Input, Output>;

    using SolutionFunc = std::function<Output(const Input&)>;

    struct TestCase {
        Input input;
        Output expected_output;
        std::string input_str;
        std::string output_str;
    };

    Problem(std::string name, SolutionFunc solution)
        : name(std::move(name)), solution(std::move(solution)) {
    }

    void addTestCase(Input&& input, Output&& expected_output, const char* input_str, const char* output_str) {
        test_cases.emplace_back(std::move(input), std::move(expected_output), input_str, output_str);
    }

    std::string name;
    SolutionFunc solution;
    std::vector<TestCase> test_cases;

public:
    void run() const {
        std::cout << "Running problem: " << name << std::endl;
        size_t passed = 0;
        double total_time = 0;

        for (size_t i = 0; i < test_cases.size(); ++i) {
            const auto& test_case = test_cases[i];
            std::cout << "Test case " << (i + 1) << ": ";

            auto start_time = std::chrono::high_resolution_clock::now();
            Output result = solution(test_case.input);
            auto end_time = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double, std::milli> duration = end_time - start_time;

            total_time += duration.count();

            if (result == test_case.expected_output) {
                std::cout << "PASSED (Time: " << duration.count() << " ms)\n";
                std::cout << "  Input:           " << test_case.input_str << "\n";
                std::cout << "  Output:          " << result << "\n";
                ++passed;
            } else {
                std::cout << "FAILED (Time: " << duration.count() << " ms)\n";
                std::cout << "  Input:           " << test_case.input_str << "\n";
                std::cout << "  Expected output: " << test_case.output_str << "\n";
                std::cout << "  Actual output:   " << result << "\n";
            }
        }

        std::cout << "\nResults: " << passed << "/" << test_cases.size() << " tests passed." << std::endl;
        std::cout << "Average time: " << (total_time / test_cases.size()) << " ms" << std::endl;
    }
};

template<typename Input, typename Output>
class ProblemBuilder {
public:
    ProblemBuilder(const std::string& name, typename Problem<Input, Output>::SolutionFunc solution)
        : problem(name, std::move(solution)) {
    }

    ProblemBuilder& addTestCase(Input&& input, Output&& expected_output, const char* input_str, const char* output_str) {
        problem.addTestCase(std::move(input), std::move(expected_output), input_str, output_str);
        return *this;
    }

    Problem<Input, Output> build() {
        return std::move(problem);
    }

private:
    Problem<Input, Output> problem;
};

#define DEFINE_PROBLEM(ProblemName, InputType, OutputType)           \
    inline auto ProblemName = ProblemBuilder<InputType, OutputType>( \
        #ProblemName, \
        [](const InputType& input) -> OutputType

#define TEST_CASE(Input, ExpectedOutput) \
    .addTestCase(Input, ExpectedOutput, S(Input), S(ExpectedOutput))

#define BUILD_PROBLEM \
    .build()

#define L(...) __VA_ARGS__

#define S(...) #__VA_ARGS__

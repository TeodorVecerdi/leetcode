
cmake_minimum_required(VERSION 3.29)
project(leetcode)

set(CMAKE_CXX_STANDARD 20)

add_executable(leetcode main.cpp
        easy/1046-last-stone-weight.h
        problem_runner.h
        easy/example.h
        hard/1096-brace-expansion-ii.h
        easy/405-convert-a-number-to-hexadecimal.h
)

if (WIN32)
    target_link_libraries(leetcode psapi)
endif ()
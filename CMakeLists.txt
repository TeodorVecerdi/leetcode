
cmake_minimum_required(VERSION 3.29)
project(leetcode)

set(CMAKE_CXX_STANDARD 20)

add_executable(leetcode main.cpp
        easy/1046-last-stone-weight.h
        problem_runner.h
        hard/1096-brace-expansion-ii.h
        easy/405-convert-a-number-to-hexadecimal.h
        easy/383-ransom-note.h
        easy/504-base-7.h
        easy/543-diameter-of-binary-tree.h
        medium/2-add-two-numbers.h
        stream_operators.h
        hard/2366-minimum-replacements-to-sort-the-array.h
        easy/2710-remove-trailing-zeros-from-a-string.h
        easy/2347-best-poker-hand.h
        easy/2515-shortest-distance-to-target-string-in-a-circular-array.h
        easy/2432-the-employee-that-worked-on-the-longest-task.h
        medium/71-simplify-path.h
)

if (WIN32)
    target_link_libraries(leetcode psapi)
endif ()
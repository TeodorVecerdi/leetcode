
cmake_minimum_required(VERSION 3.29)
project(leetcode)

set(CMAKE_CXX_STANDARD 20)

include_directories(${CMAKE_SOURCE_DIR})

add_executable(leetcode main.cpp
        problem_runner.h
        stream_operators.h
        data/BinaryTree.h
        data/LinkedList.h
        easy/383-ransom-note.h
        easy/405-convert-a-number-to-hexadecimal.h
        easy/504-base-7.h
        easy/543-diameter-of-binary-tree.h
        easy/821-shortest-distance-to-a-character.h
        easy/1046-last-stone-weight.h
        easy/2236-root-equals-sum-of-children.h
        easy/2347-best-poker-hand.h
        easy/2432-the-employee-that-worked-on-the-longest-task.h
        easy/2515-shortest-distance-to-target-string-in-a-circular-array.h
        easy/2696-minimum-string-length-after-removing-substrings.h
        easy/2710-remove-trailing-zeros-from-a-string.h
        easy/100-same-tree.h
        easy/191-number-of-1-bits.h
        medium/2-add-two-numbers.h
        medium/19-remove-nth-node-from-end-of-list.h
        medium/71-simplify-path.h
        medium/116-populating-next-right-pointers-in-each-node.h
        medium/151-reverse-words-in-a-string.h
        medium/921-minimum-add-to-make-parentheses-valid.h
        medium/1864-minimum-number-of-swaps-to-make-the-binary-string-alternating.h
        medium/1963-minimum-number-of-swaps-to-make-the-string-balanced.h
        hard/1096-brace-expansion-ii.h
        hard/2366-minimum-replacements-to-sort-the-array.h
)

if (WIN32)
    target_link_libraries(leetcode psapi)
endif ()
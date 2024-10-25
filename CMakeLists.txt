
cmake_minimum_required(VERSION 3.29)
project(leetcode)

set(CMAKE_CXX_STANDARD 20)

include_directories(${CMAKE_SOURCE_DIR}/src)

add_executable(leetcode src/main.cpp
        src/problem_runner.h
        src/stream_operators.h
        src/template.h
        src/data/BinaryTree.h
        src/data/LinkedList.h
        src/easy/100-same-tree.h
        src/easy/191-number-of-1-bits.h
        src/easy/217-contains-duplicate.h
        src/easy/383-ransom-note.h
        src/easy/405-convert-a-number-to-hexadecimal.h
        src/easy/504-base-7.h
        src/easy/543-diameter-of-binary-tree.h
        src/easy/821-shortest-distance-to-a-character.h
        src/easy/1046-last-stone-weight.h
        src/easy/2068-check-whether-two-strings-are-almost-equivalent.h
        src/easy/2169-count-operations-to-obtain-zero.h
        src/easy/2185-counting-words-with-a-given-prefix.h
        src/easy/2206-divide-array-into-equal-pairs.h
        src/easy/2224-minimum-number-of-operations-to-convert-time.h
        src/easy/2236-root-equals-sum-of-children.h
        src/easy/2335-minimum-amount-of-time-to-fill-cups.h
        src/easy/2347-best-poker-hand.h
        src/easy/2379-minimum-recolors-to-get-k-consecutive-black-blocks.h
        src/easy/2432-the-employee-that-worked-on-the-longest-task.h
        src/easy/2515-shortest-distance-to-target-string-in-a-circular-array.h
        src/easy/2696-minimum-string-length-after-removing-substrings.h
        src/easy/2710-remove-trailing-zeros-from-a-string.h
        src/easy/2784-check-if-array-is-good.h
        src/easy/2806-account-balance-after-rounded-purchase.h
        src/easy/2839-check-if-strings-can-be-made-equal-with-operations-i.h
        src/medium/2-add-two-numbers.h
        src/medium/3-longest-substring-without-repeating-characters.h
        src/medium/7-reverse-integer.h
        src/medium/8-string-to-integer-atoi.h
        src/medium/19-remove-nth-node-from-end-of-list.h
        src/medium/71-simplify-path.h
        src/medium/116-populating-next-right-pointers-in-each-node.h
        src/medium/151-reverse-words-in-a-string.h
        src/medium/670-maximum-swap.h
        src/medium/921-minimum-add-to-make-parentheses-valid.h
        src/medium/1405-longest-happy-string.h
        src/medium/1864-minimum-number-of-swaps-to-make-the-binary-string-alternating.h
        src/medium/1963-minimum-number-of-swaps-to-make-the-string-balanced.h
        src/medium/2125-number-of-laser-beams-in-a-bank.h
        src/medium/2191-sort-the-jumbled-numbers.h
        src/medium/2530-maximal-score-after-applying-k-operations.h
        src/medium/2583-kth-largest-sum-in-a-binary-tree.h
        src/medium/2641-cousins-in-binary-tree-ii.h
        src/medium/2938-separate-black-and-white-balls.h
        src/medium/3096-minimum-levels-to-gain-more-points.h
        src/hard/1096-brace-expansion-ii.h
        src/hard/1106-parsing-a-boolean-expression.h
        src/hard/2366-minimum-replacements-to-sort-the-array.h
)

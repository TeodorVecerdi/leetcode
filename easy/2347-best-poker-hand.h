#pragma once

#include <bits/stdc++.h>
#include "../problem_runner.h"

// You are given an integer array ranks and a character array suits. You have 5 cards where the i^th card has a rank of ranks[i] and a suit of suits[i].
// Return a string representing the best type of poker hand you can make with the given cards.
// The types of poker hands are, from best to worst: "Flush", "Three of a Kind", "Pair", "High Card".

DEFINE_PROBLEM(BestPokerHand, L(std::pair<std::vector<int>, std::vector<char>>), std::string) {
    const auto& [ranks, suits] = input;

    std::array<int, 5> suitOccurrences = {};
    std::array<int, 14> rankOccurrences = {};
    int maxRank = 0, maxSuit = 0;

    for (const auto& suit : suits) {
        maxSuit = std::max(maxSuit, ++suitOccurrences[suit - 'a']);
    }

    for (const auto& rank : ranks) {
        maxRank = std::max(maxRank, ++rankOccurrences[rank]);
    }

    if (maxSuit == 5) return "Flush";
    if (maxRank >= 3) return "Three of a Kind";
    if (maxRank == 2) return "Pair";
    return "High Card";
})

TEST_CASE(L({{13,2,3,1,9}, {'a','a','a','a','a'})}, "Flush")
TEST_CASE(L({{4,4,2,4,4}, {'d','a','a','b','c'}}), "Three of a Kind")
TEST_CASE(L({{10,10,2,12,9}, {'a','b','c','a','d'}}), "Pair")
TEST_CASE(L({{13,2,3,4,5}, {'a','b','c','d','e'}}), "High Card")
TEST_CASE(L({{1,1,1,1,1}, {'a','b','c','d','e'}}), "Three of a Kind")

BUILD_PROBLEM;

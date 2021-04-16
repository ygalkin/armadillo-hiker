#pragma once

#include <vector>
#include <algorithm>
#include <bitset>
#include <iostream>
#include <unordered_set>

namespace hackerrank {

    // https://www.hackerrank.com/challenges/sock-merchant/problem
    class sales_by_match {
    public:
        sales_by_match() = default;
        sales_by_match(const sales_by_match& other) = default;
        sales_by_match& operator = (const sales_by_match& other) = default;
        ~sales_by_match() = default;

        // Time complexity O(n) - linear. Using std::bitset
        int sock_merchant_bitset(int n, const std::vector<int>& ar) {
            std::bitset<100> s;
            auto pairs{ 0 };

            std::for_each(std::begin(ar), std::end(ar), [&s, &pairs](auto i) {
                if (s.test((size_t)i - 1)) {
                    ++pairs;
                }
                s.flip((size_t)i - 1);
                });

            return pairs;
        }

        // Time complexity O(n) - linear. Using std::unordered_set
        int sock_merchant_set(int n, const std::vector<int>& ar) {
            std::unordered_set<int> s;
            auto pairs{ 0 };

            for (const auto& i : ar) {
                if (s.find(i) == std::end(s)) {
                    s.insert(i);
                }
                else {
                    s.erase(i);
                    ++pairs;
                }
            }

            return pairs;
        }
    };
}
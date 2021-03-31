#pragma once

#include "helper.h"

#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <iostream>
#include <array>
#include <unordered_set>

class Test {
public:
    static void swap_xor(int& a, int& b) {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }

    // Time complexity: O(n/2)
    static bool is_palindrome(const std::string str) {
        const size_t len{ str.length() };

        for (size_t i = 0; i < len / 2; ++i) {
            if (str[i] != str[len - i - 1]) {
                return false;
            }
        }

        return true;
    }

    //    template <typename T>
    //    static T factorial_T(T n) {
    //        return n == 1 ? 1 : n * factorial_T<T>(n - 1);
    //    }

    // Time compexity: O(n) - linear
    static unsigned int factorial_recursion(unsigned int n) {
        return n == 1 ? 1 : n * factorial_recursion(n - 1);
    }

    // Time complexity: O(1) - constant
    // Gauss formula
    template <typename T>
    static inline T sum_formula(T n) {
        return (n * (n + 1)) / 2;
    }

    // Time complexity: O(n) - linear
    template <typename T>
    static T sum_recursion(T n) {
        return n == 1 ? 1 : n + sum_recursion(n - 1);
    }

    static void money(unsigned int m) {
        const unsigned int arr[]{ 25, 10, 5, 1 };

        auto i{ 0 };

        while (m > 0) {
            auto s{ (m / arr[i]) };
            m -= arr[i] * s;

            std::cout << s << ":" << arr[i];
            ++i;
        }
    }

    static unsigned int bit_count(unsigned int n) {
        auto count{ 0 };

        while (n > 0) {
            count += (n & 1);
            n >>= 1;
        }

        return count;
    }

    static void run() {
        std::cout << "-- Test if string is palindrome ---" << std::endl;
        std::vector<std::string> pal_strs{ "12321", "hello" };
        std::for_each(std::begin(pal_strs), std::end(pal_strs), [](auto i) {
            std::cout << i << " -> ";
            std::cout << (Test::is_palindrome(i) ? "Yes" : "No") << std::endl;
            });

        std::cout << "-- n! recursion ---" << std::endl;
        std::cout << Test::factorial_recursion(5) << std::endl;

        std::cout << "-- Remove duplicates in array (using hash set) ---" << std::endl;
        std::unordered_set<int> dup_set{ 1, 2, 3, 3, 5 };
        helper::out_each(std::cout, dup_set) << std::endl;

        std::cout << "-- Sum (formula) ---" << std::endl;
        std::cout << "Sum: " << Test::sum_formula(100) << std::endl;

        std::cout << "-- Sum (recursion) ---" << std::endl;
        std::cout << "Sum: " << Test::sum_recursion(100) << std::endl;

        std::cout << "-- Money task ---" << std::endl;
        Test::money(100);
        std::cout << std::endl;

        std::cout << "-- Number of bits 1 in number ---" << std::endl;
        std::cout << Test::bit_count(255) << std::endl;

        std::cout << "-- Swap two numbers (using XOR) ---" << std::endl;
        int a1{ 5 };
        int b1{ 8 };
        std::cout << "Before swap: " << a1 << " " << b1 << std::endl;
        Test::swap_xor(a1, b1);
        std::cout << "After swap: " << a1 << " " << b1 << std::endl;
    }
};


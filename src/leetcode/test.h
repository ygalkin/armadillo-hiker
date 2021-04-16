#pragma once

#include "two-sum.h"

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

namespace leetcode {
    class test {
    public:
        test() = default;
        test(const test& other) = delete;
        test(test&& other) = delete;
        test& operator = (const test& other) = delete;
        test& operator = (test&& other) = delete;
        ~test() = default;

        void run() const {
            test_two_sum();
        }

    private:

        void test_two_sum() const {
            std::cout << "--- Two Sum ---" << std::endl;

            std::map<std::pair<std::vector<int>, int>, std::vector<int>> test_cases = {
                { { { 1, 4, 5, 8, 7, 0 }, 9}, {1, 2} },
                { { { 2, 7, 11, 15}, 9}, {0, 1} },
            };

            two_sum test;
            std::for_each(std::begin(test_cases), std::end(test_cases), [&test](auto i) {
                auto result = test.task(i.first.first, i.first.second);
                std::sort(begin(result), end(result)); // to perform proper comparison with the expected result
                helper::out_each(std::cout, i.first.first) << " : " << i.first.second << " -> ";
                helper::out_each(std::cout, result) << " - " << ((result == i.second) ? "[OK]" : "[FAIL]") << std::endl;
                });
        }
    };
}
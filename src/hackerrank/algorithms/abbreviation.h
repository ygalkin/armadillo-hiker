#pragma once

#include "../../helper/helper.h"

#include <unordered_set>
#include <map>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cctype>

namespace hackerrank {

    // This code should work with C++14.
    // In C++17 it is better to use string_view.
    // https://www.hackerrank.com/challenges/abbr/problem
    class abbreviation {
    private:
        std::unordered_set<std::pair<std::string, std::string>, helper::pair_hash> _lookup;

        bool is_lower_or_empty(const std::string& s, int n) {
            for (size_t i = n; i < s.length(); ++i) {
                if (std::isupper(s[i]))
                    return false;
            }

            return true;
        }

        bool abbreviation_recursion(const std::string& a, unsigned int i, const std::string& b, unsigned int j) {
            // a < b 
            if (a.length() - i < b.length() - j) {
                return false;
            }

            // b is empty
            if (j == b.length()) {
                return is_lower_or_empty(a, i);
            }

            // memoization
            auto p = _lookup.insert({ a.substr(i), b.substr(j) });
            if (!p.second) { // No isertion. a#b already in a lookup table. 
                return false;
            }

            // a[0] == b[0] (both capital latters) or
            // a[0] is lower. We can make it upper case and then it matches b[0]
            if (b[j] == std::toupper(a[i])) {
                if (abbreviation_recursion(a, i + 1, b, j + 1)) {
                    return true;
                }
            }

            // a[0] is lower
            if (std::islower(a[i])) {
                if (abbreviation_recursion(a, i + 1, b, j)) {
                    return true;
                }
            }

            return false;
        }

    public:
        abbreviation() = default;
        abbreviation(const abbreviation& other) = default;
        abbreviation& operator = (const abbreviation& other) = default;
        ~abbreviation() = default;

        bool task(const std::string& a, const std::string& b) {
            _lookup.clear();
            return abbreviation_recursion(a, 0, b, 0);
        }
    };

};
#pragma once

#include <unordered_map>
#include <map>
#include <iostream>
#include <algorithm>

namespace leetcode {

    // https://leetcode.com/problems/two-sum/
    class two_sum {
    private:
        using lookup_tbl = std::unordered_map<int, int>;

    public:
        two_sum() = default;
        two_sum(const two_sum & other) = default;
        two_sum& operator = (const two_sum & other) = default;
        ~two_sum() = default;

        // Time complexity: O(n) - linear. One-phase loop.
        std::vector<int> task(const std::vector<int>& nums, int target) {
            lookup_tbl lookup(nums.size()); // We know max size of the set. Let's allocate it to speed up the algorithm

            for (size_t i = 0; i < nums.size(); ++i) {
                auto item = lookup.find(target - nums[i]);
                if (item != end(lookup)) {
                    return { item->second, (int)i };
                }

                lookup[nums[i]] = i;
            }

            return {};
        }
    };
}

// https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/

class Solution {
public:
    // __builtin_popcount can be used instead
    int bits_num(int n) {
        auto num{ 0 };

        while (n != 0) {
            num += (1 & n);
            n = n >> 1;
        }

        return num;
    }

    vector<int> sortByBits(vector<int>& arr) {
        std::sort(std::begin(arr), std::end(arr), [&](const auto& l, const auto& r) {
            auto x = bits_num(l);
            auto y = bits_num(r);
            return x == y ? l < r : x < y; });
        return arr;
    }
};
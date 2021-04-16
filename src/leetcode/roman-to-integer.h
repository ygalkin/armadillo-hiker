// https://leetcode.com/problems/roman-to-integer/

class Solution {
private:
    const unordered_map<char, int> _lookup_tbl = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000}
    };

public:
    int romanToInt(string& s) {
        auto n{ 0 }; // result
        int i{ 0 };
        auto prev{ 0 };
        auto curr{ 0 };
        const size_t last = s.size() - 1;

        for (i = last; i >= 0; --i) {
            curr = _lookup_tbl.at(s[i]);
            n = (i < last && curr < prev) ? n - curr : n + curr;
            prev = curr;
        }

        return n;
    }
};
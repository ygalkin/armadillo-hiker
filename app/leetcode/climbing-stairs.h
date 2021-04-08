// https://leetcode.com/problems/climbing-stairs/

class Solution {
private:
    unordered_map<int, int> _lookup_tbl;

public:
    // Recursion, memoization solution
    int climbStairs(int n) {
        if (n == 1 || n == 0) {
            return 1;
        }

        auto p = _lookup_tbl.find(n);
        if (p != _lookup_tbl.end()) {
            return p->second;
        }

        auto num = climbStairs(n - 1) + climbStairs(n - 2);
        _lookup_tbl.insert(std::pair(n, num));

        return num;
    }
};

// TODO: DP array


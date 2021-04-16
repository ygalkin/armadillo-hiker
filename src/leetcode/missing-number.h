// https://leetcode.com/problems/missing-number/

class Solution {
public:
    // Gauss formula S = (n * (n + 1)) / 2

    int missingNumber(vector<int>& nums) {
        return ((nums.size() * (nums.size() + 1)) / 2) - std::accumulate(std::begin(nums), std::end(nums), 0);
    }
};

// TODO: XOR solution

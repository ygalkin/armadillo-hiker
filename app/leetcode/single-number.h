// https://leetcode.com/problems/single-number/

class Solution {
public:
    // XOR Solution
    int singleNumber(vector<int>& nums) {
        auto res{0};
        
        for (const auto& n : nums) {
            res ^= n;
        }
        
        return res;
    }
};

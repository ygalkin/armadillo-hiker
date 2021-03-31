// https://leetcode.com/problems/permutations/

// Time complexity O(n!)
class Solution {
public:
    void permute_recursion(
        vector<int>& nums, int n, vector<vector<int>>& out) {
        
        auto last = nums.size() - 1;
        
        if (n == last) {
            out.push_back(nums);
            return;
        }
        
        for (auto i = n; i <= last; ++i) {
            swap(nums[n], nums[i]);
            permute_recursion(nums, n + 1, out);
            swap(nums[i], nums[n]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> out;
        
        permute_recursion(nums, 0, out);
        
        return out;
    }
};

// The same algorithm can be done using std::next_permutation

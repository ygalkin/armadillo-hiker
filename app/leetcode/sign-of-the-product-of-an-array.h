// https://leetcode.com/problems/sign-of-the-product-of-an-array/

class Solution {
public:
    int arraySign(vector<int>& nums) {
        auto product_sign{ 1 };
        for (auto n : nums) {
            if (n == 0)
                return 0;
            product_sign *= (n < 0) ? -1 : 1;
        }

        return product_sign;
    }
};
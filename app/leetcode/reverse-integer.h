// https://leetcode.com/problems/reverse-integer/submissions/

class Solution {
public:
    int reverse(int x) {
        const auto MAX = numeric_limits<int>::max();
        const auto MIN = numeric_limits<int>::min();
        
        int n = 0;
        
        while (x != 0) {
            int b = x % 10;
            x = x / 10;

            // overflow check           
            if (n > (MAX / 10) || n < (MIN / 10)) {
                return 0;
            }
            
            n = n * 10 + b;
        }
        
        return n;
    }
};

// TODO: add check for +b overflow
// https://leetcode.com/problems/fizz-buzz/

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result;
        
        for (auto i = 1; i <= n; ++i) {
            string str;
            if (i % 3 == 0) str = "Fizz";
            if (i % 5 == 0) str += "Buzz";
            if (str.empty()) str = to_string(i);
            
            result.push_back(str);
        }
        
        return result;
    }
};

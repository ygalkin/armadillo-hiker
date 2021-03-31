// https://leetcode.com/problems/valid-palindrome/

class Solution {
public:
    // Two-pointer approach
    bool isPalindrome(string s) {
        auto first = 0;
        auto second = s.size() - 1;
        
        while (first < second) {
            if (!std::isalnum(s[first])) {++first; continue; };
            if (!std::isalnum(s[second])) {--second; continue; }; 
            
            if (std::tolower(s[first]) != std::tolower(s[second])) {
                return false;
            }
            
            ++first;
            --second;
        }
        
        return true;
    }
};
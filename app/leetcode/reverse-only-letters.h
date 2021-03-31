// https://leetcode.com/problems/reverse-only-letters/ 

class Solution {
public:
    // Inplace solution. Two-pointer approach.
    string reverseOnlyLetters(string S) {
        if (S.empty()) {
            return {};
        }
        
        string reverted{S};
        size_t i{0};
        size_t j{reverted.size() - 1};
        
        while (i < j) {
            if (!std::isalpha(reverted[i])) { ++i; continue; }
            if (!std::isalpha(reverted[j])) { --j; continue; }
            
            std::swap(reverted[i], reverted[j]);
            ++i;
            --j;
        }        
        
        return reverted;
    }
};
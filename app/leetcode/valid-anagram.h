// https://leetcode.com/problems/valid-anagram/

class Solution {
public:
    using lookup_tbl = unordered_map<char, int>;
    
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        
        lookup_tbl _lookup_tbl;
        
        for (auto i = 0; i < s.size(); ++i) {
            ++_lookup_tbl[s[i]];
            --_lookup_tbl[t[i]];
        }
        
        for (auto node : _lookup_tbl) {
            if (node.second != 0) {
                return false;
            }
        }
        
        return true;        
    }
};
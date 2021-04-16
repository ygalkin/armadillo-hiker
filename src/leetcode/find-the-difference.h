// https://leetcode.com/problems/find-the-difference/

class Solution {
public:
    char findTheDifference(string s, string t) {
        // simple solution. max number of total loop iterations (s.length + t.length)
        // auto n{0};
        // for (auto ch : s) n ^= ch; 
        // for (auto ch : t) n ^= ch;
        // return n;

        // optimized solution max number of total iterations (s.length)
        // constrains: t.length == s.length + 1
        auto n{ t[t.size() - 1] };
        for (size_t i = 0; i < s.size(); ++i) {
            n ^= (s[i] ^ t[i]);
        }

        return n;
    }
};

class Solution2 {
public:
    char findTheDifference(string s, string t) {
        return inner_product(begin(s), end(s), begin(t), *prev(end(t)), bit_xor<>(), bit_xor<>());
    }
};
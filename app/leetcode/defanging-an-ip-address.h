// https://leetcode.com/problems/defanging-an-ip-address/

class Solution {
public:
    string defangIPaddr(string address) {
        decltype(address) s;

        for (const auto& i : address)
            (i == '.') ? s += "[.]" : s += i;

        return s;
    }
};
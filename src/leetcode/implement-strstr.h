// https://leetcode.com/problems/implement-strstr/

// Naive Algorithm for Pattern Searching
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }

        if (haystack.size() < needle.size()) {
            return -1;
        }

        for (size_t i = 0; i <= haystack.size() - needle.size(); ++i) {
            if (haystack[i] == needle[0]) {
                size_t j = 1;
                for (; j < needle.size(); ++j) {
                    if (haystack[i + j] != needle[j]) {
                        break;
                    }
                }

                if (j == needle.size()) {
                    return i;
                }
            }
        }

        return -1;
    }
};

// TODO: Optimized Naive Algorithm for Pattern Searching

// TODO: KPM Algorithm for Pattern Searching

// TODO: Rabin-Karp Algorithm for Pattern Searching
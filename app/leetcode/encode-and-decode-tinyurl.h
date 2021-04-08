// https://leetcode.com/problems/encode-and-decode-tinyurl/

#include <functional>
#include <unordered_map>

class Solution {
public:
    // <hash, long URL>
    unordered_map<size_t, std::string> _lookup_tbl;

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        // long URL -> hash
        size_t hash = std::hash<std::string>{}(longUrl);
        // find in the lookup table if hash already exist
        auto iter = _lookup_tbl.find(hash);
        // if no hash in the table
        if (iter == end(_lookup_tbl)) {
            // save hash and long URL into the table
            _lookup_tbl.insert(std::pair(hash, longUrl));
        }

        return "http://tinyurl.com/" + std::to_string(hash);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        // Parse short URL
        size_t pos = shortUrl.find_last_of("/");
        if (pos == string::npos) {
            return {};
        }

        // extract hash value from the URL
        auto str_hash = shortUrl.substr(pos + 1);
        size_t hash = std::stoul(str_hash);

        // find long URL by hash value in the lookup table
        auto iter = _lookup_tbl.find(hash);
        if (iter == end(_lookup_tbl)) {
            return {};
        }

        // return long URL
        return iter->second;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
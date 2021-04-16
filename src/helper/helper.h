#pragma once

#include <algorithm>
#include <iostream>
#include <numeric>

namespace helper {
    template <typename T>
    std::ostream& out_each(std::ostream& os, const T& t) {
        os << "{";
        std::for_each(begin(t), end(t), [](auto i) { std::cout << i << " "; });
        os << "}";
        return os;
    }

    // https://www.techiedelight.com/use-std-pair-key-std-unordered_map-cpp/
    struct pair_hash
    {
        template <class T1, class T2>
        std::size_t operator() (const std::pair<T1, T2>& pair) const
        {
            return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
        }
    };

    struct str_pair_hash {
        template <typename PairStr>
        constexpr std::size_t operator()(const PairStr& p) const {
            std::size_t res = 0;

            auto hasher = [](std::size_t res, auto c) { return (res * 131) + c; };
            res = std::accumulate(std::begin(p.first), std::end(p.first), res, hasher);
            res = std::accumulate(std::begin(p.second), std::end(p.second), res, hasher);

            return res;
        }
    };

    template <size_t max_len = 30>
    std::string short_string(const std::string& s) {
        return (s.length() > max_len ? s.substr(0, max_len).append("...") : s);
    }
}

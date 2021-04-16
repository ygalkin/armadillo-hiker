#include "test.h"
#include "hackerrank/test.h"
#include "leetcode/test.h"

#include <iostream>

const int _ = [] {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cout << "--Standard in and out streams are untied--" << std::endl;
    return 0;
}();

int main() {
    Test().run();
    hackerrank::test::run();
    leetcode::test::run();
}

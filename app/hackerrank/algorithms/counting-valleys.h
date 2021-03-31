// https://www.hackerrank.com/challenges/counting-valleys/problem
int countingValleys(int steps, string path) {
    
    auto step = 0;
    auto valley = 0;
    
    for (auto i : path) {
        if (i == 'U') {
            ++step;
            if (step == 0) ++valley;
        } else if (i == 'D') --step;
    }
    
    return valley;
}


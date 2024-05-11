//4.problem
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Pair {
    int first;
    int second;
};

bool comparePairs(const Pair& a, const Pair& b) {
    return a.second < b.second;
}

int maxChainLength(vector<Pair>& pairs) {
    if (pairs.empty()) return 0;

    sort(pairs.begin(), pairs.end(), comparePairs);

    int maxChainLen = 1;
    int currentEnd = pairs[0].second;

    for (int i = 1; i < pairs.size(); ++i) {
        if (pairs[i].first > currentEnd) {
            maxChainLen++;
            currentEnd = pairs[i].second;
        }
    }

    return maxChainLen;
}

int main() {
    vector<Pair> pairs = { {5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90} };
    cout << "Max chain length for first example: " << maxChainLength(pairs) << endl;

    pairs = { {5, 10}, {1, 11} };
    cout << "Max chain length for second example: " << maxChainLength(pairs) << endl;

    return 0;
}

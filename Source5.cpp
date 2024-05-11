//5.problem
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

    int n = pairs.size();
    vector<int> dp(n, 1);

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (pairs[i].first > pairs[j].second) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    return *max_element(dp.begin(), dp.end());
}

int main() {
    vector<Pair> pairs1 = { {5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90} };
    cout << "Max chain length for first example: " << maxChainLength(pairs1) << endl;

    vector<Pair> pairs2 = { {5, 10}, {1, 11} };
    cout << "Max chain length for second example: " << maxChainLength(pairs2) << endl;

    return 0;
}

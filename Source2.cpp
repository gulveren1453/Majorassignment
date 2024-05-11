//2.problem
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent a job
struct Job {
    int id;
    int deadline;
    int profit;
};

// Function to compare jobs based on profit in decreasing order
bool compare(Job& a, Job& b) {
    return a.profit > b.profit;
}

// Function to find maximum profit and number of jobs done
pair<int, int> maxProfit(vector<Job>& jobs) {
    // Sort jobs based on profit in decreasing order
    sort(jobs.begin(), jobs.end(), compare);

    int maxProfit = 0;
    int numJobsDone = 0;

    // Find maximum profit and number of jobs done
    vector<bool> slot(jobs.size(), false);
    for (int i = 0; i < jobs.size(); ++i) {
        for (int j = min(jobs[i].deadline - 1, (int)jobs.size() - 1); j >= 0; --j) {
            if (!slot[j]) {
                slot[j] = true;
                maxProfit += jobs[i].profit;
                ++numJobsDone;
                break;
            }
        }
    }

    return { numJobsDone, maxProfit };
}

int main() {
    // Example 1
    int N1 = 4;
    vector<Job> jobs1 = { {1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30} };

    pair<int, int> result1 = maxProfit(jobs1);

    cout << "Example 1:" << endl;
    cout << "Number of jobs done: " << result1.first << endl;
    cout << "Maximum profit: " << result1.second << endl;

    // Example 2
    int N2 = 5;
    vector<Job> jobs2 = { {1, 2, 100}, {2, 1, 19}, {3, 2, 27}, {4, 1, 25}, {5, 1, 15} };

    pair<int, int> result2 = maxProfit(jobs2);

    cout << "\nExample 2:" << endl;
    cout << "Number of jobs done: " << result2.first << endl;
    cout << "Maximum profit: " << result2.second << endl;

    return 0;
}



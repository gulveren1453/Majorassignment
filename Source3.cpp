//3.problem
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Job {
    int id;
    int deadline;
    int profit;
};

bool compare(Job a, Job b) {
    return (a.profit > b.profit);
}

pair<int, int> findMaxProfit(vector<Job>& jobs) {
    sort(jobs.begin(), jobs.end(), compare);

    int maxDeadline = 0;
    for (const Job& job : jobs) {
        maxDeadline = max(maxDeadline, job.deadline);
    }

    vector<int> result(maxDeadline, -1);
    int count = 0, profit = 0;

    for (int i = 0; i < jobs.size(); ++i) {
        for (int j = jobs[i].deadline - 1; j >= 0; --j) {
            if (result[j] == -1) {
                result[j] = jobs[i].id;
                count++;
                profit += jobs[i].profit;
                break;
            }
        }
    }

    return make_pair(count, profit);
}

int main() {
    vector<Job> jobs = { {1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30} };
    pair<int, int> result = findMaxProfit(jobs);
    cout << "Number of jobs done: " << result.first << endl;
    cout << "Maximum profit: " << result.second << endl;

    return 0;
}

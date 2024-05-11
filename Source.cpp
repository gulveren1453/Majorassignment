#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent a meeting
struct Meeting {
    int start;
    int end;
};

// Comparator function to sort meetings based on their end times
bool compareMeetings(const Meeting& a, const Meeting& b) {
    return a.end < b.end;
}

int maxMeetings(int start[], int end[], int N) {
    vector<Meeting> meetings(N);

    // Store meetings in a vector of Meeting structs
    for (int i = 0; i < N; ++i) {
        meetings[i].start = start[i];
        meetings[i].end = end[i];
    }

    // Sort meetings based on their end times
    sort(meetings.begin(), meetings.end(), compareMeetings);

    // Initialize count and end time of last selected meeting
    int count = 1;
    int lastEnd = meetings[0].end;

    // Iterate through sorted meetings and count the number of accommodated meetings
    for (int i = 1; i < N; ++i) {
        if (meetings[i].start >= lastEnd) {
            count++;
            lastEnd = meetings[i].end;
        }
    }

    return count;
}

int main() {
    int N = 6;
    int start[] = { 1, 3, 0, 5, 8, 5 };
    int end[] = { 2, 4, 6, 7, 9, 9 };

    cout << "Maximum number of meetings: " << maxMeetings(start, end, N) << endl;

    return 0;
}

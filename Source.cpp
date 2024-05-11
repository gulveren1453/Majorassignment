#include <iostream>
#include <vector>
using namespace std;
//problem 11
bool isValid(int A[], int N, int M, int mid) {
    int students = 1;
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += A[i];
        if (sum > mid) {
            students++;
            sum = A[i];
        }
        if (students > M) {
            return false;
        }
    }
    return true;
}

int findPages(int N, int A[], int M) {
    if (N < M) {
        return -1;
    }

    int total_pages = 0;
    int max_page = A[0];

    for (int i = 0; i < N; i++) {
        total_pages += A[i];
        if (A[i] > max_page) {
            max_page = A[i];
        }
    }

    int low = max_page;
    int high = total_pages;
    int result = INT_MAX; 

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (isValid(A, N, M, mid)) {
            result = min(result, mid);
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return result == INT_MAX ? -1 : result; 
}

int main() {
    int N1 = 4;
    int A1[] = { 12, 34, 67, 90 };
    int M1 = 2;
    cout << findPages(N1, A1, M1) << endl; 

    int N2 = 3;
    int A2[] = { 15, 17, 20 };
    int M2 = 2;
    cout << findPages(N2, A2, M2) << endl; 

    return 0;
}


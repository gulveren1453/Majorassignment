#include <iostream>
#include <vector>
using namespace std;
//problem 10
int kthElement(int arr1[], int arr2[], int N, int M, int K) {
    int i = 0, j = 0;
    int count = 0;
    int result = -1;

    while (i < N && j < M) {
        if (arr1[i] < arr2[j]) {
            count++;
            if (count == K) {
                result = arr1[i];
                break;
            }
            i++;
        }
        else {
            count++;
            if (count == K) {
                result = arr2[j];
                break;
            }
            j++;
        }
    }

   
    while (i < N && count < K) {
        count++;
        if (count == K) {
            result = arr1[i];
            break;
        }
        i++;
    }

    while (j < M && count < K) {
        count++;
        if (count == K) {
            result = arr2[j];
            break;
        }
        j++;
    }

    return result;
}

int main() {
    int arr1[] = { 2, 3, 6, 7, 9 };
    int arr2[] = { 1, 4, 8, 10 };
    int N = 5, M = 4, K = 5;
    cout << kthElement(arr1, arr2, N, M, K) << endl; 

    int arr3[] = { 100, 112, 256, 349, 770 };
    int arr4[] = { 72, 86, 113, 119, 265, 445, 892 };
    N = 5, M = 7, K = 7;
    cout << kthElement(arr3, arr4, N, M, K) << endl;

    return 0;
}

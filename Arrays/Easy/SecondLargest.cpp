#include <bits/stdc++.h>
using namespace std;

int secondLargest(int arr[], int n) {
    int largest = arr[0];
    int sLargest = -1;

    for (int i = 0; i < n; i++) {
        if (arr[i] > largest) {
            sLargest = largest;
            largest = arr[i];
        } else if (arr[i] < largest && arr[i] > sLargest) {
            sLargest = arr[i];
        }
    }
    return sLargest;
}

int main() {
    int arr[] = {1, 2, 4, 7, 7, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << secondLargest(arr, n);
}
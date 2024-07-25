#include <bits/stdc++.h>
using namespace std;

// hashing approach

int main() {
    int arr[] = {2, 6, 5, 8, 11};

    sort(arr, arr + (end(arr) - begin(arr)));

    int i = 0;
    int j = end(arr) - begin(arr) - 1;
    int sum = 14;

    while (i < j) {
        if (arr[i] + arr[j] == sum) {
            cout << i << ", " << j;
            return 0;
        } else if (arr[i] + arr[j] < sum) {
            i++;
        } else {
            j--;
        }
    }

    cout << "-1, -1";
}
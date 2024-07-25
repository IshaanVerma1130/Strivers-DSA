#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {1, 1, 2, 2, 3, 3};
    int n = size(arr);
    int i = 0;

    for (int j = 1; j < n; j++) {
        if (arr[i] != arr[j]) {
            i++;
            arr[i] = arr[j];
        }
    }
    cout << i + 1;
}
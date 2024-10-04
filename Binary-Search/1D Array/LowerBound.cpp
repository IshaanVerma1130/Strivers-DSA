#include <bits/stdc++.h>
using namespace std;

int optimla(vector<int> arr, int target) {
    int low = 0;
    int high = arr.size() - 1;
    int ind = arr.size();

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= target) {
            ind = mid;
            high = mid - 1;
        } else
            low = mid + 1;
    }

    return ind;
}

int main() {
    vector<int> arr = {1, 2, 2, 3};
    int target = 2;
    cout << optimla(arr, target) << endl;
}
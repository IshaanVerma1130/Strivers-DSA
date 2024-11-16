#include <bits/stdc++.h>
using namespace std;

int brute(vector<int> arr) {
    vector<int> prefix(arr.size(), 0), suffix(arr.size(), 0);
    // Prefix Array
    prefix[0] = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        prefix[i] = max(prefix[i - 1], arr[i]);
    }
    // Suffix Array
    suffix[arr.size() - 1] = arr[arr.size() - 1];
    for (int i = arr.size() - 2; i >= 0; i--) {
        suffix[i] = max(suffix[i + 1], arr[i]);
    }

    int ans = 0;
    for (int i = 0; i < arr.size(); i++) {
        ans += min(prefix[i], suffix[i]) - arr[i];
    }
    return ans;
}

int optimal(vector<int> arr) {
    int l = 0, r = arr.size() - 1, total = 0;
    int leftMax = 0, rightMax = 0;

    while (l <= r) {
        if (arr[l] <= arr[r]) {
            if (leftMax > arr[l]) {
                total += leftMax - arr[l];
            } else {
                leftMax = arr[l];
            }
            l++;
        }
        if (arr[l] > arr[r]) {
            if (rightMax > arr[r]) {
                total += rightMax - arr[r];
            } else {
                rightMax = arr[r];
            }
            r--;
        }
    }
    return total;
}

int main() {
    vector<int> arr = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    // cout << brute(arr) << endl;
    cout << optimal(arr) << endl;
    return 0;
}
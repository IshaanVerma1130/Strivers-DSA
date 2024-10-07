#include <bits/stdc++.h>
using namespace std;

int optimal(vector<int> arr1, vector<int> arr2, int k) {
    int n1 = arr1.size();
    int n2 = arr2.size();
    if (n1 > n2) {
        return optimal(arr2, arr1, k);
    }
    int low = max(0, k - n2);
    int high = min(k, n1);
    int left = k;
    while (low <= high) {
        int mid1 = (low + high) / 2;
        int mid2 = left - mid1;
        int l1 = INT_MIN;
        int l2 = INT_MIN;
        int r1 = INT_MAX;
        int r2 = INT_MAX;
        if (mid1 < n1)
            r1 = arr1[mid1];
        if (mid2 < n2)
            r2 = arr2[mid2];
        if (mid1 - 1 >= 0)
            l1 = arr1[mid1 - 1];
        if (mid2 - 1 >= 0)
            l2 = arr2[mid2 - 1];
        if (l1 <= r2 && l2 <= r1) {
            return max(l1, l2);
        } else if (l1 > r2)
            high = mid1 - 1;
        else
            low = mid1 + 1;
    }
    return 0;
}

int main() {
    vector<int> arr1 = {100, 112, 256, 349, 770};
    vector<int> arr2 = {72, 86, 113, 119, 265, 445, 892};
    int k = 7;
    cout << optimal(arr1, arr2, k) << endl;
}
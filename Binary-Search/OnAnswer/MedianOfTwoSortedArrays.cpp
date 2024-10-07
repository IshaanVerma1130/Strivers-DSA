#include <bits/stdc++.h>
using namespace std;
double brute(vector<int> arr1, vector<int> arr2) {
    int n = arr1.size();
    int m = arr2.size();
    vector<int> arr(n + m);

    int i = 0;
    int j = 0;

    while (i < n && j < m) {
        if (arr1[i] >= arr2[j]) {
            arr[i + j] = arr2[j];
            j++;
        } else {
            arr[i + j] = arr1[i];
            i++;
        }
    }
    while (i < n) {
        arr[i + j] = arr1[i];
        i++;
    }
    while (j < m) {
        arr[i + j] = arr2[j];
        j++;
    }
    int med = (n + m) / 2;
    if ((n + m) % 2 == 0) {
        return (arr[med] + arr[med - 1]) / 2.0;
    } else {
        return arr[med];
    }
}

double better(vector<int> arr1, vector<int> arr2) {
    int n = arr1.size();
    int m = arr2.size();
    int total = n + m;
    int el2Index = total / 2;
    int el1Index = el2Index - 1;

    int el1 = -1;
    int el2 = -1;
    int count = 0;

    int i = 0;
    int j = 0;

    while (i < n && j < m) {
        if (arr1[i] < arr2[j]) {
            if (count == el1Index)
                el1 = arr1[i];
            if (count == el2Index)
                el2 = arr1[i];
            i++;
        } else {
            if (count == el1Index)
                el1 = arr2[j];
            if (count == el2Index)
                el2 = arr2[j];
            j++;
        }
        count++;
    }

    while (i < n) {
        if (count == el1Index)
            el1 = arr1[i];
        if (count == el2Index)
            el2 = arr1[i];
        i++;
        count++;
    }
    while (j < m) {
        if (count == el1Index)
            el1 = arr2[j];
        if (count == el2Index)
            el2 = arr2[j];
        j++;
        count++;
    }

    if (total % 2 == 0) {
        return (el1 + el2) / 2.0;
    } else {
        return el2;
    }
}

double optimal(vector<int> arr1, vector<int> arr2) {
    int n1 = arr1.size();
    int n2 = arr2.size();
    if (n1 > n2) {
        return optimal(arr2, arr1);
    }
    int low = 0;
    int high = n1;
    int left = (n1 + n2 + 1) / 2;
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
            if ((n1 + n2) % 2 == 0) {
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            } else {
                return max(l1, l2);
            }
        } else if (l1 > r2)
            high = mid1 - 1;
        else
            low = mid1 + 1;
    }
    return 0;
}

int main() {
    vector<int> arr1 = {1};
    vector<int> arr2 = {1};
    cout << brute(arr1, arr2) << endl;
    cout << better(arr1, arr2) << endl;
    cout << optimal(arr1, arr2) << endl;
}
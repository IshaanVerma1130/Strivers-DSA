#include <bits/stdc++.h>
using namespace std;

int brute(vector<int> arr) {
    int count = 0;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[i] > arr[j] * 2) {
                count++;
            }
        }
    }
    return count;
}

void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp;
    int left = low, right = mid + 1;

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

int countPairs(vector<int> &arr, int low, int mid, int high) {
    int count = 0;
    int right = mid + 1;

    for (int i = low; i <= mid; i++) {
        while (right <= high && arr[i] > 2 * arr[right])
            right++;
        count += right - (mid + 1);
    }
    return count;
}

int mS(vector<int> &arr, int low, int high) {
    int count = 0;
    if (low >= high)
        return count;
    int mid = (low + high) / 2;
    count += mS(arr, low, mid);
    count += mS(arr, mid + 1, high);
    count += countPairs(arr, low, mid, high);
    merge(arr, low, mid, high);
    return count;
}

int main() {
    vector<int> arr = {1, 3, 2, 3, 1};
    cout << brute(arr) << endl;
    cout << mS(arr, 0, arr.size() - 1) << endl;
    return 0;
}
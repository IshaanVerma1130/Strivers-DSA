#include <bits/stdc++.h>
using namespace std;

int better(vector<int> arr, long long k) { // this is optimal for negatives
    map<long long, int> prefixMap;
    long long sum = 0;
    int len = 0;

    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        if (sum == k) {
            len = max(len, i + 1);
        }

        long long remaining = sum - k;

        if (prefixMap.find(remaining) != prefixMap.end()) {
            len = max(len, i - prefixMap[remaining]);
        }

        if (prefixMap.find(remaining) == prefixMap.end()) {
            prefixMap[sum] = i;
        }
    }
    return len;
}

int optimal(vector<int> arr, long long k) { // sliding window
    int i = 0;
    int j = 0;
    int maxLen = 0;
    long long sum = 0;

    while (j < arr.size()) {
        sum += arr[j];

        if (sum < k) {
            j++;
        } else if (sum == k) {
            maxLen = max(maxLen, j - i + 1);
            j++;
        } else {
            while (sum > k) {
                sum -= arr[i];
                i++;
            }

            if (sum == k) {
                maxLen = max(maxLen, j - i + 1);
            }
            j++;
        }
    }
    return maxLen;
}

int main() {
    vector<int> arr = {1, 2, 3, 1, 1, 1, 1, 4, -1, 1, 0, 0, 2, 3};
    long long k = 5;

    cout << better(arr, k) << endl;
    cout << optimal(arr, k);
}
#include <bits/stdc++.h>
using namespace std;

int brute(vector<int> arr, int givenSum) {
    int n = arr.size();
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int sum = 0;

            for (int k = i; k <= j; k++) {
                sum += arr[k];
            }

            if (sum == givenSum)
                count++;
        }
    }

    return count;
}
int better(vector<int> arr, int givenSum) {
    int n = arr.size();
    int count = 0;

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];

            if (sum == givenSum)
                count++;
        }
    }

    return count;
}

int optimal(vector<int> arr, int givenSum) {
    map<int, int> prefixMap;
    prefixMap[0] = 1;

    int preSum = 0;
    int count = 0;

    for (int i = 0; i < arr.size(); i++) {
        preSum += arr[i];

        int remove = preSum - givenSum;

        count += prefixMap[remove];

        prefixMap[preSum] += 1;
    }
    return count;
}

int main() {
    vector<int> arr = {3, 1, 2, 4};
    int k = 6;

    cout << "Brute:" << brute(arr, k) << "\n";
    cout << "Better:" << better(arr, k) << "\n";
    cout << "Optimal:" << optimal(arr, k) << "\n";
}
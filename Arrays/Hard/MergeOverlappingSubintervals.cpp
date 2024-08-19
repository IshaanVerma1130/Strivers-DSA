#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> brute(vector<vector<int>> arr) {
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        int start = arr[i][0];
        int end = arr[i][1];
        if (!ans.empty() && ans.back()[1] >= end) {
            continue;
        }
        for (int j = i + 1; j < n; j++) {
            if (arr[j][0] <= end) {
                end = max(end, arr[j][1]);
            } else {
                break;
            }
        }
        ans.push_back({start, end});
    }
    return ans;
}

vector<vector<int>> optimal(vector<vector<int>> arr) {
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        if (ans.empty() || arr[i][0] > ans.back()[1]) {
            ans.push_back(arr[i]);
        } else {
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }
    return ans;
}

int main() {
    // Sample test vector 1
    vector<vector<int>> arr1 = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> result1_brute = brute(arr1);
    vector<vector<int>> result1_optimal = optimal(arr1);

    cout << "Result for sample test vector 1 (brute approach):" << endl;
    for (auto interval : result1_brute) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    cout << "Result for sample test vector 1 (optimal approach):" << endl;
    for (auto interval : result1_optimal) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    // Sample test vector 2
    vector<vector<int>> arr2 = {{1, 4}, {4, 5}};
    vector<vector<int>> result2_brute = brute(arr2);
    vector<vector<int>> result2_optimal = optimal(arr2);

    cout << "Result for sample test vector 2 (brute approach):" << endl;
    for (auto interval : result2_brute) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    cout << "Result for sample test vector 2 (optimal approach):" << endl;
    for (auto interval : result2_optimal) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> brute(vector<int> arr, int target) { // O(n^4 * log(unique triplets)) // O(2*number of triplets)
    int n = arr.size();
    set<vector<int>> s;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                for (int l = k + 1; l < n; l++) {
                    long long sum = arr[i] + arr[j];
                    sum += arr[k];
                    sum += arr[l];
                    if (sum == target) {
                        vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                        sort(temp.begin(), temp.end());
                        s.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>> ans(s.begin(), s.end());
    return ans;
}

vector<vector<int>> better(vector<int> arr, int target) { // O(n^3 * log(unique tiplets)) // O(2*number of triplets)
    int n = arr.size();
    set<vector<int>> s;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            set<long long> hashset;
            for (int k = j + 1; k < n; k++) {
                long long sum = arr[i] + arr[j];
                sum += arr[k];
                long long l = target - sum;
                if (hashset.find(l) != hashset.end()) {
                    vector<int> temp = {arr[i], arr[j], arr[k], (int)l};
                    sort(temp.begin(), temp.end());
                    s.insert(temp);
                }
                hashset.insert(arr[k]);
            }
        }
    }
    vector<vector<int>> ans(s.begin(), s.end());
    return ans;
}

vector<vector<int>> optimal(vector<int> arr, int target) { // O(nlongn + n^2*n)
    int n = arr.size();
    vector<vector<int>> ans;

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++) {
        if (i > 0 && arr[i] == arr[i - 1])
            continue;
        for (int j = i + 1; j < n; j++) {
            if (j > i + 1 && arr[j] == arr[j - 1])
                continue;
            int k = j + 1;
            int l = n - 1;

            while (k < l) {
                long long sum = arr[i] + arr[j];
                sum += arr[k];
                sum += arr[l];

                if (sum < target) {
                    k++;
                } else if (sum > target) {
                    l--;
                } else {
                    vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                    ans.push_back(temp);
                    k++;
                    l--;

                    while (k < l && arr[k] == arr[k - 1])
                        k++;
                    while (k < l && arr[l] == arr[l + 1])
                        l--;
                }
            }
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
    int target = 9;
    vector<vector<int>> arr_brute = brute(arr, target);
    cout << "Brute Force Approach:" << endl;
    for (auto triplet : arr_brute) {
        for (auto num : triplet) {
            cout << num << " ";
        }
        cout << endl;
    }

    vector<vector<int>> arr_better = better(arr, target);
    cout << "Better Approach:" << endl;
    for (auto triplet : arr_better) {
        for (auto num : triplet) {
            cout << num << " ";
        }
        cout << endl;
    }

    vector<vector<int>> arr_optimal = optimal(arr, target);
    cout << "Optimal Approach:" << endl;
    for (auto triplet : arr_optimal) {
        for (auto num : triplet) {
            cout << num << " ";
        }
        cout << endl;
    }
}
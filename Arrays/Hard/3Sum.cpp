#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

vector<vector<int>> brute(vector<int> arr) {  // O(n^3 * log(unique triplets))
                                              // // O(2*number of triplets)
    int n = arr.size();
    set<vector<int>> s;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (arr[i] + arr[j] + arr[k] == 0) {
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());
                    s.insert(temp);
                }
            }
        }
    }

    vector<vector<int>> ans(s.begin(), s.end());
    return ans;
}

vector<vector<int>> better(vector<int> arr) {  // O(n^2 * log(unique tiplets))
                                               // // O(2*number of triplets)
    int n = arr.size();
    set<vector<int>> s;

    for (int i = 0; i < n; i++) {
        set<int> hashset;
        for (int j = i + 1; j < n; j++) {
            int k = -(arr[i] + arr[j]);
            if (hashset.find(k) != hashset.end()) {
                vector<int> temp = {arr[i], arr[j], k};
                sort(temp.begin(), temp.end());
                s.insert(temp);
            }
            hashset.insert(arr[j]);
        }
    }

    vector<vector<int>> ans(s.begin(), s.end());
    return ans;
}

vector<vector<int>> optimal(vector<int> arr) {  // O(nlongn + n*n)
    int n = arr.size();
    vector<vector<int>> ans;

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++) {
        if (i > 0 && arr[i] == arr[i - 1]) continue;
        int j = i + 1;
        int k = n - 1;

        while (j < k) {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum < 0) {
                j++;
            } else if (sum > 0) {
                k--;
            } else {
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;

                while (j < k && arr[j] == arr[j - 1]) j++;
                while (j < k && arr[k] == arr[k + 1]) k--;
            }
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {-1, 0, 1, 2, -1, -4};

    vector<vector<int>> arr_brute = brute(arr);
    cout << "Brute Force Approach:" << endl;
    for (auto triplet : arr_brute) {
        for (auto num : triplet) {
            cout << num << " ";
        }
        cout << endl;
    }

    vector<vector<int>> arr_better = better(arr);
    cout << "Better Approach:" << endl;
    for (auto triplet : arr_better) {
        for (auto num : triplet) {
            cout << num << " ";
        }
        cout << endl;
    }

    vector<vector<int>> arr_optimal = optimal(arr);
    cout << "Optimal Approach:" << endl;
    for (auto triplet : arr_optimal) {
        for (auto num : triplet) {
            cout << num << " ";
        }
        cout << endl;
    }
}
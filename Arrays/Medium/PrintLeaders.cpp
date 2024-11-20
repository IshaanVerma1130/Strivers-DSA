#include <iostream>
#include <vector>
using namespace std;

vector<int> brute(int arr[], int n) {
    vector<int> ans;

    for (int i = 0; i < n; i++) {
        bool isLeader = true;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                isLeader = false;
            }
        }
        if (isLeader) {
            ans.push_back(arr[i]);
        }
    }
    return ans;
}

vector<int> optimal(int arr[], int n) {
    int maxEl = arr[n - 1];
    vector<int> ans;
    ans.push_back(maxEl);

    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] > maxEl) {
            ans.push_back(arr[i]);
            maxEl = arr[i];
        }
    }

    return ans;
}

int main() {
    int n = 6;
    int arr[n] = {10, 22, 12, 3, 0, 6};

    vector<int> ansOpt = optimal(arr, n);

    for (int i = 0; i < ansOpt.size(); i++) {
        cout << ansOpt[i] << " ";
    }

    cout << endl;

    vector<int> ansBrute = brute(arr, n);

    for (int i = 0; i < ansBrute.size(); i++) {
        cout << ansBrute[i] << " ";
    }
}
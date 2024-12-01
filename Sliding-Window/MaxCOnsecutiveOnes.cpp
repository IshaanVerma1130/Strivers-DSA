#include <iostream>
#include <vector>
using namespace std;

int optimalLess(vector<int> arr, int k) {
    int n = arr.size();
    int i = 0;
    int j = 0;
    int ans = 0;
    int count = 0;

    while (j < n) {
        if (arr[j] == 0) count++;

        while (count > k) {
            if (arr[i] == 0) count--;
            i++;
        }

        if (count <= k) {
            ans = max(ans, j - i + 1);
        }
        j++;
    }
    return ans;
}

int optimalBest(vector<int> arr, int k) {
    int n = arr.size();
    int i = 0;
    int j = 0;
    int ans = 0;
    int count = 0;

    while (j < n) {
        if (arr[j] == 0) count++;
        if (count > k) {
            if (arr[i] == 0) count--;
            i++;
        }
        if (count <= k) {
            ans = max(ans, j - i + 1);
        }
        j++;
    }
    return ans;
}

int main() {
    vector<int> arr = {1, 0, 0, 1, 1, 0, 1, 1, 0, 1};
    int k = 2;
    cout << optimalLess(arr, k) << endl;
    cout << optimalBest(arr, k) << endl;
    return 0;
}
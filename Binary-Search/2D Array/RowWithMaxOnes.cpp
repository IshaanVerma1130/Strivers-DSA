#include <iostream>
#include <vector>
using namespace std;

int brute(vector<vector<int>> mat) {
    int n = mat.size();
    int m = mat[0].size();
    int maxOnes = 0;
    int row = -1;

    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < m; j++) {
            count += mat[i][j];
        }
        if (count > maxOnes) {
            maxOnes = count;
            row = i;
        }
    }

    return row;
}

int firstOcc(vector<int> arr, int k) {
    int low = 0;
    int high = arr.size() - 1;
    int ans = arr.size();

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == k) {
            ans = mid;
            high = mid - 1;
        } else if (arr[mid] > k) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int optimal(vector<vector<int>> mat) {
    int n = mat.size();
    int m = mat[0].size();
    int maxOnes = 0;
    int row = -1;

    for (int i = 0; i < n; i++) {
        int count = m - firstOcc(mat[i], 1);
        if (count > maxOnes) {
            maxOnes = count;
            row = i;
        }
    }

    return row;
}

int main() {
    vector<vector<int>> matrix = {{0}, {0}};
    cout << brute(matrix) << endl;
    cout << optimal(matrix) << endl;
}
#include <bits/stdc++.h>
using namespace std;

// whole matric is flattened. last elecment of first row is < first element of second row
bool optimal(vector<vector<int>> mat, int k) {
    int n = mat.size();
    int m = mat[0].size();

    int low = 0;
    int high = (n * m) - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int row = mid / m;
        int col = mid % m;
        if (mat[row][col] == k) {
            return true;
        } else if (mat[row][col] < k) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return false;
}

int main() {
    vector<vector<int>> mat = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    int k = 100;
    cout << (optimal(mat, k) ? "Found" : "Not Found") << endl;
}
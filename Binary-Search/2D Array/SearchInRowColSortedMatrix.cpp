#include <bits/stdc++.h>
using namespace std;

int optimal(vector<vector<int>> mat, int k) {
    int n = mat.size();
    int m = mat[0].size();

    int row = 0;
    int col = m - 1;

    while (col >= 0 && row < n) {
        if (mat[row][col] == k) {
            return 1;
        } else if (mat[row][col] > k) {
            col--;
        } else {
            row++;
        }
    }
    return 0;
}

int main() {
    vector<vector<int>> matrix = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    cout << optimal(matrix, -5) << endl;
}
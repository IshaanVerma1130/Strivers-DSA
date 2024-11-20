#include <iostream>
#include <vector>
using namespace std;
int maxRowIndex(vector<vector<int>> mat, int col, int n) {
    int maxRow = -1;
    int maxVal = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (mat[i][col] > maxVal) {
            maxVal = mat[i][col];
            maxRow = i;
        }
    }
    return maxRow;
}
vector<int> optimal(vector<vector<int>> mat) {
    int n = mat.size();
    int m = mat[0].size();
    int low = 0;
    int high = m - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int maxRow = maxRowIndex(mat, mid, n);
        int left = mid - 1 > 0 ? mat[maxRow][mid - 1] : INT_MIN;
        int right = mid + 1 < m ? mat[maxRow][mid + 1] : INT_MIN;
        if (mat[maxRow][mid] > left && mat[maxRow][mid] > right) {
            return {maxRow, mid};
        } else if (left > mat[maxRow][mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return {-1, -1};
}
int main() {}
#include <iostream>
#include <vector>
using namespace std;

void markRow(vector<vector<int>> &arr, int i, int m) {
    for (int j = 0; j < m; j++) {
        arr[i][j] = -1;
    }
}
void markCol(vector<vector<int>> &arr, int j, int n) {
    for (int i = 0; i < n; i++) {
        arr[i][j] = -1;
    }
}

vector<vector<int>> brute(vector<vector<int>> arr) {
    int n = arr.size();
    int m = arr[0].size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 0) {
                markRow(arr, i, m);
                markCol(arr, j, n);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == -1) {
                arr[i][j] = 0;
            }
        }
    }
    return arr;
}

vector<vector<int>> better(vector<vector<int>> arr) {
    int n = arr.size();
    int m = arr[0].size();

    vector<int> row(n, 0);
    vector<int> col(m, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 0) {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (row[i] || col[j]) {
                arr[i][j] = 0;
            }
        }
    }
    return arr;
}

vector<vector<int>> optimal(vector<vector<int>> arr) {
    int n = arr.size();
    int m = arr[0].size();
    int col0 = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 0) {
                arr[i][0] = 0;

                if (j == 0)
                    col0 = 0;

                else
                    arr[0][j] = 0;
            }
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (arr[i][j] != 0) {
                if (arr[0][j] == 0 || arr[i][0] == 0) arr[i][j] = 0;
            }
        }
    }

    if (arr[0][0] == 0)
        for (int j = 0; j < m; j++) arr[0][j] = 0;

    if (col0 == 0)
        for (int i = 0; i < n; i++) arr[i][0] = 0;

    return arr;
}

int main() {
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};

    cout << "Brute\n";
    for (auto it : brute(matrix)) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "\n";
    }
    cout << endl;

    cout << "Better\n";
    for (auto it : better(matrix)) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "\n";
    }
    cout << endl;

    cout << "Optimal\n";
    for (auto it : optimal(matrix)) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "\n";
    }
    cout << endl;
}
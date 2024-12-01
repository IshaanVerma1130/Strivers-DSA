#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int optimal(vector<vector<int>> mat) {
    int n = mat[0].size();

    int top = 0;
    int bottom = n - 1;

    while (top < bottom) {
        if (mat[top][bottom]) {
            top++;
        } else if (mat[bottom][top]) {
            bottom--;
        } else {
            top++;
            bottom--;
        }
    }

    if (top > bottom) {
        return -1;
    }

    for (int i = 0; i < n; i++) {
        if (mat[top][i] == 0 && mat[i][top] == 1) {
            continue;
        } else {
            return -1;
        }
    }
    return top;
}
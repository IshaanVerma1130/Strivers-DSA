#include <iostream>
#include <vector>
using namespace std;

int largestAreaInHistorgam(vector<int> arr) {
    stack<int> st;
    int maxArea = 0;

    for (int i = 0; i < arr.size(); i++) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            int el = st.top();
            st.pop();
            int nse = i;
            int pse = st.empty() ? -1 : st.top();
            int width = nse - pse - 1;
            int area = arr[el] * width;
            maxArea = max(maxArea, area);
        }
        st.push(i);
    }

    while (!st.empty()) {
        int el = st.top();
        st.pop();
        int nse = arr.size();
        int pse = st.empty() ? -1 : st.top();
        int width = nse - pse - 1;
        int area = arr[el] * width;
        maxArea = max(maxArea, area);
    }
    return maxArea;
}

int optimal(vector<vector<int>> arr) {
    stack<int> s;
    int n = arr.size();
    int m = arr[0].size();
    int maxArea = 0;
    vector<vector<int>> prefSum(n, vector<int>(m, 0));

    for (int j = 0; j < m; j++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i][j] == 0) {
                sum = 0;
            }
            sum += arr[i][j];
            prefSum[i][j] = sum;
        }
    }

    for (int i = 0; i < n; i++) {
        maxArea = max(maxArea, largestAreaInHistorgam(prefSum[i]));
    }

    return maxArea;
}

int main() {
    vector<vector<int>> arr = {
        {1, 0, 1, 0, 0}, {1, 0, 1, 1, 1}, {1, 1, 1, 1, 1}, {1, 0, 0, 1, 0}};

    cout << optimal(arr);
}
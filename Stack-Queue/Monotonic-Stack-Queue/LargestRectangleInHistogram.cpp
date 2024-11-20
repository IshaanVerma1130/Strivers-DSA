#include <iostream>
#include <vector>
using namespace std;

vector<int> previousSmaller(vector<int> arr) {
    stack<int> st;
    vector<int> ans(arr.size(), -1);

    for (int i = 0; i < arr.size(); i++) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        if (st.empty()) {
            ans[i] = -1;
        } else {
            ans[i] = st.top();
        }
        st.push(i);
    }
    return ans;
}

vector<int> nextSmaller(vector<int> arr) {
    stack<int> st;
    vector<int> ans(arr.size(), -1);

    for (int i = arr.size() - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        if (st.empty()) {
            ans[i] = arr.size();
        } else {
            ans[i] = st.top();
        }
        st.push(i);
    }
    return ans;
}

int brute(vector<int> arr) {
    vector<int> prevSmall = previousSmaller(arr);
    vector<int> nextSmall = nextSmaller(arr);
    int maxArea = 0;

    for (int i = 0; i < arr.size(); i++) {
        int width = nextSmall[i] - prevSmall[i] - 1;
        int area = width * arr[i];
        maxArea = max(maxArea, area);
    }
    return maxArea;
}

int optimal(vector<int> arr) {
    stack<int> st;
    int maxArea = 0;

    for (int i = 0; i < arr.size(); i++) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            int el = st.top();
            st.pop();
            int nse = i;
            int pse = st.empty() ? -1 : st.top();
            int width = nse - pse - 1;
            int area = width * arr[el];
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
        int area = width * arr[el];
        maxArea = max(maxArea, area);
    }
    return maxArea;
}

int main() {
    vector<int> arr = {2, 1, 5, 6, 2, 3};
    cout << brute(arr) << endl;
    return 0;
}
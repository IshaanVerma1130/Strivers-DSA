#include <iostream>
#include <vector>
using namespace std;

vector<int> prevSmallerOrEqual(vector<int> arr) {
    vector<int> ans(arr.size(), -1);
    stack<int> st;

    for (int i = 0; i < arr.size(); i++) {
        while (!st.empty() && arr[i] < arr[st.top()]) {
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
    vector<int> ans(arr.size(), -1);
    stack<int> st;

    for (int i = arr.size() - 1; i >= 0; i--) {
        while (!st.empty() && arr[i] <= arr[st.top()]) {
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

long long optimal(vector<int> arr) {
    vector<int> prev = prevSmallerOrEqual(arr);
    vector<int> next = nextSmaller(arr);

    long long ans = 0;
    for (int i = 0; i < arr.size(); i++) {
        long long left = i - prev[i];
        long long right = next[i] - i;
        ans += ((left * right * arr[i]) % 1000000007) % 1000000007;
    }
    return ans;
}
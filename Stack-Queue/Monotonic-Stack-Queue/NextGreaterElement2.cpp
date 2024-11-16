#include <bits/stdc++.h>
using namespace std;

vector<int> optimal(vector<int> arr) {
    stack<int> st;
    vector<int> ans(arr.size(), -1);
    int n = arr.size();

    for (int i = 2 * n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= arr[i % n]) {
            st.pop();
        }
        if (i < n) {
            if (st.empty())
                ans[i] = -1;
            else
                ans[i] = st.top();
        }
        st.push(arr[i % n]);
    }
    return ans;
}
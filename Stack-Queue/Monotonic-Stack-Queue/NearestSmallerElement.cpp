#include <iostream>
#include <vector>
using namespace std;

vector<int> optimal(vector<int> arr) {
    stack<int> st;
    vector<int> res(arr.size(), -1);

    for (int i = 0; i < arr.size(); i++) {
        while (!st.empty() && arr[i] <= st.top()) {
            st.pop();
        }
        if (st.empty()) {
            res[i] = -1;
        } else {
            res[i] = st.top();
        }
        st.push(arr[i]);
    }
    return res;
}

int main() {
    vector<int> arr = {4, 5, 2, 10, 8};
    vector<int> res = optimal(arr);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    return 0;
}
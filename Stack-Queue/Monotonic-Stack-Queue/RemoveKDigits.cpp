#include <iostream>
#include <vector>
using namespace std;

string optimal(string s, int k) {
    stack<char> st;

    if (k == s.size()) return "0";

    for (int i = 0; i < s.size(); i++) {
        while (!st.empty() && st.top() > s[i] && k > 0) {
            st.pop();
            k--;
        }
        st.push(s[i]);
    }

    while (k--) {
        st.pop();
    }

    string res = "";
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }

    while (res.size() > 1 && res.back() == '0') {
        res.pop_back();
    }

    reverse(res.begin(), res.end());
    if (res.size() == 0) return "0";
    return res;
}
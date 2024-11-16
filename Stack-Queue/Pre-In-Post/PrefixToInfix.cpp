#include <bits/stdc++.h>
using namespace std;

string prefixToInfix(string s) {
    stack<string> st;
    for (int i = s.size() - 1; i >= 0; i--) {
        char c = s[i];
        if (isalpha(c)) {
            st.push(string(1, c));
        } else {
            string s1 = st.top();
            st.pop();
            string s2 = st.top();
            st.pop();
            st.push("(" + s1 + c + s2 + ")");
        }
    }
    return st.top();
}
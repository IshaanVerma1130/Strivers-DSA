#include <bits/stdc++.h>
using namespace std;

int priority(char c) {
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string optimal(string s) {
    string ans = "";
    stack<char> st;
    int i = 0;
    int size = s.size();

    string reverseS = "";
    for (int i = size - 1; i >= 0; i--) {
        if (s[i] == '(')
            reverseS += ')';
        else if (s[i] == ')')
            reverseS += '(';
        else
            reverseS += s[i];
    }

    s = reverseS;

    while (i < size) {
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
            ans += s[i];
        } else if (s[i] == '(') {
            ans += s[i];
        } else if (s[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            st.pop();
        } else {
            if (s[i] == '^') {
                while (!st.empty() && priority(s[i]) <= priority(st.top())) {
                    ans += st.top();
                    st.pop();
                }
            } else {
                while (!st.empty() && priority(s[i]) < priority(st.top())) {
                    ans += st.top();
                    st.pop();
                }
            }
            st.push(s[i]);
        }
        i++;
    }

    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());
    return ans;
}
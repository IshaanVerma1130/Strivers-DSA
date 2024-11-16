#include <bits/stdc++.h>
using namespace std;

string optimal(string s) {
    stack<string> st;
    int n = s.size();

    for (int i = 0; i < n; i++) {
        char c = s[i];

        if (isalpha(c) || isdigit(c)) {
            st.push(string(1, c));
        } else {
            string s2 = st.top();
            st.pop();
            string s1 = st.top();
            st.pop();
            string temp = '(' + s1 + c + s2 + ')';
            st.push(temp);
        }
    }
    return st.top();
}

int main() {
    string s = "hm^q^74-^";
    cout << optimal(s) << endl;
    return 0;

    // (h^m^q^(7-4))
}
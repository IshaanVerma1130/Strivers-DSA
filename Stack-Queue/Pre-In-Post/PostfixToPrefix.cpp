#include <iostream>
#include <vector>
using namespace std;

string optimal(string s) {
    stack<string> st;

    for (int i = 0; i < s.size(); i++) {
        char c = s[i];

        if (isalpha(c)) {
            st.push(string(1, c));
        } else {
            string s2 = st.top();
            st.pop();
            string s1 = st.top();
            st.pop();
            st.push(c + s1 + s2);
        }
    }
    return st.top();
}
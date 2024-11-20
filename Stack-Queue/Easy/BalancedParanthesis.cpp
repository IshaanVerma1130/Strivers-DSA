#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool optimal(string s) {
    stack<char> st;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            st.push(s[i]);
        } else {
            if (st.empty())
                return false;
            char ch = st.top();
            if (s[i] == ')' && ch != '(')
                return false;
            if (s[i] == ']' && ch != '[')
                return false;
            if (s[i] == '}' && ch != '{')
                return false;
            st.pop();
        }
    }
    return st.empty();
}

int main() {
    string s = "(()";
    cout << optimal(s) << endl;
    return 0;
}
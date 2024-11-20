#include <iostream>
#include <vector>
using namespace std;

class MinStackBrute {
    stack<pair<int, int>> st;

   public:
    void push(int x) {
        if (st.empty()) {
            st.push({x, x});
        } else {
            st.push({x, min(x, st.top().second)});
        }
    }

    int getMin() { return st.top().second; }

    int top() { return st.top().first; }
};
class MinStackOptimal {
    stack<int> st;
    long long minEle = LLONG_MAX;

   public:
    void push(int x) {
        if (st.empty()) {
            minEle = x;
            st.push(x);
        } else {
            if (minEle < x) {
                st.push(x);
            } else {
                st.push(2 * x - minEle);
                minEle = x;
            }
        }
    }

    void pop() {
        if (st.empty()) {
            return;
        }
        int x = st.top();
        if (x < minEle) {
            minEle = 2 * minEle - x;
        }
    }

    int top() {
        if (st.empty()) {
            return -1;
        }
        int x = st.top();
        if (x < minEle) {
            return minEle;
        }
        return x;
    }

    int getMin() { return minEle; }
};
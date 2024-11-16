#include <bits/stdc++.h>
using namespace std;

class Stack {
    queue<int> q;

public:
    void push(int x) {
        int size = q.size();
        q.push(x);

        for (int i = 0; i < size; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        q.pop();
    }

    int top() {
        return q.front();
    }
};
#include <bits/stdc++.h>
using namespace std;

class Queue {
    int arr[10];
    int start = -1;
    int end = -1;
    int size = 0;

public:
    void push(int x) {
        if (size == 10) {
            cout << "Queue Overflow" << endl;
            return;
        }
        if (size == 0) {
            start = 0;
            end = 0;
        } else {
            end += 1;
            end %= 10;
        }
        arr[end] = x;
        size += 1;
    }

    int pop() {
        if (size == 0) {
            cout << "Queue Underflow" << endl;
            return;
        }
        int el = arr[start];
        if (size == 1) {
            start = -1;
            end = -1;
        } else {
            start += 1;
            start %= 10;
        }
        size -= 1;
        return el;
    }
    int top() {
        if (size == 0) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[start];
    }
    int size() {
        return size;
    }
};
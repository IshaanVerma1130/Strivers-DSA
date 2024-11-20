#include <iostream>
#include <vector>
using namespace std;

class Stack {
    int arr[10];
    int top = -1;

   public:
    void push(int x) {
        if (top >= 10) {
            cout << "Stack Overflow" << endl;
            return;
        }
        top += 1;
        arr[top] = x;
    }
    int top() {
        if (top < 0) {
            cout << "Stack Underflow" << endl;
            return;
        }
        return arr[top];
    }
    void pop() {
        if (top < 0) {
            cout << "Stack Underflow" << endl;
            return;
        }
        top -= 1;
    }
    int size() { return top + 1; }
};
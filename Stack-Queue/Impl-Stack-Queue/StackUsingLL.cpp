#include <iostream>
#include <vector>
using namespace std;

class Node {
   public:
    int data;
    Node *next;
    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};

class Stack {
    Node *top;
    int size = 0;

   public:
    void push(int x) {
        Node *temp = new Node(x);
        temp->next = top;
        top = temp;
        size++;
    }

    void pop() {
        if (top == nullptr) {
            cout << "Stack is empty" << endl;
            return;
        }
        Node *temp = top;
        top = top->next;
        delete temp;
        size--;
    }

    int top() {
        if (top == nullptr) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return top->data;
    }

    int size() { return size; }
};
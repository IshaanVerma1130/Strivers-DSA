#include <bits/stdc++.h>
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

class Queue {
    Node *head, *tail;
    int size = 0;

public:
    void push(int x) {
        Node *temp = new Node(x);
        if (head == nullptr) {
            head = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
        size++;
    }

    void pop() {
        if (head == nullptr) {
            cout << "Queue is empty\n";
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
        size--;
    }

    int top() {
        if (head == nullptr) {
            cout << "Queue is empty\n";
            return -1;
        }
        return head->data;
    }

    int size() {
        return size;
    }
};
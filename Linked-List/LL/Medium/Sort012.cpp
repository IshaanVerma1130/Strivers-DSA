#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;

    Node *next;

    Node(int data1, Node *next1) {
        data = data1;
        next = next1;
    }

    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

Node *optimal(Node *head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    Node *zero = new Node(-1);
    Node *one = new Node(-1);
    Node *two = new Node(-1);

    Node *zeroHead = zero;
    Node *oneHead = one;
    Node *twoHead = two;

    Node *temp = head;

    while (temp != nullptr) {
        if (temp->data == 0) {
            zero->next = temp;
            zero = zero->next;
        } else if (temp->data == 1) {
            one->next = temp;
            one = one->next;
        } else {
            two->next = temp;
            two = two->next;
        }
        temp = temp->next;
    }

    zero->next = oneHead->next ? oneHead->next : twoHead->next;
    one->next = twoHead->next;
    two->next = nullptr;

    Node *newHead = zeroHead->next;
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return newHead;
}
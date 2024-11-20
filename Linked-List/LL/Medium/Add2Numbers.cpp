#include <iostream>
#include <vector>
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

Node *optimal(Node *l1, Node *l2) {
    Node *dummy = new Node(-1);
    Node *t1 = l1, *t2 = l2, *curr = dummy;
    int carry = 0;

    while (t1 != nullptr || t2 != nullptr) {
        int sum = carry;
        if (t1 != nullptr) {
            sum += t1->data;
        }
        if (t2 != nullptr) {
            sum += t2->data;
        }
        Node *newNode = new Node(sum % 10);
        carry = sum / 10;
        curr->next = newNode;
        curr = curr->next;
        if (t1 != nullptr) {
            t1 = t1->next;
        }
        if (t2 != nullptr) {
            t2 = t2->next;
        }
    }

    if (carry) {
        Node *newNode = new Node(carry);
        curr->next = newNode;
    }
    return dummy->next;
}
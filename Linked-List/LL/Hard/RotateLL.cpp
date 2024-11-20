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

Node *getNthNode(Node *head, int n) {
    n--;
    Node *temp = head;
    while (n--) {
        temp = temp->next;
    }
    return temp;
}

Node *optimal(Node *head, int k) {
    if (head == nullptr || k == 0) {
        return head;
    }

    Node *tail = head;
    int len = 1;
    while (tail->next != nullptr) {
        tail = tail->next;
        len++;
    }

    if (k % len == 0) {
        return head;
    }

    k = k % len;

    tail->next = head;
    Node *newLast = getNthNode(head, len - k);
    head = newLast->next;
    newLast->next = nullptr;
    return head;
}
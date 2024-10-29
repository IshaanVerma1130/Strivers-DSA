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

Node *reverse(Node *head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    Node *prev = nullptr;
    Node *curr = head;

    while (curr != nullptr) {
        Node *front = curr->next;
        curr->next = prev;
        prev = curr;
        curr = front;
    }
    return prev;
}

Node *getKthNode(Node *temp, int k) {
    k -= 1;
    while (k > 0 && temp != nullptr) {
        k--;
        temp = temp->next;
    }
    return temp;
}

Node *optimal(Node *head, int k) {
    Node *temp = head;
    Node *prevNode = nullptr;
    while (temp != nullptr) {
        Node *kthNode = getKthNode(temp, k);
        if (kthNode == nullptr) {
            if (prevNode != nullptr) {
                prevNode->next = temp;
            }
            break;
        }
        Node *nextNode = kthNode->next;
        kthNode->next = nullptr;
        reverse(temp);

        if (temp == head) {
            head = kthNode;
        } else {

            prevNode->next = kthNode;
        }
        prevNode = temp;
        temp = nextNode;
    }
    return head;
}

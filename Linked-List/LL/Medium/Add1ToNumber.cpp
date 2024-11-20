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

Node *better(Node *head) {
    head = reverse(head);
    Node *temp = head;
    int carry = 1;

    while (temp != nullptr) {
        temp->data = temp->data + carry;
        if (temp->data < 10) {
            carry = 0;
            break;
        } else {
            carry = 1;
            temp->data = 0;
        }
        temp = temp->next;
    }

    if (carry == 1) {
        Node *newNode = new Node(1);
        head = reverse(head);

        newNode->next = head;
        return newNode;
    }
    head = reverse(head);
    return head;
}
int recur(Node *head) {
    if (head == nullptr) {
        return 1;
    }

    int carry = recur(head->next);
    head->data = head->data + carry;
    if (head->data < 10) {
        return 0;
    }
    head->data = 0;
    return 1;
}

Node *optimal(Node *head) {
    int carry = recur(head);
    if (carry == 1) {
        Node *newNode = new Node(1);
        newNode->next = head;
        return newNode;
    }
    return head;
}

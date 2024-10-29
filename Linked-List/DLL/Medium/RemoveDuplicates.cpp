#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *back;

public:
    Node(int data1) {
        data = data1;
        next = nullptr;
        back = nullptr;
    }

public:
    Node(int data1, Node *back1, Node *next1) {
        data = data1;
        next = next1;
        back = back1;
    }
};

Node *optimal(Node *head) {
    Node *temp = head;
    while (temp != nullptr) {
        Node *nextNode = temp->next;
        while (nextNode != nullptr && nextNode->data == temp->data) {
            Node *duplicate = nextNode;
            nextNode = nextNode->next;
            delete duplicate;
        }
        temp->next = nextNode;
        if (nextNode != nullptr)
            nextNode->back = temp;
        temp = temp->next;
    }
    return head;
}

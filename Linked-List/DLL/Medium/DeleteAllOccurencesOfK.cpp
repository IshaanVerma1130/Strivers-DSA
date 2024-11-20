#include <iostream>
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

Node *optimal(Node *head, int key) {
    if (head == nullptr)
        return nullptr;

    Node *temp = head;
    while (temp != nullptr) {
        if (temp->data == key) {
            if (temp == head) {
                head = head->next;
            }
            Node *nextNode = temp->next;
            Node *prev = temp->back;
            if (nextNode != nullptr) {
                nextNode->back = prev;
            }
            if (prev != nullptr) {
                prev->next = nextNode;
            }
            delete temp;
            temp = nextNode;
        } else {
            temp = temp->next;
        }
    }
    return head;
}
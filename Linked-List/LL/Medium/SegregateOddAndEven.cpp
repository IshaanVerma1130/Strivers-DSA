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

Node *brute(Node *head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    vector<int> arr;
    Node *temp = head;

    while (temp != nullptr && temp->next != nullptr) {
        arr.push_back(temp->data);
        temp = temp->next->next;
    }
    if (temp != nullptr) {
        arr.push_back(temp->data);
    }

    temp = head->next;

    while (temp != nullptr && temp->next != nullptr) {
        arr.push_back(temp->data);
        temp = temp->next->next;
    }
    if (temp != nullptr) {
        arr.push_back(temp->data);
    }

    temp = head;
    int i = 0;
    while (temp != nullptr) {
        temp->data = arr[i];
        i++;
        temp = temp->next;
    }

    return head;
}

Node *optimal(Node *head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    Node *odd = head;
    Node *even = head->next;
    Node *evenHead = head->next;

    while (even != nullptr && even->next != nullptr) {
        odd->next = odd->next->next;
        even->next = even->next->next;

        odd = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}
#include <iostream>
#include <vector>
using namespace std;

class Node {
   public:
    int data;

    Node *next;
    Node *random;

    Node(int data1) {
        data = data1;
        next = nullptr;
        random = nullptr;
    }
};

Node *brute(Node *head) {
    Node *temp = head;
    unordered_map<Node *, Node *> mp;
    while (temp != nullptr) {
        Node *newNode = new Node(temp->data);
        mp[temp] = newNode;
        temp = temp->next;
    }
    temp = head;
    while (temp != nullptr) {
        Node *copyNode = mp[temp];
        copyNode->next = mp[temp->next];
        copyNode->random = mp[temp->random];
        temp = temp->next;
    }
    return mp[head];
}

Node *optimal(Node *head) {
    if (head == nullptr) return nullptr;
    Node *temp = head;
    while (temp != nullptr) {
        Node *newNode = new Node(temp->data);
        newNode->next = temp->next;
        temp->next = newNode;
        temp = newNode->next;
    }
    temp = head;
    while (temp != nullptr) {
        temp->next->random =
            (temp->random != nullptr) ? temp->random->next : nullptr;
        temp = temp->next->next;
    }
    Node *dummy = new Node(-1);
    Node *res = dummy;
    temp = head;

    while (temp != nullptr) {
        res->next = temp->next;
        temp->next = temp->next->next;
        temp = temp->next;
        res = res->next;
    }

    return dummy->next;
}
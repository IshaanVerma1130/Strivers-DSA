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
        return nullptr;
    }
    Node *temp = head;
    int count = 0;

    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }

    int res = count / 2;
    temp = head;

    while (temp != nullptr) {
        res--;
        if (res == 0) {
            Node *mid = temp->next;
            temp->next = temp->next->next;
            free(mid);
            break;
        }
        temp = temp->next;
    }
    return head;
}

Node *optimal(Node *head) {
    if (head == nullptr || head->next == nullptr) {
        return nullptr;
    }

    Node *slow = head;
    Node *fast = head;
    fast = fast->next->next;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *mid = slow->next;
    slow->next = slow->next->next;
    free(mid);
    return head;
}
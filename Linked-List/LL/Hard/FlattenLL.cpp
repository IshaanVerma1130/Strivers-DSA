#include <iostream>
#include <vector>
using namespace std;

class Node {
   public:
    int data;

    Node *next;
    Node *child;

    Node(int data1, Node *next1) {
        data = data1;
        next = next1;
    }

    Node(int data1) {
        data = data1;
        next = nullptr;
        child = nullptr;
    }
};

Node *merge(Node *list1, Node *list2) {
    Node *dummy = new Node(-1);
    Node *temp = dummy;

    while (list1 != nullptr && list2 != nullptr) {
        if (list1->data < list2->data) {
            temp->child = list1;
            temp = list1;
            list1 = list1->child;
        } else {
            temp->child = list2;
            temp = list2;
            list2 = list2->child;
        }
        temp->next = nullptr;
    }

    if (list1 != nullptr)
        temp->child = list1;
    else
        temp->child = list2;

    return dummy->child;
}

Node *optimal(Node *head) {
    if (head->next == nullptr || head == nullptr) return head;
    Node *mergedHead = optimal(head->next);
    return merge(head, mergedHead);
}

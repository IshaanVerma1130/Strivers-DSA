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

Node *findMiddle(Node *head) {
    Node *slow = head;
    Node *fast = head->next;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

Node *merge(Node *l1, Node *l2) {
    Node *t1 = l1;
    Node *t2 = l2;

    Node *dummy = new Node(-1);
    Node *temp = dummy;

    while (t1 != nullptr && t2 != nullptr) {
        if (t1->data < t2->data) {
            temp->next = t1;
            temp = t1;
            t1 = t1->next;
        } else {
            temp->next = t2;
            temp = t2;
            t2 = t2->next;
        }
    }

    if (t1 != nullptr) {
        temp->next = t1;
    }

    if (t2 != nullptr) {
        temp->next = t2;
    }
    return dummy->next;
}

Node *optimal(Node *head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    Node *middle = findMiddle(head);
    Node *left = head;
    Node *right = middle->next;
    middle->next = nullptr;

    left = optimal(left);
    right = optimal(right);
    return merge(left, right);
}

void printLinkedList(Node *head) {
    Node *temp = head;
    while (temp != nullptr) {
        // Print the data of the current node
        cout << temp->data << " ";
        // Move to the next node
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Linked List: 3 2 5 4 1
    Node *head = new Node(3);
    head->next = new Node(2);
    head->next->next = new Node(5);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(1);

    cout << "Original Linked List: ";
    printLinkedList(head);

    // Sort the linked list
    head = optimal(head);

    cout << "Sorted Linked List: ";
    printLinkedList(head);

    return 0;
}
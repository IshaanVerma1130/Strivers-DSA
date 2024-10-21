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

Node *optimal(Node *head, int n) {
    Node *fast = head;

    while (n--) {
        fast = fast->next;
    }
    if (fast == nullptr) {
        return head->next;
    }

    Node *slow = head;
    while (fast->next != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }
    Node *delNode = slow->next;
    slow->next = slow->next->next;
    delete delNode;
    return head;
}

void printLL(Node *head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int N = 2;
    Node *head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);
    head->next->next->next->next = new Node(arr[4]);

    // Delete the Nth node from the end
    // and print the modified linked list
    head = optimal(head, N);
    printLL(head);
}
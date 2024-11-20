

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

Node *iterative(Node *head) {
    if (head == nullptr) return nullptr;
    if (head->next == nullptr) return head;

    Node *prev = nullptr;
    Node *current = head;

    while (current != nullptr) {
        Node *front = current->next;
        current->next = prev;
        prev = current;
        current = front;
    }
    return prev;
}

Node *recursive(Node *head) {
    if (head == nullptr || head->next == nullptr) return head;
    Node *newHead = recursive(head->next);
    Node *front = head->next;
    front->next = head;
    head->next = nullptr;
    return newHead;
}

// Function to print the linked list
void printLinkedList(Node *head) {
    Node *temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Create a linked list with
    // values 1, 3, 2, and 4
    Node *head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(2);
    head->next->next->next = new Node(4);

    // Print the original linked list
    cout << "Original Linked List: ";
    printLinkedList(head);

    // Reverse the linked list
    head = iterative(head);

    // Print the reversed linked list
    cout << "Reversed Linked List: ";
    printLinkedList(head);

    head = recursive(head);  // Print the reversed linked list
    cout << "Reversed Linked List: ";
    printLinkedList(head);

    return 0;
}

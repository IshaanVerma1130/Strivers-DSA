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

int brute(Node *head) {
    unordered_map<Node *, int> mpp;
    Node *temp = head;
    int timer = 0;
    while (temp != nullptr) {
        if (mpp.find(temp) != mpp.end()) {
            return timer - mpp[temp];
        }
        mpp[temp] = timer;
        timer++;
        temp = temp->next;
    }
    return 0;
}

int optimal(Node *head) {
    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            int count = 1;
            fast = fast->next;
            while (slow != fast) {
                fast = fast->next;
                count++;
            }
            return count;
        };
    }
    return 0;
}

int main() {
    // Create a sample linked
    // list with a loop

    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *fourth = new Node(4);
    Node *fifth = new Node(5);

    // Create a loop from
    // fifth to second
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    // This creates a loop
    fifth->next = second;

    int loopLength = brute(head);
    if (loopLength > 0) {
        cout << "Length of the loop: " << loopLength << endl;
    } else {
        cout << "No loop found in the linked list." << endl;
    }

    loopLength = optimal(head);
    if (loopLength > 0) {
        cout << "Length of the loop: " << loopLength << endl;
    } else {
        cout << "No loop found in the linked list." << endl;
    }

    return 0;
}
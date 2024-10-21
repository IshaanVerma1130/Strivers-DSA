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

Node *convertArr2DLL(vector<int> &arr) {
    Node *head = new Node(arr[0]);
    Node *prev = head;

    for (int i = 1; i < arr.size(); i++) {
        Node *temp = new Node(arr[i], prev, nullptr);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void printDLL(Node *head) {
    Node *temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *removeHead(Node *head) {
    if (head == nullptr || head->next == nullptr) {
        return nullptr;
    }
    Node *temp = head;
    head = head->next;
    head->back = nullptr;
    temp->next = nullptr;
    free(temp);
    return head;
}

Node *removeTail(Node *head) {
    if (head == nullptr || head->next == nullptr) {
        return nullptr;
    }
    Node *tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
    }
    Node *prev = tail->back;
    prev->next = nullptr;
    tail->back = nullptr;
    free(tail);
    return head;
}

Node *removeKth(Node *head, int k) {
    if (head == nullptr) {
        return nullptr;
    }
    int count = 0;
    Node *temp = head;
    while (temp != nullptr) {
        count++;
        if (count == k)
            break;
        temp = temp->next;
    }

    Node *prev = temp->back;
    Node *front = temp->next;

    if (prev == nullptr && front == nullptr) {
        return nullptr;
    } else if (prev == nullptr) {
        return removeHead(head);
    } else if (front == nullptr) {
        return removeTail(temp);
    }

    prev->next = front;
    front->back = prev;

    temp->next = nullptr;
    temp->back = nullptr;
    free(temp);
    return head;
}

void removeNode(Node *temp) {
    Node *prev = temp->back;
    Node *front = temp->next;

    if (front == nullptr) {
        prev->next = nullptr;
        temp->back = nullptr;
        free(temp);
        return;
    }
    prev->next = front;
    front->back = prev;
    free(temp);
    return;
}

Node *insertBeforHead(Node *head, int val) {
    Node *temp = new Node(val, nullptr, head);
    head->back = temp;
    return temp;
}

Node *insertBeforeTail(Node *head, int val) {
    if (head->next == nullptr) {
        return insertBeforHead(head, val);
    }
    Node *tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
    }
    Node *prev = tail->back;
    Node *temp = new Node(val, prev, tail);
    prev->next = temp;
    tail->back = temp;
    return head;
}

Node *insertBeforeKth(Node *head, int val, int k) {
    if (k == 1)
        return insertBeforHead(head, val);
    Node *temp = head;
    int count = 0;
    while (temp != nullptr) {
        count++;
        if (count == k)
            break;
        temp = temp->next;
    }
    Node *prev = temp->back;
    Node *newNode = new Node(val, prev, temp);
    prev->next = newNode;
    temp->back = newNode;
    return head;
}

void insertBeforeNode(Node *temp, int val) {
    Node *prev = temp->back;
    Node *newNode = new Node(val, prev, temp);
    prev->next = newNode;
    temp->back = newNode;
}

Node *reverseDLL(Node *head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    Node *prev = nullptr;
    Node *curr = head;
    while (curr != nullptr) {
        prev = curr->back;
        curr->back = curr->next;
        curr->next = prev;
        curr = curr->back;
    }
    return prev->back;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = convertArr2DLL(arr);
    printDLL(head);
    head = insertBeforHead(head, 0);
    printDLL(head);
    head = insertBeforeTail(head, 6);
    printDLL(head);
    head = insertBeforeKth(head, 10, 3);
    printDLL(head);
    insertBeforeNode(head->next->next, 9);
    printDLL(head);
    head = reverseDLL(head);
    printDLL(head);
}
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;

public:
    Node(int data1, Node *next1) {
        data = data1;
        next = next1;
    }

public:
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

Node *convertArr2LL(vector<int> &arr) {
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++) {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void printLL(Node *head) {
    Node *temp = head;

    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int lengthLL(Node *head) {
    Node *temp = head;
    int count = 0;

    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

int checkIfPresent(Node *head, int val) {
    Node *temp = head;

    while (temp != nullptr) {
        if (temp->data == val)
            return 1;
        temp = temp->next;
    }
    return 0;
}

Node *removeHead(Node *head) {
    if (head == nullptr)
        return head;
    Node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

Node *removeTail(Node *head) {
    if (head == nullptr)
        return head;
    if (head->next == nullptr)
        return nullptr;

    Node *temp = head;

    while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = nullptr;
    return head;
}

Node *removeKth(Node *head, int k) {
    if (head == nullptr)
        return head;
    if (k == 1) {
        Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node *temp = head;
    int count = 0;
    Node *prev = nullptr;

    while (temp != nullptr) {
        count++;
        if (count == k) {
            prev->next = temp->next;
            free(temp);
            return head;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node *removeEl(Node *head, int val) {
    if (head == nullptr)
        return head;
    if (head->data == val) {
        Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node *temp = head;
    Node *prev = nullptr;

    while (temp != nullptr) {
        if (temp->data == val) {
            prev->next = temp->next;
            free(temp);
            return head;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node *insertHead(Node *head, int val) {
    return new Node(val, head);
}

Node *insertTail(Node *head, int val) {
    if (head == nullptr)
        return new Node(val);
    Node *temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = new Node(val);
    return head;
}

Node *insertKth(Node *head, int val, int k) {
    if (head == nullptr) {
        if (k == 1)
            return new Node(val);
        return head;
    }

    if (k == 1)
        return new Node(val, head);

    Node *temp = head;
    int count = 0;

    while (temp != nullptr) {
        count++;
        if (count == k - 1) {
            Node *newNode = new Node(val, temp->next);
            temp->next = newNode;
            return head;
        }
        temp = temp->next;
    }
    return head;
}

Node *insertBeforeVal(Node *head, int newVal, int val) {
    if (head == nullptr) {
        return head;
    }

    if (head->data == val)
        return new Node(newVal, head);

    Node *temp = head;
    int count = 0;

    while (temp->next != nullptr) {
        count++;
        if (temp->next->data == val) {
            Node *newNode = new Node(newVal, temp->next);
            temp->next = newNode;
            return head;
        }
        temp = temp->next;
    }
    return head;
}

int main() {
    vector<int> arr = {2, 5, 8, 7};
    Node *head = convertArr2LL(arr);
    printLL(head);
    head = insertKth(head, 100, 5);
    printLL(head);
    head = insertBeforeVal(head, 101, 100);
    printLL(head);
}
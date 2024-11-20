#include <iostream>
#include <vector>
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

vector<pair<int, int>> brute(Node *head, int k) {
    vector<pair<int, int>> res;
    Node *temp1 = head;
    while (temp1 != nullptr) {
        Node *temp2 = temp1->next;
        while (temp2 != nullptr && (temp1->data + temp2->data) <= k) {
            if ((temp1->data + temp2->data) == k) {
                res.push_back({temp1->data, temp2->data});
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return res;
}

vector<pair<int, int>> optimal(Node *head, int k) {
    vector<pair<int, int>> res;
    Node *left = head;
    Node *right = head;
    while (right->next != nullptr) {
        right = right->next;
    }

    while (left->data < right->data) {
        int sum = left->data + right->data;
        if (sum == k) {
            res.push_back({left->data, right->data});
            left = left->next;
            right = right->back;
        } else if (sum < k) {
            left = left->next;
        } else {
            right = right->back;
        }
    }
    return res;
}
#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class LRUCache {
   public:
    class Node {
       public:
        int key;
        int value;
        Node* next;
        Node* prev;
        Node(int key1, int value1) {
            key = key1;
            value = value1;
        }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    int cap;
    unordered_map<int, Node*> m;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* newNode) {
        Node* temp = head->next;
        head->next = newNode;
        newNode->next = temp;
        newNode->prev = head;
        temp->prev = newNode;
    }

    void deleteNode(Node* delNode) {
        Node* nextNode = delNode->next;
        Node* prevNode = delNode->prev;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    int get(int key) {
        if (m.find(key) != m.end()) {
            Node* temp = m[key];
            deleteNode(temp);
            addNode(temp);
            return temp->value;
        }
        return -1;
    }

    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            Node* temp = m[key];
            temp->value = value;
            deleteNode(temp);
            addNode(temp);
        } else {
            if (m.size() == cap) {
                Node* temp = tail->prev;
                m.erase(temp->key);
                deleteNode(temp);
            }

            Node* newNode = new Node(key, value);
            m[key] = newNode;
            addNode(newNode);
        }
    }
};
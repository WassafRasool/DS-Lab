#include <iostream>
using namespace std;

// Node for linked list
class Node {
public:
    int key;
    Node* next;
    Node(int k) {
        key = k;
        next = nullptr;
    }
};

// Linked list class
class LinkedList {
public:
    Node* head;
    LinkedList() { head = nullptr; }

    void insert(int key) {
        Node* newNode = new Node(key);
        newNode->next = head;
        head = newNode;
    }

    bool search(int key) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->key == key)
                return true;
            temp = temp->next;
        }
        return false;
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->key << " -> ";
            temp = temp->next;
        }
        cout << "NULL";
    }
};

// Hash table with chaining
class HashTable {
    int size;
    LinkedList* table;

public:
    HashTable(int s) {
        size = s;
        table = new LinkedList[size];
    }

    int hash(int key) { return key % size; }

    void insert(int key) { table[hash(key)].insert(key); }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << i << ": ";
            table[i].display();
            cout << endl;
        }
    }
};

int main() {
    HashTable ht(7);
    ht.insert(10);
    ht.insert(20);
    ht.insert(15);
    ht.insert(7);

    ht.display();
}

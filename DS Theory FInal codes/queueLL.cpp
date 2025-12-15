//normal queue
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Queue {
    Node* front;
    Node* rear;

public:
    Queue() {
        front = rear = NULL;
    }

    void enqueue(int val) {
        Node* temp = new Node(val);
        if (rear == NULL)
            front = rear = temp;
        else {
            rear->next = temp;
            rear = temp;
        }
    }

    void dequeue() {
        if (front == NULL)
            cout << "Queue Empty\n";
        else {
            Node* temp = front;
            front = front->next;
            if (front == NULL)
                rear = NULL;
            delete temp;
        }
    }

    void display() {
        if (front == NULL)
            cout << "Queue Empty\n";
        else {
            Node* temp = front;
            while (temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main() {
    Queue q;
    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);
    q.display();
    q.dequeue();
    q.display();
    return 0;
}

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
    Node* top;

public:
    Stack() { top = NULL; }

    void push(int val) {
        Node* temp = new Node;
        temp->data = val;
        temp->next = top;
        top = temp;
    }

    void pop() {
        if (top == NULL)
            cout << "Stack Underflow\n";
        else {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    void display() {
        Node* temp = top;
        if (temp == NULL)
            cout << "Stack is empty\n";
        else {
            while (temp) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main() {
    Stack s;
    s.push(5);
    s.push(10);
    s.push(15);
    s.display();
    s.pop();
    s.display();
    return 0;
}

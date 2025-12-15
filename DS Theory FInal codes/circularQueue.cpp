#include <iostream>
using namespace std;

class CircularQueue {
    int arr[5];
    int front, rear, count;

public:
    CircularQueue() {
        front = 0;
        rear = 0;
        count = 0;
    }

    void enqueue(int val) {
        if (count == 5)
            cout << "Queue Full\n";
        else {
            arr[rear] = val;
            rear = (rear + 1) % 5;
            count++;
        }
    }

    void dequeue() {
        if (count == 0)
            cout << "Queue Empty\n";
        else {
            front = (front + 1) % 5;
            count--;
        }
    }

    void display() {
        if (count == 0)
            cout << "Queue Empty\n";
        else {
            int i = front;
            for (int j = 0; j < count; j++) {
                cout << arr[i] << " ";
                i = (i + 1) % 5;
            }
            cout << endl;
        }
    }
};

int main() {
    CircularQueue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.display();
    q.dequeue();
    q.enqueue(4);
    q.display();
    return 0;
}

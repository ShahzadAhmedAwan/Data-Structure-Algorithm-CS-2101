//   TASK 02 ( Circular Queue )
#include <iostream>
using namespace std;

class CircularQueue {
    int arr[100];
    int front, rear;
    int capacity;
public:
    CircularQueue() {
        front = rear = -1;
        capacity = 100;
    }

    bool isFull() {
        return ((rear + 1) % capacity == front);
    }

    bool isEmpty() {
        return (front == -1);
    }

    void enqueue(int value) {
        if (isFull()) return;
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }
        arr[rear] = value;
    }

    void dequeue() {
        if (isEmpty()) return;
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
    }

    int peek() {
        if (isEmpty()) return -1;
        return arr[front];
    }
};

int main() {
    CircularQueue cq;

    // Simple operations
    cq.enqueue(5);
    cq.enqueue(10);
    cq.enqueue(15);

    cout << "Front: " << cq.peek() << endl; // 5

    cq.dequeue();
    cout << "After dequeue, Front: " << cq.peek() << endl; // 10

    cq.enqueue(20);
    cq.enqueue(25);

    cout << "Front after more enqueues: " << cq.peek() << endl; // 10

    return 0;
}
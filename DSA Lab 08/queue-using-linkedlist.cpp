// TASK 03 ( Queue Using Linked List )
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
    Node* front;
    Node* rear;

public:
    Queue() {
        front = rear = nullptr;
    }

    void enqueue(int value) {
        Node* temp = new Node();
        temp->data = value;
        temp->next = nullptr;

        if (rear == nullptr) {
            front = rear = temp;
        } else {
            rear->next = temp;
            rear = temp;
        }
    }

    void dequeue() {
        if (front == nullptr) return;

        Node* temp = front;
        front = front->next;

        if (front == nullptr) rear = nullptr;

        delete temp;
    }

    int peek() {
        if (front == nullptr) return -1;
        return front->data;
    }

    bool isEmpty() {
        return front == nullptr;
    }
};

int main() {
    Queue q;

    // Test basic operations
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.peek() << endl; // 10

    q.dequeue();
    cout << "After dequeue, Front element: " << q.peek() << endl; // 20

    q.dequeue();
    q.dequeue();

    cout << "After all dequeues, Front element: " << q.peek() << endl; // -1
    cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl; // Yes

    return 0;
}
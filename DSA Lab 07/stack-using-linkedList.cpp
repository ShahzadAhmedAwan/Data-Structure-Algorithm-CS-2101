#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedListStack {
    Node* top;
public:
    LinkedListStack() { top = nullptr; }

    bool isEmpty() { return top == nullptr; }

    void push(int value) {
        Node* temp = new Node();
        temp->data = value;
        temp->next = top;
        top = temp;
        cout << value << " pushed into stack.\n";
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Nothing to pop.\n";
            return;
        }
        Node* temp = top;
        cout << top->data << " popped from stack.\n";
        top = top->next;
        delete temp;
    }

    int peek() {
        if (isEmpty()) return -1;
        return top->data;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Stack elements (top -> bottom): ";
        Node* temp = top;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedListStack stack;
    int choice;

    do {
        cout << "\n--- Linked List Stack Menu ---\n";
        cout << "1. Push\n2. Pop\n3. Peek\n4. Display\n0. Exit\nChoose: ";
        cin >> choice;

        switch(choice) {
            case 1: {
                int val;
                cout << "Enter value to push: ";
                cin >> val;
                stack.push(val);
                break;
            }
            case 2: stack.pop(); break;
            case 3: {
                int val = stack.peek();
                if (val == -1) cout << "Stack is empty.\n";
                else cout << "Top element: " << val << endl;
                break;
            }
            case 4: stack.display(); break;
            case 0: break;
            default: cout << "Invalid choice!\n";
        }
    } while(choice != 0);

    cout << "\n--- Lab Summary ---\n";
    cout << "Stack follows LIFO principle.\n";
    cout << "Linked list stack allows dynamic size.\n";
    return 0;
}

#include <iostream>
using namespace std;

// ========================
// Stack using Array
// ========================
class ArrayStack {
    int arr[100];
    int top;
public:
    ArrayStack() { top = -1; }

    bool isEmpty() { return top == -1; }
    bool isFull() { return top == 99; }

    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << value << endl;
            return;
        }
        arr[++top] = value;
        cout << value << " pushed into stack.\n";
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Nothing to pop.\n";
            return;
        }
        cout << arr[top--] << " popped from stack.\n";
    }

    int peek() {
        if (isEmpty()) return -1;
        return arr[top];
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Stack elements (top -> bottom): ";
        for (int i = top; i >= 0; i--) cout << arr[i] << " ";
        cout << endl;
    }
};

// ========================
// Stack using Linked List
// ========================
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

// ========================
// Main Lab Menu
// ========================
int main() {
    int choice, subChoice;
    cout << "Stack Lab Implementation\n";
    cout << "1. Stack using Array\n2. Stack using Linked List\nChoose implementation: ";
    cin >> choice;

    if (choice == 1) {
        ArrayStack stack;
        do {
            cout << "\n--- Array Stack Menu ---\n";
            cout << "1. Push\n2. Pop\n3. Peek\n4. Display\n0. Exit\nChoose: ";
            cin >> subChoice;

            switch(subChoice) {
                case 1: {
                    int val; cout << "Enter value to push: "; cin >> val;
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
        } while(subChoice != 0);
    }
    else if (choice == 2) {
        LinkedListStack stack;
        do {
            cout << "\n--- Linked List Stack Menu ---\n";
            cout << "1. Push\n2. Pop\n3. Peek\n4. Display\n0. Exit\nChoose: ";
            cin >> subChoice;

            switch(subChoice) {
                case 1: {
                    int val; cout << "Enter value to push: "; cin >> val;
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
        } while(subChoice != 0);
    }
    else {
        cout << "Invalid choice!\n";
    }

    cout << "\n--- Lab Summary ---\n";
    cout << "• Stack follows LIFO principle.\n";
    cout << "• Array-based stack has fixed size.\n";
    cout << "• Linked list stack allows dynamic size.\n";

    return 0;
}

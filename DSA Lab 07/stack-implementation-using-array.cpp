#include <iostream>
using namespace std;

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

int main() {
    ArrayStack stack;
    int choice;

    do {
        cout << "\n--- Array Stack Menu ---\n";
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
    cout << "Array-based stack has fixed size.\n";
    return 0;
}

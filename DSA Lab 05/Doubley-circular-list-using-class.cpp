#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

// Doubly Circular Linked List class
class DoublyCircularList {
private:
    Node* head;

public:
    DoublyCircularList() {
        head = nullptr;
    }

    // Insert at the end
    void insertEnd(int value) {
        Node* newNode = new Node(value);

        // If list is empty
        if (head == nullptr) {
            newNode->next = newNode;
            newNode->prev = newNode;
            head = newNode;
            return;
        }

        // Otherwise insert at the end
        Node* last = head->prev;

        newNode->next = head;   // new node points to head
        newNode->prev = last;   // new node points to last
        last->next = newNode;   // last's next is new node
        head->prev = newNode;   // head's prev is new node
    }

    // Display forward
    void displayForward() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        cout << "Doubly Circular Linked List (Forward): ";
        Node* temp = head;

        do {
            cout << temp->data << "->";
            temp = temp->next;
        } while (temp != head);

        cout << endl;
    }

    // Display backward
    void displayBackward() {
        if (head == nullptr) return;

        cout << "Doubly Circular Linked List (Backward): ";
        Node* temp = head->prev;  // start from last node

        do {
            cout << temp->data << "->";
            temp = temp->prev;
        } while (temp != head->prev);

        cout << endl;
    }
};

// Main function
int main() {
    DoublyCircularList list;

    // Insert nodes
    list.insertEnd(10);
    list.insertEnd(20);
    list.insertEnd(30);
    list.insertEnd(40);

    // Display outputs
    list.displayForward();
    list.displayBackward();

    return 0;
}

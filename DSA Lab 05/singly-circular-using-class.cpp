#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Singly Circular Linked List class
class CircularList {
private:
    Node* head;

public:
    CircularList() {
        head = nullptr;
    }

    // Insert at the end of the list
    void insertEnd(int value) {
        Node* newNode = new Node(value);

        // If list is empty
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;   // circular
            return;
        }

        // Find last node (next points to head)
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }

        // Insert new node after last node
        temp->next = newNode;
        newNode->next = head;   // maintain circular link
    }

    // Display list
    void display() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        cout << "Circular Linked List: ";
        Node* temp = head;

        // Use do-while for circular traversal
        do {
            cout << temp->data << "->";
            temp = temp->next;
        } while (temp != head);

        cout << endl;
    }
};

// Main function
int main() {
    CircularList list;

    // Insert values
    list.insertEnd(10);
    list.insertEnd(20);
    list.insertEnd(30);
    list.insertEnd(40);

    // Display list
    list.display();

    return 0;
}

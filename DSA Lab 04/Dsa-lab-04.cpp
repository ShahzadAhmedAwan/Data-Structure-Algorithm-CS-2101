#include <iostream>
#include <cstdlib> // for system("cls")
using namespace std;

// Node structure for Doubly Linked List
class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

// Doubly Linked List Class
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Insert node at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        cout << "\nInserted " << value << " at the beginning.\n";
    }

    // Insert node at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        cout << "\nInserted " << value << " at the end.\n";
    }

    // Delete node from the beginning
    void deleteFromBeginning() {
        if (!head) {
            cout << "\nList is empty. Nothing to delete.\n";
            return;
        }
        Node* temp = head;
        if (head == tail) { // Only one node
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        cout << "\nDeleted " << temp->data << " from the beginning.\n";
        delete temp;
    }

    // Delete node from the end
    void deleteFromEnd() {
        if (!tail) {
            cout << "\nList is empty. Nothing to delete.\n";
            return;
        }
        Node* temp = tail;
        if (head == tail) { // Only one node
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        cout << "\nDeleted " << temp->data << " from the end.\n";
        delete temp;
    }

    // Display list in forward direction
    void displayForward() {
        if (!head) {
            cout << "\nList is empty.\n";
            return;
        }
        cout << "\nList (Forward): ";
        Node* temp = head;
        while (temp) {
            cout << temp->data;
            if (temp->next) cout << " -> ";
            temp = temp->next;
        }
        cout << " -> NULL\n";
    }

    // Display list in backward direction
    void displayBackward() {
        if (!tail) {
            cout << "\nList is empty.\n";
            return;
        }
        cout << "\nList (Backward): ";
        Node* temp = tail;
        while (temp) {
            cout << temp->data;
            if (temp->prev) cout << " -> ";
            temp = temp->prev;
        }
        cout << " -> NULL\n";
    }
};

// Utility: Pause and clear screen
void pauseAndClear() {
    cout << "\n-------------------------------------------\n";
    cout << "Press Enter to continue...";
    cin.ignore();
    cin.get();
    system("cls"); // Use "clear" if on Linux/Mac
}

// Main Function
int main() {
    DoublyLinkedList dll;
    int choice, value;

    do {
        cout << "===========================================\n";
        cout << "           DOUBLY LINKED LIST MENU          \n";
        cout << "===========================================\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Delete from Beginning\n";
        cout << "4. Delete from End\n";
        cout << "5. Display Forward\n";
        cout << "6. Display Backward\n";
        cout << "0. Exit\n";
        cout << "-------------------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout << "-------------------------------------------\n";

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            dll.insertAtBeginning(value);
            pauseAndClear();
            break;
        case 2:
            cout << "Enter value to insert: ";
            cin >> value;
            dll.insertAtEnd(value);
            pauseAndClear();
            break;
        case 3:
            dll.deleteFromBeginning();
            pauseAndClear();
            break;
        case 4:
            dll.deleteFromEnd();
            pauseAndClear();
            break;
        case 5:
            dll.displayForward();
            pauseAndClear();
            break;
        case 6:
            dll.displayBackward();
            pauseAndClear();
            break;
        case 0:
            cout << "\nExiting Program. Goodbye!\n";
            break;
        default:
            cout << "\nInvalid choice! Try again.\n";
            pauseAndClear();
        }

    } while (choice != 0);

    return 0;
}

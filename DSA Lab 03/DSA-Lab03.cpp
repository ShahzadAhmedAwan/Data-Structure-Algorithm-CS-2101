#include <iostream>
#include <string>
#include <limits>   // for input validation
#include <cstdlib>  // for system("cls")
using namespace std;

// Library ADT class
class Library {
private:
    struct Book {
        int id;
        string title;
        string author;
    };

    Book books[50];   // Maximum 50 books
    int totalBooks;

public:
    // Constructor
    Library() {
        totalBooks = 0;
    }

    // Clear screen utility
    void clearScreen() {
        system("cls");
    }

    // Add a new book
    void addBook() {
        clearScreen();
        if (totalBooks >= 50) {
            cout << "Library is full! Cannot add more books.\n";
            return;
        }

        int id;
        string title, author;

        cout << "Enter Book ID: ";
        while (!(cin >> id)) {
            cout << "Invalid input! Please enter a numeric Book ID: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore();

        cout << "Enter Book Title: ";
        getline(cin, title);

        cout << "Enter Author Name: ";
        getline(cin, author);

        // Check duplicate ID
        for (int i = 0; i < totalBooks; i++) {
            if (books[i].id == id) {
                cout << "\nA book with this ID already exists!\n";
                return;
            }
        }

        books[totalBooks].id = id;
        books[totalBooks].title = title;
        books[totalBooks].author = author;
        totalBooks++;

        cout << "\nBook added successfully!\n";
    }

    // Remove a book by ID
    void removeBook() {
        clearScreen();
        if (totalBooks == 0) {
            cout << "Library is empty! No books to remove.\n";
            return;
        }

        int id;
        cout << "Enter Book ID to remove: ";
        while (!(cin >> id)) {
            cout << "Invalid input! Enter a valid numeric ID: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        bool found = false;
        for (int i = 0; i < totalBooks; i++) {
            if (books[i].id == id) {
                found = true;
                for (int j = i; j < totalBooks - 1; j++) {
                    books[j] = books[j + 1];
                }
                totalBooks--;
                cout << "\nBook with ID " << id << " removed successfully.\n";
                break;
            }
        }
        if (!found)
            cout << "\nBook not found!\n";
    }

    // Search a book by ID
    void searchBook() {
        clearScreen();
        if (totalBooks == 0) {
            cout << "Library is empty! No books to search.\n";
            return;
        }

        int id;
        cout << "Enter Book ID to search: ";
        while (!(cin >> id)) {
            cout << "Invalid input! Enter a valid numeric ID: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        bool found = false;
        for (int i = 0; i < totalBooks; i++) {
            if (books[i].id == id) {
                cout << "\nBook Found:\n";
                cout << "---------------------------------\n";
                cout << "ID: " << books[i].id << endl;
                cout << "Title: " << books[i].title << endl;
                cout << "Author: " << books[i].author << endl;
                cout << "---------------------------------\n";
                found = true;
                break;
            }
        }
        if (!found)
            cout << "\nBook not found in the library.\n";
    }

    // Display all books
    void displayBooks() {
        clearScreen();
        cout << "========== Library Book List ==========\n";
        if (totalBooks == 0) {
            cout << "No books currently in the library.\n";
        } else {
            for (int i = 0; i < totalBooks; i++) {
                cout << i + 1 << ". ID: " << books[i].id
                     << " | Title: " << books[i].title
                     << " | Author: " << books[i].author << endl;
            }
        }
        cout << "=======================================\n";
    }

    // Display total book count
    void countBooks() {
        cout << "\nTotal books in library: " << totalBooks << endl;
    }
};

// ================= MAIN PROGRAM ===================
int main() {
    Library myLibrary;
    int choice;

    do {
        myLibrary.clearScreen();
        cout << "========== LIBRARY MANAGEMENT SYSTEM ==========\n";
        cout << "1. Add a new book\n";
        cout << "2. Remove a book\n";
        cout << "3. Search for a book\n";
        cout << "4. Display all books\n";
        cout << "5. Show total book count\n";
        cout << "6. Exit\n";
        cout << "==============================================\n";
        cout << "Enter your choice: ";

        // Input validation for menu choice
        while (!(cin >> choice)) {
            cout << "Invalid choice! Please enter a number between 1 and 6: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (choice) {
        case 1:
            myLibrary.addBook();
            break;
        case 2:
            myLibrary.removeBook();
            break;
        case 3:
            myLibrary.searchBook();
            break;
        case 4:
            myLibrary.displayBooks();
            break;
        case 5:
            myLibrary.countBooks();
            break;
        case 6:
            cout << "\nExiting... Thank you for using the Library ADT!\n";
            break;
        default:
            cout << "\nInvalid option! Please try again.\n";
        }

        if (choice != 6) {
            cout << "\nPress Enter to return to menu...";
            cin.ignore();
            cin.get();
        }

    } while (choice != 6);

    return 0;
}

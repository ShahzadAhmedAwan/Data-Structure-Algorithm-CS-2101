#include <iostream>
using namespace std;

int main() {
    int numbers[5];         // Declare an array of 5 integers
    int *ptr = numbers;     // Pointer pointing to the first element of the array
    int sum = 0, max;

    cout << "Enter 5 numbers: " << endl;

    // Input using pointer
    for (int i = 0; i < 5; i++) {
        cout << "Number " << i + 1 << ": ";
        cin >> *(ptr + i);   // Using pointer arithmetic to access array elements
    }

    // Initialize max with the first element
    max = *ptr;

    // Calculate sum and find maximum using pointer
    for (int i = 0; i < 5; i++) {
        sum += *(ptr + i);         // Add value at address (ptr + i)
        if (*(ptr + i) > max)
            max = *(ptr + i);
    }

    // Display entered numbers
    cout << "\nYou entered: ";
    for (int i = 0; i < 5; i++) {
        cout << *(ptr + i) << " ";
    }

    cout << "\nSum of numbers = " << sum;
    cout << "\nMaximum number = " << max << endl;

    return 0;
}

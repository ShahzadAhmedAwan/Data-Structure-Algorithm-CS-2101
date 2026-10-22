#include <iostream>
using namespace std;

int main() {
    int numbers[5];  // Declare an array of 5 integers
    int sum = 0, max;

    cout << "Enter 5 numbers: " << endl;

    // Input values into the array
    for (int i = 0; i < 5; i++) {
        cout << "Number " << i + 1 << ": ";
        cin >> numbers[i];
    }

    // Initialize max with the first element
    max = numbers[0];

    // Calculate sum and find maximum
    for (int i = 0; i < 5; i++) {
        sum += numbers[i];
        if (numbers[i] > max)
            max = numbers[i];
    }

    // Display results
    cout << "\nYou entered: ";
    for (int i = 0; i < 5; i++) {
        cout << numbers[i] << " ";
    }

    cout << "\nSum of numbers = " << sum;
    cout << "\nMaximum number = " << max << endl;

    return 0;
}


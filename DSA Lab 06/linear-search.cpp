#include <iostream>
using namespace std;

// Linear Search Function with step-by-step simulation
int linearSearch(int arr[], int n, int key) {
    cout << "\nStarting Linear Search for " << key << "...\n\n";

    for (int i = 0; i < n; i++) {
        cout << "Checking index " << i << ": " << arr[i] << " ";
        if (arr[i] == key) {
            cout << "--> Found!\n";
            return i;  // element found
        } else {
            cout << "--> Not this one.\n";
        }
    }

    return -1; // element not found
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int key;
    cout << "Enter the element to search for: ";
    cin >> key;

    int result = linearSearch(arr, n, key);

    if (result != -1)
        cout << "\nResult: Element " << key << " found at index " << result << ".\n";
    else
        cout << "\nResult: Element " << key << " not found in the array.\n";

    return 0;
}

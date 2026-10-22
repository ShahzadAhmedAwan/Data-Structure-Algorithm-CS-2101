#include <iostream>
using namespace std;

void sortArray(int arr[], int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
}

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n-1;
    while (low <= high) {
        int mid = low + (high - low)/2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int original[n], arr[n];
    cout << "Enter elements: ()we will sort and search):";
    for (int i = 0; i < n; i++) {
        cin >> original[i];
        arr[i] = original[i]; // copy for sorting
    }

    // Sort the copy
    sortArray(arr, n);

    int key;
    cout << "Enter element to search: ";
    cin >> key;

    int resultSorted = binarySearch(arr, n, key);

    if (resultSorted != -1) {
        // Find index in original array
        int originalIndex = -1;
        for (int i = 0; i < n; i++) {
            if (original[i] == key) {
                originalIndex = i;
                break;
            }
        }
        cout << "Element " << key << " found at index " << originalIndex << " in the original array.\n";
    } else {
        cout << "Element " << key << " not found.\n";
    }

    return 0;
}

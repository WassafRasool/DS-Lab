#include <iostream>
using namespace std;

// Heapify a subtree rooted at index i in array arr of size n (Heapify Down)
void heapifyDown(int arr[], int n, int i) {
    int largest = i;           // Initialize largest as root
    int left = 2 * i + 1;      // left child index
    int right = 2 * i + 2;     // right child index

    // If left child exists and is greater than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child exists and is greater than current largest
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root, swap and continue heapifying
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapifyDown(arr, n, largest);
    }
}

// Heap Sort function
void heapSort(int arr[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)//i = n/2 -1 is used to ignore the leaf nodes (nodes that have no children)
        heapifyDown(arr, n, i);

    // Extract elements one by one from heap
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);      // Move current root to end
        heapifyDown(arr, i, 0);    // Heapify reduced heap
    }
}

// Utility function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {20, 5, 15, 10, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    heapSort(arr, n);

    cout << "Sorted array:   ";
    printArray(arr, n);

    return 0;
}

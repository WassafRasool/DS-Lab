#include <iostream>
using namespace std;

void mergeArray(int arr[], int left, int mid, int right) {
    int size1 = mid - left + 1;
    int size2 = right - mid;

    int leftArr[size1], rightArr[size2];

    for (int i = 0; i < size1; i++)
        leftArr[i] = arr[left + i];

    for (int j = 0; j < size2; j++)
        rightArr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < size1 && j < size2) {
        if (leftArr[i] <= rightArr[j])
            arr[k++] = leftArr[i++];
        else
            arr[k++] = rightArr[j++];
    }

    while (i < size1)
        arr[k++] = leftArr[i++];

    while (j < size2)
        arr[k++] = rightArr[j++];
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        mergeArray(arr, left, mid, right);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Before sorting: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    mergeSort(arr, 0, size - 1);

    cout << "After sorting:  ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}

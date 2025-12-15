#include <iostream>
#include <vector>
using namespace std;

int getMax(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > maxVal)
            maxVal = arr[i];
    return maxVal;
}

void radixSort(int arr[], int n) {
    int maxVal = getMax(arr, n);
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        vector<int> bucket[10];
        for (int i = 0; i < n; i++) {
            int digit = (arr[i] / exp) % 10;
            bucket[digit].push_back(arr[i]);
        }
        int idx = 0;
        for (int d = 0; d < 10; d++) {
            for (int i = 0; i < bucket[d].size(); i++) {
                arr[idx++] = bucket[d][i];
            }
        }
    }
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before sorting: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    radixSort(arr, n);

    cout << "After sorting:  ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}

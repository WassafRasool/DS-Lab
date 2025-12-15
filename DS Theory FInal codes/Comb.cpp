#include <iostream>
using namespace std;

void combSort(int arr[], int n) {
    int gap = n;
    bool sorted = true;            // start true so we can enter while(sorted)
    const float shrink = 1.3;

    while (sorted) {               // outer loop now uses while(sorted)
        sorted = false;            // assume not sorted for this pass

        gap = int(gap / shrink);
        if (gap <= 1) {
            gap = 1;
            sorted = true;         // force at least one final pass
        }

        for (int i = 0; i + gap < n; i++) {   // unchanged inner for loop
            if (arr[i] > arr[i + gap]) {
                swap(arr[i], arr[i + gap]);
                sorted = true;     // found a swap → need another pass
            }
        }
    }
}

int main() {
    int arr[] = {30, 10, 50, 20, 40};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    combSort(arr, n);

    cout << "Sorted:   ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}

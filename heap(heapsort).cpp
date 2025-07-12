#include <bits/stdc++.h>
using namespace std;

class MaxHeap {
public:
    // Heapify a subtree rooted at index i, n is the size of the heap
    void maxHeapify(int arr[], int n, int i) {
        int largest = i;
        int l = 2 * i + 1; // left child
        int r = 2 * i + 2; // right child

        if (l < n && arr[l] > arr[largest])
            largest = l;
        if (r < n && arr[r] > arr[largest])
            largest = r;

        if (largest != i) {
            swap(arr[i], arr[largest]);
            maxHeapify(arr, n, largest);
        }
    }

    // Main function to perform heap sort
    void heapSort(int arr[], int n) {
        // Step 1: Build MaxHeap
        for (int i = n / 2 - 1; i >= 0; i--)
            maxHeapify(arr, n, i);

        // Step 2: Extract elements one by one from the heap
        for (int i = n - 1; i > 0; i--) {
            // Move current root to end
            swap(arr[0], arr[i]);

            // call maxHeapify on the reduced heap
            maxHeapify(arr, i, 0);
        }
    }
};

int main() {
    int arr[] = {12, 3, 17, 8, 34, 25, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    MaxHeap h;
    h.heapSort(arr, n);

    cout << "Sorted array (ascending): ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}

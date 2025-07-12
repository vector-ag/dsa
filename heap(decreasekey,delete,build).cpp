#include <bits/stdc++.h>
using namespace std;

class MinHeap {
    int* arr;
    int size;
    int capacity;

public:
    // Constructor
    MinHeap(int c) {
        arr = new int[c];
        size = 0;
        capacity = c;
    }

    // Helper functions
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }
    int parent(int i) { return (i - 1) / 2; }

    // Insert a new key
    void insert(int x) {
        if (size == capacity) {
            cout << "Heap overflow\n";
            return;
        }

        // Insert at the end
        size++;
        int i = size - 1;
        arr[i] = x;

        // Fix the min heap property
        while (i != 0 && arr[parent(i)] > arr[i]) {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    // Decrease key at index i to new_val
    void decreaseKey(int i, int new_val) {
        arr[i] = new_val;
        while (i != 0 && arr[parent(i)] > arr[i]) {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    // Extract the root (minimum element)
    int extractMin() {
        if (size <= 0)
            return INT_MAX;
        if (size == 1) {
            size--;
            return arr[0];
        }

        // Store the minimum value, and remove it from heap
        int root = arr[0];
        arr[0] = arr[size - 1];
        size--;
        minHeapify(0);

        return root;
    }

    // Delete key at index i
    void deleteKey(int i) {
        decreaseKey(i, INT_MIN);
        extractMin();
    }

    // Heapify a subtree with root at given index
    void minHeapify(int i) {
        int l = left(i);
        int r = right(i);
        int smallest = i;

        if (l < size && arr[l] < arr[smallest])
            smallest = l;
        if (r < size && arr[r] < arr[smallest])
            smallest = r;
        if (smallest != i) {
            swap(arr[i], arr[smallest]);
            minHeapify(smallest);
        }
    }

    // Build heap from an array
    void buildHeap(int input[], int n) {
        if (n > capacity) {
            cout << "Input array too large for heap capacity\n";
            return;
        }

        size = n;
        for (int i = 0; i < n; i++)
            arr[i] = input[i];

        for (int i = parent(size - 1); i >= 0; i--)
            minHeapify(i);
    }

    // Print heap
    void printHeap() {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    // Destructor
    ~MinHeap() {
        delete[] arr;
    }
};

int main() {
    MinHeap h(15);

    h.insert(30);
    h.insert(20);
    h.insert(10);
    h.insert(5);

    cout << "Heap after inserts: ";
    h.printHeap();

    h.decreaseKey(2, 1);
    cout << "After decreaseKey(2, 1): ";
    h.printHeap();

    h.deleteKey(1);
    cout << "After deleteKey(1): ";
    h.printHeap();

    int input[] = {40, 20, 30, 10, 5, 15};
    h.buildHeap(input, 6);
    cout << "After buildHeap: ";
    h.printHeap();

    return 0;
}

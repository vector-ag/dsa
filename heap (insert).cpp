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

    // Insert function
    void insert(int x) {
        if (size == capacity) {
            cout << "Heap overflow\n";
            return;
        }

        // First insert at end
        size++;
        int i = size - 1;
        arr[i] = x;

        // Fix the min heap property
        while (i != 0 && arr[parent(i)] > arr[i]) {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
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
    MinHeap h(10);
    h.insert(30);
    h.insert(20);
    h.insert(10);
    h.insert(5);

    cout << "Heap contents: ";
    h.printHeap();

    return 0;
}

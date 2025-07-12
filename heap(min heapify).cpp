#include <bits/stdc++.h>
using namespace std;

class MinHeap {
    int* arr;
    int size;
    int capacity;

public:
    MinHeap(int c) {
        arr = new int[c];
        size = 0;
        capacity = c;
    }

    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }
    int parent(int i) { return (i - 1) / 2; }

    void insert(int x) {
        if (size == capacity) {
            cout << "Heap overflow\n";
            return;
        }
        int i = size++;
        arr[i] = x;
        while (i != 0 && arr[parent(i)] > arr[i]) {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    void minheapify(int i) {
        int lt = left(i), rt = right(i);
        int smallest = i;
        if (lt < size && arr[lt] < arr[smallest])
            smallest = lt;
        if (rt < size && arr[rt] < arr[smallest])
            smallest = rt;
        if (smallest != i) {
            swap(arr[i], arr[smallest]);
            minheapify(smallest);
        }
    }

    int deleteMin() {
        if (size <= 0) {
            cout << "Heap underflow\n";
            return INT_MAX;
        }
        if (size == 1) {
            return arr[--size];
        }
        int root = arr[0];
        arr[0] = arr[--size];
        minheapify(0);
        return root;
    }

    void printHeap() {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    ~MinHeap() {
        delete[] arr;
    }
};
int main() {
    MinHeap h(10);

    // Inserting elements
    h.insert(30);
    h.insert(20);
    h.insert(10);
    h.insert(5);
    h.insert(15);

    cout << "Initial heap: ";
    h.printHeap();

    // Deleting min element
    cout << "Deleted min: " << h.deleteMin() << endl;
    cout << "Heap after deletion: ";
    h.printHeap();

    // Insert again
    h.insert(2);
    cout << "Heap after inserting 2: ";
    h.printHeap();

    return 0;
}
 
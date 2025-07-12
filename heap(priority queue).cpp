// priority queue is basically a heap data structure
#include<bits/stdc++.h>
using namespace std;

int main(){
    priority_queue<int> pq; // Max-Heap by default

    pq.push(10);
    pq.push(20);
    pq.push(5);
    pq.push(15);

    cout << "Top element (max): " << pq.top() << endl; // Should print 20

    pq.pop(); // Remove the top element (20)
    cout << "Top element after pop: " << pq.top() << endl; // Should print 15

    // create min heap using priority queue
    priority_queue<int, vector<int>, greater<int>> min_pq; // Min-Heap
    min_pq.push(10);
    min_pq.push(20);
    min_pq.push(5);
    min_pq.push(15);
    cout << "Top element (min): " << min_pq.top() << endl; // Should print 5
    min_pq.pop(); // Remove the top element (5)
    cout << "Top element after pop: " << min_pq.top() << endl; // Should print 10


    // priority queue using array
    int arr[] = {10, 20, 5, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    priority_queue<int> pq_arr(arr, arr + n); // Max-Heap from array
    cout << "Top element from array-based pq: " << pq_arr.top() << endl; // Should print 20
    pq_arr.pop(); // Remove the top element (20)
    cout << "Top element after pop from array-based pq: " << pq_arr.top() << endl; // Should print 15

    // priority queue using vector
    vector<int> vec = {10, 20, 5, 15};
    priority_queue<int> pq_vec(vec.begin(), vec.end()); // Max-Heap from vector
    cout << "Top element from vector-based pq: " << pq_vec.top() << endl; // Should print 20
    pq_vec.pop(); // Remove the top element (20)
    cout << "Top element after pop from vector-based pq: " << pq_vec.top() << endl; // Should print 15
    return 0;

    //priority queue using pair
}
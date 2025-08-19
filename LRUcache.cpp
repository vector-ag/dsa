#include <bits/stdc++.h>
using namespace std;

class LRUCache {
private:
    // Doubly linked list node
    struct Node {
        int key, value;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    unordered_map<int, Node*> cache; // key -> node
    Node* head; // dummy head
    Node* tail; // dummy tail

    // Add node right after head
    void addNode(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    // Remove an existing node from the list
    void removeNode(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
    }

    // Move given node to the head (most recently used)
    void moveToHead(Node* node) {
        removeNode(node);
        addNode(node);
    }

    // Pop the least recently used node
    Node* popTail() {
        Node* res = tail->prev;
        removeNode(res);
        return res;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;

        head = new Node(0, 0);
        tail = new Node(0, 0);

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (cache.find(key) == cache.end())
            return -1;

        Node* node = cache[key];
        moveToHead(node); // move accessed node to head
        return node->value;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // Update value
            Node* node = cache[key];
            node->value = value;
            moveToHead(node);
        } else {
            Node* node = new Node(key, value);
            cache[key] = node;
            addNode(node);

            if ((int)cache.size() > capacity) {
                Node* tailNode = popTail();
                cache.erase(tailNode->key);
                delete tailNode;
            }
        }
    }
};

// Example usage
int main() {
    LRUCache lru(2);
    lru.put(1, 1);
    lru.put(2, 2);
    cout << lru.get(1) << "\n"; // returns 1
    lru.put(3, 3);              // evicts key 2
    cout << lru.get(2) << "\n"; // returns -1 (not found)
    lru.put(4, 4);              // evicts key 1
    cout << lru.get(1) << "\n"; // returns -1
    cout << lru.get(3) << "\n"; // returns 3
    cout << lru.get(4) << "\n"; // returns 4
}

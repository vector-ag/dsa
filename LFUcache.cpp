#include <bits/stdc++.h>
using namespace std;

class LFUCache {
private:
    int capacity, minFreq;
    unordered_map<int, pair<int,int>> keyToValFreq; // key -> {value, freq}
    unordered_map<int, list<int>> freqToKeys;       // freq -> list of keys (LRU order within freq)
    unordered_map<int, list<int>::iterator> keyToIter; // key -> iterator in freq list

    void updateFreq(int key) {
        int freq = keyToValFreq[key].second;
        // remove from current freq list
        freqToKeys[freq].erase(keyToIter[key]);

        // if this was the last key in minFreq list, increase minFreq
        if (freqToKeys[freq].empty()) {
            freqToKeys.erase(freq);
            if (minFreq == freq) minFreq++;
        }

        // add to next freq list
        keyToValFreq[key].second++;
        int newFreq = freq + 1;
        freqToKeys[newFreq].push_front(key);
        keyToIter[key] = freqToKeys[newFreq].begin();
    }

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    int get(int key) {
        if (capacity == 0 || keyToValFreq.find(key) == keyToValFreq.end())
            return -1;
        updateFreq(key);
        return keyToValFreq[key].first;
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        if (keyToValFreq.find(key) != keyToValFreq.end()) {
            // update value and frequency
            keyToValFreq[key].first = value;
            updateFreq(key);
            return;
        }

        // if over capacity, evict LFU
        if ((int)keyToValFreq.size() >= capacity) {
            int keyToEvict = freqToKeys[minFreq].back(); // LRU within minFreq
            freqToKeys[minFreq].pop_back();
            if (freqToKeys[minFreq].empty()) freqToKeys.erase(minFreq);

            keyToValFreq.erase(keyToEvict);
            keyToIter.erase(keyToEvict);
        }

        // insert new key
        keyToValFreq[key] = {value, 1};
        freqToKeys[1].push_front(key);
        keyToIter[key] = freqToKeys[1].begin();
        minFreq = 1; // new key always has freq 1
    }
};

// Example usage
int main() {
    LFUCache lfu(2);
    lfu.put(1, 1);
    lfu.put(2, 2);
    cout << lfu.get(1) << "\n"; // returns 1
    lfu.put(3, 3);              // evicts key 2 (LFU)
    cout << lfu.get(2) << "\n"; // returns -1
    cout << lfu.get(3) << "\n"; // returns 3
    lfu.put(4, 4);              // evicts key 1
    cout << lfu.get(1) << "\n"; // returns -1
    cout << lfu.get(3) << "\n"; // returns 3
    cout << lfu.get(4) << "\n"; // returns 4
}

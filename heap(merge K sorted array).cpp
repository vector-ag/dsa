// merge k sorted arrays
// Time complexity: O(n log k)
#include <bits/stdc++.h>
using namespace std;

struct triplet{
    int val; // value of the element
    int arrIndex; // index of the array from which the element is taken
    int index; // index of the element in that array

    triplet(int v, int aI, int i) : val(v), arrIndex(aI), index(i) {}
};
struct mycmp{
    bool operator()(const triplet &a, const triplet &b) {
        return a.val > b.val; // Min-heap based on value
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>>& arrays) {
    priority_queue<triplet, vector<triplet>, mycmp> minHeap;
    vector<int> result;

    // Initialize the min-heap with the first element of each array
    for (int i = 0; i < arrays.size(); i++) {
        if (!arrays[i].empty()) {
            minHeap.push(triplet(arrays[i][0], i, 0));
        }
    }

    // Process the min-heap
    while (!minHeap.empty()) {
        triplet current = minHeap.top();
        minHeap.pop();
        result.push_back(current.val);
        int ap = current.arrIndex; // array index
        int vp = current.index; // value index
        // If there is a next element in the same array, add it to the heap
        if(vp + 1 < arrays[ap].size()) {
            triplet t(arrays[ap][vp + 1], ap, vp + 1);
            minHeap.push(t);
        }
    }

    return result;
}
int main() {
    vector<vector<int>> arrays = {
        {1, 4, 7},
        {2, 5, 8},
        {3, 6, 9}
    };

    vector<int> mergedArray = mergeKSortedArrays(arrays);

    cout << "Merged array: ";
    for (int num : mergedArray) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
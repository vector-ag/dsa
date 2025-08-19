#include <bits/stdc++.h>
using namespace std;

void add(map<int, int>& freq, map<int, set<int>, greater<int>>& freq_to_value, int x) {
    int old_freq = freq[x]++;
    if (old_freq > 0) {
        freq_to_value[old_freq].erase(x);
        if (freq_to_value[old_freq].empty()) {
            freq_to_value.erase(old_freq);
        }
    }
    freq_to_value[old_freq + 1].insert(x);
}

void remove(map<int, int>& freq, map<int, set<int>, greater<int>>& freq_to_value, int x) {
    int old_freq = freq[x]--;
    freq_to_value[old_freq].erase(x);
    if (freq_to_value[old_freq].empty()) {
        freq_to_value.erase(old_freq);
    }
    if (freq[x] > 0) {
        freq_to_value[old_freq - 1].insert(x);
    } else {
        freq.erase(x);
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    map<int, int> freq;
    map<int, set<int>, greater<int>> freq_to_value;
    vector<int> res;

    // Initialize first window
    for (int i = 0; i < k; i++) {
        add(freq, freq_to_value, v[i]);
    }
    res.push_back(*freq_to_value.begin()->second.begin());

    // Slide the window
    for (int i = k; i < n; ++i) {
        remove(freq, freq_to_value, v[i - k]);
        add(freq, freq_to_value, v[i]);
        res.push_back(*freq_to_value.begin()->second.begin());
    }

    // Output result
    for (int x : res) cout << x << " ";
    cout << endl;
    return 0;
}

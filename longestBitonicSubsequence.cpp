#include<bits/stdc++.h>
using namespace std;
// Function to find the length of the longest bitonic subsequence
int longestBitonicSubsequence(vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return 0;
    vector<int> lis(n, 1), lds(n, 1);
    // Calculate LIS ending at each index
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                lis[i] = max(lis[i], lis[j] + 1);
            }
        }
    }
    // Calculate LDS starting at each index
    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j > i; j--) {
            if (arr[i] > arr[j]) {
                lds[i] = max(lds[i], lds[j] + 1);
            }
        }
    }
    // Find the maximum length of bitonic subsequence
    int maxLength = 0;
    for (int i = 0; i < n; i++) {
        maxLength = max(maxLength, lis[i] + lds[i] - 1);
    }
    return maxLength;
}      

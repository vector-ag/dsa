#include<bits/stdc++.h>
using namespace std;
int lis(vector<int>&a, int n) {
    vector<int> dp(n, 1),hash(n);
    int mx = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[i] > a[j]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        mx = max(mx, dp[i]);
    }
    return mx;
}
vector<int>printlis(vector<int>&a, int n) {
    vector<int> dp(n, 1),hash(n);
    int mx = 1;
    int lastindex = 0; // To track the last index of LIS
    for(int i=0;i<n;i++){
        hash[i] = i; // Initialize hash to track indices
        for(int j=0;j<i;j++){
            if(a[i] > a[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                hash[i] = j; // Update hash to point to the previous index
                
            }
        }
        if(mx < dp[i]) {
            mx = dp[i];
            lastindex = i; // Update last index of LIS
        }
    }
    vector<int> lis;// To store the LIS elements
    lis.push_back(a[lastindex]); // Start with the last element of LIS 
    while(lastindex != hash[lastindex]) {
        lis.push_back(a[lastindex]);
        lastindex = hash[lastindex]; // Move to the previous index in the LIS   
    }
    
    reverse(lis.begin(), lis.end()); // Reverse to get the correct order
    return lis;
}
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }
    cout << lis(a, n) << endl;
    return 0;
}
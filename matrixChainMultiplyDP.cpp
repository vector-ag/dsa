#include<bits/stdc++.h>
using namespace std;
// using memproization
// Time Complexity: O(n^3)
// Space Complexity: O(n^2)
int findmin(int i,int j,vector<int>&v,vector<vector<int>>&dp){
    if(i == j)return 0;
    if(dp[i][j] != -1)return dp[i][j];
    int ans = INT_MAX;
    for(int k=i;k<j;k++){
        int cost = v[i-1]*v[k]*v[j] + findmin(i,k,v,dp) + findmin(k+1,j,v,dp);
        ans = min(ans,cost);
    }
    return dp[i][j];
}
int matrixChainOrder(vector<int>&v){
    int n = v.size();
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    return findmin(1,n-1,v,dp);
}

// using tabulation
// Time Complexity: O(n^3)
// Space Complexity: O(n^2)

int findminTabulation(vector<int>&v,vector<vector<int>>&dp,int n){
    for(int i=1;i<n;i++){
        dp[i][i] = 0; // cost of multiplying one matrix is zero
    }
    for(int i = n-1;i>=1;i--){
        for(int j= i+1;j<n;j++){
            int ans = INT_MAX;
            for(int k=i;k<j;k++){
                int cost = v[i-1] * v[k] * v[j] + dp[i][k] + dp[k+1][j];
                ans = min(ans, cost);
            }
            dp[i][j] = ans; // store the minimum cost for multiplying matrices from i to j
        }
    }
    return dp[1][n-1]; // return the minimum cost for multiplying all matrices
}

int matrixChainOrderTabulation(vector<int>&v){
    int n= v.size();
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    return findminTabulation(v, dp, n);
}
int main(){
    vector<int>v = {10, 20, 30, 40, 30};
    cout << "Minimum number of multiplications is " << matrixChainOrder(v) << endl;
    return 0;
}
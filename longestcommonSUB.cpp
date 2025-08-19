#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<vector<int>>memo;
    int lcs(string &a,string &b,int n,int m){
        
        if(n == 0 || m == 0)return 0;
        if(memo[n][m] != -1){
            return memo[n][m];
        }
        if(a[n-1]== b[m-1]){
            memo[n][m] = 1 + lcs(a,b,n-1,m-1);
        }
        else{
            memo[n][m] = max(lcs(a,b,n-1,m), lcs(a,b,n,m-1));
        }
        return memo[n][m];
    }
public:
    int longestCommonSubsequence(string a, string b) {
        int n= a.size();
        int m = b.size();
        memo.assign(n+1,vector<int>(m+1,-1));
        return lcs(a,b,n,m);
    }
};
#include<bits/stdc++.h>
using namespace std;

int lcs(string &a,string &b,int n,int m,vector<vector<int>>&dp){
    if(n== 0 || m == 0)return 0;
    if(dp[n][m] != -1)return dp[n][m];
    if(a[n-1] == b[m-1]){
        dp[n][m] = 1 + lcs(a,b,n-1,m-1,dp);
    }
    else{
        dp[n][m] = max(lcs(a,b,n-1,m,dp),lcs(a,b,n,m-1,dp));
    }
    return dp[n][m];
}
int main(){
    string a, b;
    cin >> a >> b;
    int n = a.size();
    int m= b.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    int len = lcs(a,b,n,m,dp);
    string ans = "";
    for(int i=0;i<len;i++){
        ans= ans + '$';
    }
    int i = n,j = m;
    int ind = len-1;
    while(i > 0 && j > 0){
        if(a[i-1] == b[j-1]){
            ans[ind] = a[i-1];
            ind--;
            i--,j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    cout << ans << endl;
}
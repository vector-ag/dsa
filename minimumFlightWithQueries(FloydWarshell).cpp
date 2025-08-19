#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,q;
    cin >> n >> m >> q;
    vector<vector<long long>>dp(n+1,vector<long long>(n+1,1e18));
    for(int i=0;i<m;i++){
        int a,b;
        long long c;
        cin >> a >> b >> c;
        dp[a][b] = min(dp[a][b],c);
        dp[b][a] = min(dp[b][a],c);
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }
    while(q--){
        int a,b;
        cin >> a >> b;
        if(dp[a][b] == 1e18)cout << -1 << endl;
        else{
            cout << dp[a][b] << endl;
        }
    }
}
#include<bits/stdc++.h>
using namespace std;
int solve(int k,int n,vector<int>&v){
    int l = 0,count = 1;
    int r = 1e9;
    while(l < r){
        int mid= l+(r-l)/2;
        for(int i=0;i<=k;i++){
            if(v[i]%k == 0){
                count++;
            }
        }
        
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>v(n);
        for(int i=0;i<n;i++)cin >> v[i];
        int l = 0,r=0;
        for(int i=0;i<n-1;i++){
            if(v[i+1]%v[i] != 0){
                r =  i;
                l++:
            }
        }
        if(l ==  0){
            return 1;
        }
        else{
            int ans = solve(r,n,v);
        }
        
    }
}
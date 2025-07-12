#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define ff first
#define ss second
#define u_b(V,i) upper_bound(V.begin(),V.end(),i)
#define l_b(V,i) lower_bound(V.begin(),V.end(),i)
#define st(a,n) sort(a,a+n)
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define frr(i,a,b) for(int i=a;i>=b;i--)
#define mii map<int,int>
#define vc vector<char>
#define all(a) a.begin(),a.end()
#define stg(a,n) sort(a,a+n,greater<int>())
#define mn(a) min_element(all(a))
#define mx(a) max_element(all(a))
#define vpii vector<pii>
const int M=1e9+7;
const long long  M1=1e18;

int findMin(vector<int>&v) {
    int k = v.size();
    int l = 0,r = k-1;
    int m ;
    while(l!=r && l != r-1){
        m = (l+r)/2;
        if(v[m] <= v[r]){
            r = m;
        }
        if(v[l] <= v[m]){
            l = m;
        }
    }
    return min(v[l],v[r]);
}
signed main(){

std::ios::sync_with_stdio(false);

cin.tie(NULL);

cout.tie(NULL);

    int n;
    cin >> n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    int ans = findMin(v);
    cout << ans << "\n";

}

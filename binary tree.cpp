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

struct Node{
    int key;
    Node*left;
    Node *right;
    Node(int k){
        key = k;
        left = NULL;
        right = NULL;
    }
};
signed main(){

std::ios::sync_with_stdio(false);

cin.tie(NULL);

cout.tie(NULL);

    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);

}

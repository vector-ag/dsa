#include<bits/stdc++.h>
using namespace std;
int power(int a,int n){
    if(n == 0)return 1;
    int p = power(a,n/2);
    p = p*p;
    if(n %2 == 0)return p;
    return p*a;
}
int main(){
    int n,m;
    cin >> n >> m;
    cout << power(n,m) << endl;
}
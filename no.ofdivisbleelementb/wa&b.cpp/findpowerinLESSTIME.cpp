#include<bits/stdc++.h>
using namespace std;

int divisble(int a,int b,int x){
    int l=a,r=b;
    if(b%x == 0){
        r = b;
    }
    else{
        r = ((b/x))*x;
    }
    if(a%x == 0){
        l = a;
    }
    else{
        l = (a/x + 1)*x;
    }
    return (r-l)/x + 1;
}
/// findinfd power in less time complexity;
int power(int a,int n){
    if(n== 0){
        return 1;
    }
    int partial_ans = power(a,n/2);
    partial_ans = (partial_ans*partial_ans);
    if(n%2 == 0){
        return partial_ans;
    }
    return partial_ans*a;
}
int main(){
    cout << power(2,3) << endl;
}
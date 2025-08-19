#include<bits/stdc++.h>
using namespace std;

// Function to compute nCk % MOD using Fermat's Little Theorem
int mod_pow(int base, int exp, int mod) {
    int res = 1;
    while(exp) {
        if (exp % 2) res = res * base % mod;
        base = base * base % mod;
        exp /= 2;
    }
    return res;
}

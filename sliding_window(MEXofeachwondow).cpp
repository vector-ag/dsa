#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    set<int>s;
    for(int i=0;i<n;i++){
        s.insert(i);
    }
    vector<int>res;
    map<int,int>mp;
    for(int i=0;i<k;i++){
        mp[v[i]]++;
        s.erase(v[i]);
    }
    res.push_back(*s.begin());
    int l = 0;
    for(int i=k;i<n;i++){
        int in = v[i];
        int out = v[l];
        mp[in]++;
        mp[out]--;
        if(s.find(in) != s.end()){
            s.erase(in);
        }
        if(mp[out] == 0){
            s.insert(out);
            mp.erase(out);
        }
        l++;
        res.push_back(*s.begin());
    }
    for(int i=0;i<res.size();i++){
        cout << res[i] << " ";
    }
    cout << endl;
}
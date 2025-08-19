#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int ceil(vector<int>&tail,int l,int r,int x){
        while(l<r){
            int mid = l+(r-l)/2;
            if(tail[mid] >= x){
                r = mid;
            }
            else{
                l = mid+1;
            }
        }
        return r;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n  = nums.size();
        vector<int>tail(n);
        tail[0] = nums[0];
        int len = 1;
        for(int i=1;i<n;i++){
            if(nums[i] > tail[len-1]){
                tail[len] = nums[i];
                len++;
            }
            else{
                int c = ceil(tail,0,len-1,nums[i]);
                tail[c] = nums[i];
            }
        }
        return len;
    }
};
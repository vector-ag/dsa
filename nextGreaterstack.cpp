#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmallerOrEqual(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, n);  // Default: no next smaller => n
        stack<int> st;

        for (int i = 0; i < n; ++i) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                ans[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }

    vector<int> prevSmaller(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, -1);  // Default: no prev smaller => -1
        stack<int> st;

        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                ans[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> nextgreaterOrEqual(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, n);  // Default: no next smaller => n
        stack<int> st;

        for (int i = 0; i < n; ++i) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                ans[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }

    vector<int> prevgreater(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, -1);  // Default: no prev smaller => -1
        stack<int> st;

        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                ans[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }

    long long subArrayRanges(vector<int>& arr) {
        int n = arr.size();
        vector<int> next = nextSmallerOrEqual(arr);
        vector<int> prev = prevSmaller(arr);
        long long sum = 0;
        int mod = 1e9 + 7;

        for (int i = 0; i < n; ++i) {
            long long left = i - prev[i];
            long long right = next[i] - i;
            sum = (sum + (arr[i] * left * right));
        }
        vector<int> next1 = nextgreaterOrEqual(arr);
        vector<int> prev1 = prevgreater(arr);
        long long sum1 = 0;

        for (int i = 0; i < n; ++i) {
            long long left = i - prev1[i];
            long long right = next1[i] - i;
            sum1 = (sum1 + (arr[i] * left* right));
        }
        return abs(sum1 - sum);
    }
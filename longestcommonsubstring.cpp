#include<bits/stdc++.h>
using namespace std;
int longestCommonSubstring(string &a, string &b) {
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int maxLength = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                maxLength = max(maxLength, dp[i][j]);
            } else {
                dp[i][j] = 0; // Reset to zero if characters do not match
            }
        }
    }
    return maxLength;
}
// printing the longest common substring;
string printLongestCommonSubstring(string &a, string &b) {
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int maxLength = 0, endIndex = -1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxLength) {
                    maxLength = dp[i][j];
                    endIndex = i - 1; // Store the end index of the substring
                }
            } else {
                dp[i][j] = 0; // Reset to zero if characters do not match
            }
        }
    }

    // Reconstruct the longest common substring
    if (endIndex == -1) return ""; // No common substring found
    return a.substr(endIndex - maxLength + 1, maxLength);
}
int main() {
    string a, b;
    cin >> a >> b;
    cout << longestCommonSubstring(a, b) << endl;
    return 0;
}
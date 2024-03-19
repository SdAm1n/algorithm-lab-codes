// Top Down Approach
// Longest Common Subsequence using dynamic programming
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[1005][1005];

int lcs(int i, int j, string &s1, string &s2) {
    if (i < 0 || j < 0) return 0;

    // memoization
    if (dp[i][j] != -1) return dp[i][j];

    // remove 1 char from s1
    int ans = lcs(i-1, j, s1, s2);
    
    // remove 1 char from s2
    ans = max(ans, lcs(i, j-1, s1, s2));

    // remove 1 char from s1 and s2
    ans = max(ans, lcs(i-1, j-1, s1, s2) + (s1[i] == s2[j]));

    return dp[i][j] = ans;
}

int main() {
    memset(dp, -1, sizeof(dp));
    string s1;
    cin >> s1;
    string s2;
    cin >> s2;

    cout << "Longest common subsequence: " << lcs(s1.size() - 1, s2.size() - 1, s1, s2) << '\n';

    string lcs_string = "";
    cout << "Any longest common subsequence: ";
    int i = s1.size() - 1;
    int j = s2.size() - 1;
    while (i > 0 && j > 0) {
        if (s1[i] == s2[j]) {
            lcs_string = s1[i] + lcs_string;
            i--;
            j--;
        } else if (dp[i-1][j] > dp[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }
    cout << lcs_string << endl;

}
// Rod Cutting using Dynamic Programming
// Top Down Approach
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int dp[1005];

int cut_rod(int len, vector<int>prices){
    if(len == 0) return 0;
    // memoization
    if (dp[len] != -1) return dp[len];
    int ans = 0;
    for (int cut_len = 1; cut_len <= prices.size(); cut_len++) {
        if(len - cut_len >= 0) {
            ans = max(ans, cut_rod(len - cut_len, prices) + prices[cut_len - 1]);
        }
    }
    return dp[len] = ans;
}

int main() {
    memset(dp, -1, sizeof(dp));

    int rod_length;
    cin >> rod_length;
    vector<int>prices;
    for (int i=0; i < rod_length; i++) {
        int x;
        cin >> x;
        prices.push_back(x);
    }

    cout << cut_rod(rod_length, prices) << endl; 
}
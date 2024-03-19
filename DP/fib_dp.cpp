#include <iostream>
#include <cstring>
using namespace std;
const int N = 1e5+10;

int dp[N];

// Top down approach
int fib(int n) {
    if (n == 1) return 1;
    if (n == 0) return 0;
    // memoization
    if(dp[n] != -1) return dp[n];

    return dp[n] = fib(n-1) + fib(n-2);
}

int main() {
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    cout << "Top Down Approach: \n"; 
    cout << "Fib(" << n << "): " << fib(n) << endl;

    // Bottom UP Approach
    dp[0]=0;
    dp[1]=1;
    for (int i=2; i < n; i++) {
        dp[i] = dp[i-1] + dp[i - 2];
    }
}
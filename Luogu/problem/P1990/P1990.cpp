#include <bits/stdc++.h>

using namespace std;

int n, dp[1000009];

int main() {
    dp[1] = 1, dp[2] = 2, dp[3] = 5;
    cin >> n;
    for (int i = 4; i <= n; i++) {
        dp[i] = (dp[i - 1] * 2 + dp[i - 3]) % 10000;
    }
    cout << dp[n] << endl;
    return 0;
}
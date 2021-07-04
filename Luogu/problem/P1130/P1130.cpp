#include<bits/stdc++.h>

using namespace std;

int main() {
    long long n, m, a[2005][2005], f[2005][2005];
    cin >> n >> m;
    for(int i = 1 ; i <= m ; i++) {
        for(int j = 1 ; j <= n ; j++) {
            cin >> a[j][i];
        }
    }
    for(int i = 1 ; i <= n ; i++) {
        f[i-1][0] = f[i-1][m];
        for(int j = 1 ; j <= m ; j++) {
            f[i][j] = a[i][j] + min(f[i-1][j], f[i-1][j-1]);
        }
    }
    long long ans = f[n][1];
    for(int i = 2 ; i <= m ; i++) {
        ans = min(ans, f[n][i]);
    }
    cout << ans << endl;
    return 0;
}

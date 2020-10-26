#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, a[1005][1005], f[1005][1005];
    cin >> n;
    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1 ; j <= i ; j++) {
            cin >> a[i][j];
        }
    }
    f[1][1] = a[1][1];
    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1 ; j <= i+1 ; j++) {
            f[i][j] = a[i][j] + max(f[i-1][j], f[i-1][j-1]);
        }
    }
    int ans = -0x3f3f3f;
    for(int i = 1 ; i <= n ; i++) {
        ans = max(ans, f[n][i]);
    }
    cout << ans << endl;
    return 0;
}

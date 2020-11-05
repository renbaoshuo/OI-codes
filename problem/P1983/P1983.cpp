#include <bits/stdc++.h>

using namespace std;

int  n, m, k, ans, l, a[1005], d[1005], c[1005][1005], f[1005];
bool v[1005][1005];

int dfs(int x) {
    if (f[x]) {
        return f[x];
    }
    for (int i = 1; i <= c[x][0]; i++) {
        f[x] = max(f[x], dfs(c[x][i]));
    }
    return ++f[x];
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a[0];
        for (int j = 1; j <= a[0]; j++) {
            cin >> a[j];
        }
        l = 1;
        for (int j = a[1]; j < a[a[0]]; j++) {
            if (a[l] == j) {
                l++;
            }
            else {
                for (int k = 1; k <= a[0]; k++) {
                    if (!v[a[k]][j]) {
                        int t = a[k];
                        c[t][0]++;
                        c[t][c[t][0]] = j;
                        v[t][j]       = 1;
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dfs(i));
    }
    cout << ans << endl;
    return 0;
}

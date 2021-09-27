#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;

int t, n, m, phi[1000005], cnt, prime[1000005];
bool vis[1000005];

void euler(int n) {
    phi[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!vis[i]) {
            phi[i] = i - 1;
            prime[++cnt] = i;
        }
        for (int j = 1; j <= cnt; j++) {
            if (1ll * i * prime[j] >= n) break;
            vis[i * prime[j]] = true;
            if (i % prime[j]) {
                phi[i * prime[j]] = phi[i] * (prime[j] - 1);
            } else {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
        }
    }
}

int find(int l, int r, int x) {
    int res = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (prime[mid] >= x) {
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin >> t;
    euler(1000000);
    while (t--) {
        memset(vis, 0x00, sizeof(vis));
        cin >> m >> n;
        if (n <= 1000000) {
            int l = find(0, cnt, m);
            for (int i = l; i <= cnt; i++) {
                if (prime[i] > n) break;
                cout << prime[i] << endl;
            }
        } else {
            int l = m + (m & 1);
            if (l == 2) l += 2;
            for (int i = l; i <= n; i += 2) {
                vis[i - m] = true;
            }
            int d = sqrt(n) + 1;
            for (int i = 2; i <= cnt; i++) {
                if (prime[i] > d) break;
                int p = (m - 1) / prime[i] + 1;
                p += !(p & 1);
                if (p == 1) p += 2;
                for (int j = p; j * prime[i] <= n; j++) {
                    vis[j * prime[i] - m] = true;
                }
            }
            for (int i = m; i <= n; i++) {
                if (!vis[i - m]) {
                    cout << i << '\n';
                }
            }
        }
        cout << endl;
    }
    return 0;
}

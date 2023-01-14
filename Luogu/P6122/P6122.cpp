#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;

int n, m, c[N], p[N], f[N << 1], g[N << 1], f2[N], ans;

void update(int u) {
    f[u] = INF;

    if (c[u]) {
        f[u] = 0;
        g[u] = u;
    }

    if (f[u] > f[u << 1] + (f2[u << 1] < 0 ? -1 : 1)) {
        f[u] = f[u << 1] + (f2[u << 1] < 0 ? -1 : 1);
        g[u] = g[u << 1];
    }

    if (f[u] > f[u << 1 | 1] + (f2[u << 1 | 1] < 0 ? -1 : 1)) {
        f[u] = f[u << 1 | 1] + (f2[u << 1 | 1] < 0 ? -1 : 1);
        g[u] = g[u << 1 | 1];
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    std::fill(std::begin(f), std::end(f), INF);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }

    for (int i = 1; i <= m; i++) {
        cin >> p[i];
    }

    for (int i = n; i; i--) {
        update(i);
    }

    for (int i = 1; i <= m; i++) {
        int x = INF,
            y = 0,
            u = p[i],
            t = 0,
            v = 0;

        while (u) {
            if (x > f[u] + t) {
                x = f[u] + t;
                y = g[u];
                v = u;
            }

            t += (f2[u] > 0 ? -1 : 1);
            u >>= 1;
        }

        u = p[i];
        ans += x;

        while (u != v) {
            f2[u]--;
            update(u >>= 1);
        }

        c[y]--;
        update(y);

        while (y != v) {
            f2[y]++;
            update(y >>= 1);
        }

        while (v) {
            update(v);
            v >>= 1;
        }

        cout << ans << ' ';
    }

    cout << endl;

    return 0;
}

#pragma GCC optimize("Ofast")

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

const int N = 1005;

int n, m;
long long g[N][N], l, r;
bool vis[N][N];

bool check(long long x) {
    memset(vis, 0x00, sizeof(vis));

    for (int i = 1; i <= n; i++) {
        std::vector<long long> t;

        for (int j = 1; j <= m; j++) {
            if (g[i][j] >= x) t.push_back(j);
        }

        for (int j = 0; j < t.size(); j++) {
            for (int k = j + 1; k < t.size(); k++) {
                if (vis[t[j]][t[k]]) return true;
                vis[t[j]][t[k]] = true;
            }
        }
    }

    return false;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%lld", &g[i][j]);
            r = std::max(r, g[i][j]);
        }
    }

    while (l <= r) {
        long long mid = l + r >> 1;
        if (check(mid)) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    printf("%lld\n", r);

    return 0;
}

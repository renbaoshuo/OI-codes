#include <iostream>
#include <cmath>
#include <cstring>

using std::cin;
using std::cout;
const char endl = '\n';

constexpr int N = 1e5 + 5,
              M = 1005;

int n, c, m, a[N], cnt[M][N], ans[M][N], res;
int t, b, st[N], ed[N], pos[N], h[N];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> c >> m;

    t = std::sqrt(n);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (b = 1;; b++) {
        st[b] = (b - 1) * t + 1;
        ed[b] = std::min(n, b * t);

        if (b * t >= n) break;
    }

    for (int i = 1; i <= b; i++) {
        for (int j = st[i]; j <= ed[i]; j++) {
            pos[j] = i;
            cnt[i][a[j]]++;
        }
    }

    for (int i = 1; i <= b; i++) {
        for (int j = 0; j <= c; j++) {
            cnt[i][j] += cnt[i - 1][j];
        }
    }

    for (int i = 1; i <= b; i++) {
        for (int j = i; j <= b; j++) {
            ans[i][j] = ans[i][j - 1];

            for (int k = st[j]; k <= ed[j]; k++) {
                h[a[k]]++;

                if (h[a[k]] % 2 == 0) ans[i][j]++;
                else if (h[a[k]] >= 3) ans[i][j]--;
            }
        }

        memset(h, 0x00, sizeof(h));
    }

    while (m--) {
        int l, r;

        cin >> l >> r;

        l = (l + res) % n + 1;
        r = (r + res) % n + 1;
        if (l > r) std::swap(l, r);

        if (pos[l] == pos[r]) {
            res = 0;

            for (int i = l; i <= r; i++) {
                h[a[i]]++;
                if (h[a[i]] % 2 == 0) res++;
                else if (h[a[i]] >= 3) res--;
            }

            for (int i = l; i <= r; i++) h[a[i]]--;

        } else {
            res = ans[pos[l] + 1][pos[r] - 1];

            for (int i = l; i <= ed[pos[l]]; i++) {
                h[a[i]]++;

                int x = cnt[pos[r] - 1][a[i]] - cnt[pos[l]][a[i]];

                if ((h[a[i]] + x) % 2 == 0) res++;
                else if (h[a[i]] + x >= 3) res--;
            }

            for (int i = st[pos[r]]; i <= r; i++) {
                h[a[i]]++;

                int x = cnt[pos[r] - 1][a[i]] - cnt[pos[l]][a[i]];

                if ((h[a[i]] + x) % 2 == 0) res++;
                else if (h[a[i]] + x >= 3) res--;
            }

            for (int i = l; i <= ed[pos[l]]; i++) h[a[i]]--;
            for (int i = st[pos[r]]; i <= r; i++) h[a[i]]--;
        }

        cout << res << endl;
    }

    return 0;
}

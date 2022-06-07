#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 40005;

int n, m, t, p[N], pre[N], lst[N], nxt[N], pos[N], cnt[N], f[N];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    std::fill(f, f + 1 + n, 0x3f3f3f3f);

    for (int i = 1; i <= n; i++) {
        cin >> p[i];

        pre[i] = lst[p[i]];
        nxt[lst[p[i]]] = i;
        lst[p[i]] = i;
        nxt[i] = n + 1;
    }

    t = std::sqrt(n);
    f[1] = 1;

    for (int i = 1; i <= t; i++) {
        pos[i] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= t; j++) {
            if (pre[i] < pos[j]) cnt[j]++;

            if (cnt[j] > j) {
                cnt[j]--;

                while (nxt[pos[j]++] < i) {}
            }

            f[i] = std::min(f[i], f[pos[j] - 1] + (int)std::pow(j, 2));
        }
    }

    cout << f[n] << endl;

    return 0;
}

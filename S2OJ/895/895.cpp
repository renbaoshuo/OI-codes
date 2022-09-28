#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include <tuple>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5,
          M = 505;

int n, m, a[N];
std::tuple<int, int, int> q[N];
int b, t, st[M], ed[M], pos[N], max[M][N];
int tmp[N];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (b = 1, t = std::sqrt(n);; b++) {
        st[b] = (b - 1) * t + 1;
        ed[b] = std::min(n, b * t);

        if (b * t >= n) break;
    }

    for (int i = 1; i <= b; i++) {
        for (int j = st[i]; j <= ed[i]; j++) {
            pos[j] = i;
        }
    }

    for (int i = 1; i <= m; i++) {
        cin >> std::get<0>(q[i]) >> std::get<1>(q[i]) >> std::get<2>(q[i]);
    }

    int max_k = std::get<2>(*std::max_element(q + 1, q + 1 + m, [&](auto a, auto b) -> bool { return std::get<2>(a) < std::get<2>(b); }));

    for (int i = 1; i <= b; i++) {
        std::fill_n(tmp, N, 0);

        for (int j = st[i]; j <= ed[i]; j++) {
            tmp[a[j]] = a[j];
        }

        for (int j = 1; j <= 100000; j++) {
            tmp[j] = std::max(tmp[j], tmp[j - 1]);
        }

        for (int j = 1; j <= max_k; j++) {
            for (int k = 0; k <= max_k; k += j) {
                max[i][j] = std::max(max[i][j], tmp[std::min(j + k - 1, 100000)] - k);
            }
        }
    }

    for (int i = 1; i <= m; i++) {
        int l, r, k, res = 0;

        std::tie(l, r, k) = q[i];

        if (pos[l] == pos[r]) {
            for (int j = l; j <= r; j++) {
                res = std::max(res, a[j] % k);
            }
        } else {
            for (int j = l; j <= ed[pos[l]]; j++) {
                res = std::max(res, a[j] % k);
            }

            for (int j = pos[l] + 1; j <= pos[r] - 1; j++) {
                res = std::max(res, max[j][k]);
            }

            for (int j = st[pos[r]]; j <= r; j++) {
                res = std::max(res, a[j] % k);
            }
        }

        cout << res << endl;
    }

    return 0;
}

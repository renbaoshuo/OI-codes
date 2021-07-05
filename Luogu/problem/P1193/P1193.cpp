#include <bits/stdc++.h>

using namespace std;

int n, m, p[1005], s[1005], ta, tb, tc, td, a, h, e, r, pr, sr, sc, ans1, ans2;
map<int, map<int, int>> m1, m2;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> s[i];
        for (int i = 0; i < n; i++) {
            m1[s[i]][p[i]] = 0;
        }
    }
    cin >> ta >> tb >> tc >> td >> a >> h >> e >> r;
    ans2 = (ta * n + tc * r) * 100 / a + h;
    ans1 = n * ta;
    for (int i = 0; i < r; i++) {
        cin >> pr >> sr >> sc;
        m2[sr][pr]++;
        if (e && m1[sr][pr] < sc) ans1 += td, m1[sr][pr] = sc;
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (m2[s[i]][p[j]]) {
                ans1 += min(m2[s[i]][p[j]] * tb, ta + m2[s[i]][p[j]] * tc);
            }
        }
    }
    cout << ans1 << endl
         << ans2 << endl
         << (ans1 > ans2 ? "Use Luogu!" : "Forget it...") << endl;
    return 0;
}

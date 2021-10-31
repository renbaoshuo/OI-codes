#include <bits/stdc++.h>

using namespace std;

int n, m[2], a, b, cnt[2][100005], ans;
set<pair<int, int>> s;

int main() {
    cin >> n >> m[0] >> m[1];
    for (int k = 0; k < 2; k++) {
        for (int i = 1; i <= m[k]; i++) {
            cin >> a >> b;
            s.insert(make_pair(a, b));
        }
        for (int i = 1; i <= n; i++) {
            int p = 0, c = 0;
            while (true) {
                auto it = s.lower_bound(make_pair(p, 0));
                if (it == s.end()) break;
                p = it->second;
                s.erase(it);
                c++;
            }
            cnt[k][i] = cnt[k][i - 1] + c;
        }
        s.clear();
    }
    for (int i = 0; i <= n; i++) {
        ans = max(ans, cnt[0][i] + cnt[1][n - i]);
    }
    cout << ans << endl;
    return 0;
}

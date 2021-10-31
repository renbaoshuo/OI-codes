#include <bits/stdc++.h>

using namespace std;

int n, t;
double g[155][155], d[155], l1, l2 = 1e9, ans;
pair<int, int> m[155];

double dis(pair<int, int> a, pair<int, int> b) {
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> m[i].first >> m[i].second;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%1d", &t);
            if (t) {
                g[i][j] = dis(m[i], m[j]);
            } else {
                g[i][j] = i == j ? 0 : 1e9;
            }
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (g[i][j] != 1e9) {
                d[i] = max(g[i][j], d[i]);
            }
            l1 = max(l1, d[i]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (g[i][j] == 1e9) {
                l2 = min(l2, d[i] + dis(m[i], m[j]) + d[j]);
            }
        }
    }
    cout << fixed << setprecision(6) << max(l1, l2) << endl;
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int n, m, x, y, s, t;
double g[105][105];
vector<pair<int, int>> d(1);

double dis(pair<int, int> a, pair<int, int> b) {
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x >> y;
        d.push_back(make_pair(x, y));
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            g[i][j] = i == j ? 0 : 1e9;
        }
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        g[x][y] = g[y][x] = dis(d[x], d[y]);
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
    cin >> s >> t;
    cout << fixed << setprecision(2) << g[s][t] << endl;
    return 0;
}

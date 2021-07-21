#include <bits/stdc++.h>

using namespace std;

int n, m, c;
double w, g[35][35];
map<string, int> kv;
string s, s1, s2;

bool floyd() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                g[i][j] = max(g[i][j], g[i][k] * g[k][j]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (g[i][i] > 1) {
            return true;
        }
    }
    return false;
}

int main() {
    while (cin >> n, n) {
        kv.clear();
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                g[i][j] = i == j ? 1 : 0;
            }
        }
        for (int i = 1; i <= n; i++) {
            cin >> s;
            kv[s] = i;
        }
        cin >> m;
        for (int i = 1; i <= m; i++) {
            cin >> s1 >> w >> s2;
            g[kv[s1]][kv[s2]] = w;
        }
        cout << "Case " << ++c << ": " << (floyd() ? "Yes" : "No") << endl;
    }
    return 0;
}

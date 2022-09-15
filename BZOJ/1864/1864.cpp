#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 5e5 + 5;

int n, p = 1, f1[N][3], f2[N][3];
std::string s;
std::vector<int> g[N];

void dfs1(int fa) {
    int t = s[p] - '0', u = p++;

    if (fa) g[fa].push_back(u);
    if (!t) return;

    dfs1(u);
    if (t == 2) dfs1(u);
}

void dfs2(int u) {
    if (g[u].empty()) {
        f1[u][0] = f2[u][0] = 1;
        f1[u][1] = f1[u][2] = f2[u][1] = f2[u][2] = 0;

        return;
    }

    for (int v : g[u]) {
        dfs2(v);

        f1[u][0] = std::max(f1[v][1], f1[v][2]) + 1;
        f1[u][1] = std::max(f1[v][0], f1[v][2]);
        f1[u][2] = std::max({f1[u][2], f1[v][0], f1[v][1]});
        f2[u][0] = std::min({f2[u][0], f2[v][1] + 1, f2[v][2] + 1});
        f2[u][1] = std::min({f2[u][1], f2[v][0], f2[v][2]});
        f2[u][2] = std::min({f2[u][2], f2[v][0], f2[v][1]});
    }

    switch (g[u].size()) {
        case 1: {
            int v = g[u][0];

            f1[u][0] = std::max(f1[v][1], f1[v][2]) + 1;
            f1[u][1] = std::max(f1[v][0], f1[v][2]);
            f1[u][2] = std::max(f1[v][0], f1[v][1]);

            f2[u][0] = std::min(f2[v][1], f2[v][2]) + 1;
            f2[u][1] = std::min(f2[v][0], f2[v][2]);
            f2[u][2] = std::min(f2[v][0], f2[v][1]);

            break;
        }
        case 2: {
            int v1 = g[u][0],
                v2 = g[u][1];

            f1[u][0] = std::max(f1[v1][1] + f1[v2][2], f1[v1][2] + f1[v2][1]) + 1;
            f1[u][1] = std::max(f1[v1][0] + f1[v2][2], f1[v1][2] + f1[v2][0]);
            f1[u][2] = std::max(f1[v1][0] + f1[v2][1], f1[v1][1] + f1[v2][0]);

            f2[u][0] = std::min(f2[v1][1] + f2[v2][2], f2[v1][2] + f2[v2][1]) + 1;
            f2[u][1] = std::min(f2[v1][0] + f2[v2][2], f2[v1][2] + f2[v2][0]);
            f2[u][2] = std::min(f2[v1][0] + f2[v2][1], f2[v1][1] + f2[v2][0]);

            break;
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s;
    n = s.size();
    s = ' ' + s;

    dfs1(0);

    memset(f2, 0x3f, sizeof(f2));

    dfs2(1);

    cout << std::max({f1[1][0], f1[1][1], f1[1][2]}) << ' ' << std::min({f2[1][0], f2[1][1], f2[1][2]}) << endl;

    return 0;
}

#include <iostream>
#include <cstring>
#include <set>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1005;

int n, cnt, s, t, deg[N], ans[N];
int g[N][N];
std::set<char> nodes;

void dfs(char u) {
    for (int i = 1; i <= 128; i++) {
        if (g[u][i]) {
            g[u][i]--;
            g[i][u]--;

            dfs(i);
        }
    }

    ans[++cnt] = u;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        char u, v;

        cin >> u >> v;

        g[u][v]++, g[v][u]++;
        deg[u]++, deg[v]++;

        nodes.insert(u);
        nodes.insert(v);
    }

    int x = 0;

    t = *nodes.rbegin();

    for (const char &node : nodes) {
        if (deg[node] & 1) {
            x++;

            if (!s) s = node;
        }
    }

    if (!s) s = *nodes.begin();

    if (x && x != 2) {
        cout << "No Solution" << endl;

        exit(0);
    }

    dfs(s);

    if (cnt <= n) {
        cout << "No Solution" << endl;
    } else {
        for (int i = cnt; i; i--) {
            cout << (char)(ans[i]);
        }
        cout << endl;
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

vector<int> g[100005];
int n, x, y, s[100005];
bool flag;

void dfs(int u, int p) {
    s[u] = 1;
    int t = 0;
    for (int i = 0; i < g[u].size(); i++) {
        if (g[u][i] != p) {
            dfs(g[u][i], u);
            t += s[g[u][i]];
            s[u] ^= s[g[u][i]];
        }
    }
    if (t > 1) flag = true;
}

int main() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    if (n & 1) {
        cout << "First" << endl;
        return 0;
    }
    dfs(1, 0);
    if (flag) {
        cout << "First" << endl;
    }
    else {
        cout << "Second" << endl;
    }
    return 0;
}

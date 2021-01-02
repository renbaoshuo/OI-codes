#include <bits/stdc++.h>

using namespace std;

vector<int> l[100010];
int         n, m, f, s, ans, pd[100010];

void dfs(int x) {
    for (int y = 0; y < l[x].size(); y++) {
        if (!pd[l[x][y]]) {
            pd[l[x][y]] = 1;
            dfs(l[x][y]);
        }
    }
}

int main() {
    int p, q;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> p >> q;
        l[p].push_back(q);
        l[q].push_back(p);
    }
    for (int i = 1; i <= n; i++) {
        if (!pd[i]) {
            ans++;
            pd[i] = 1;
            dfs(i);
        }
    }
    cout << ans << endl;
    return 0;
}

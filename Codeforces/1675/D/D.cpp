#include <iostream>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e5 + 5;

int t, n, fa[N], root, ans_cnt;
std::vector<int> g[N], ans[N];

void dfs(int u, int fa, int cnt) {
    if (g[u].size() == 1) {
        ans[cnt].push_back(u);
        return;
    }

    ans[cnt].push_back(u);

    bool f = false;

    for (int v : g[u]) {
        if (v == fa) continue;

        if (!f) {
            dfs(v, u, cnt);
            f = true;
        } else {
            dfs(v, u, ++ans_cnt);
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);

    cin >> t;

    while (t--) {
        root = 0;
        ans_cnt = 1;

        cin >> n;

        for (int i = 1; i <= n; i++) {
            cin >> fa[i];

            if (fa[i] == i) root = i;

            g[i].push_back(fa[i]);
            g[fa[i]].push_back(i);
        }

        dfs(root, root, 1);

        for (int i = 1; i <= n; i++) {
            g[i].clear();
        }

        cout << ans_cnt << endl;
        for (int i = 1; i <= ans_cnt; i++) {
            cout << ans[i].size() << endl;
            for (int x : ans[i]) {
                cout << x << ' ';
            }
            cout << endl;

            ans[i].clear();
        }
        cout << endl;
    }

    return 0;
}

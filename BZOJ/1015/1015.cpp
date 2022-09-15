#include <iostream>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 4e5 + 5;

int n, m, k, a[N], fa[N], ans[N];
bool vis[N], del[N];
std::vector<int> g[N];

int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0, x, y; i < m; i++) {
        cin >> x >> y;

        g[x].push_back(y);
        g[y].push_back(x);
    }

    for (int i = 0; i < n; i++) fa[i] = i;

    cin >> k;

    for (int i = 1; i <= k; i++) {
        cin >> a[i];

        del[a[i]] = true;
    }

    for (int i = 0; i < n; i++) {
        if (!del[i]) {
            for (int v : g[i]) {
                if (!del[v]) {
                    int f1 = find(i),
                        f2 = find(v);

                    fa[f1] = f2;
                }
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (fa[i] == i && !del[i]) cnt++;
    }
    ans[k] = cnt;

    for (int i = k; i; i--) {
        del[a[i]] = false;
        cnt++;

        for (int v : g[a[i]]) {
            if (!del[v]) {
                int f1 = find(a[i]),
                    f2 = find(v);

                if (f1 != f2) {
                    fa[f1] = f2;
                    cnt--;
                }
            }
        }

        ans[i - 1] = cnt;
    }

    for (int i = 0; i <= k; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}

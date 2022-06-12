#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e5 + 5;

int n, cnt, pre[N], in[N];
std::pair<int, int> tr[N];

int dfs(int l, int r) {
    if (l > r) return 0;

    if (cnt > n) {
        cout << -1 << endl;

        exit(0);
    }

    int root = pre[++cnt];

    tr[root].first = dfs(l, in[root] - 1);
    tr[root].second = dfs(in[root] + 1, r);

    return root;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> pre[i];
    }

    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        in[x] = i;
    }

    if (pre[1] != 1) {
        cout << -1 << endl;

        exit(0);
    }

    dfs(1, n);

    for (int i = 1; i <= n; i++) {
        cout << tr[i].first << ' ' << tr[i].second << endl;
    }

    return 0;
}

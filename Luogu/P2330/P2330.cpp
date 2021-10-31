#include <bits/stdc++.h>

using namespace std;

struct edge {
    int from, to, dis;

    bool operator<(edge b) const {
        return dis < b.dis;
    }
} e[100005];

int n, m, s, maxx, fa[10005];

int get(int x) {
    if (fa[x] == x) return x;
    return fa[x] = get(fa[x]);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> e[i].from >> e[i].to >> e[i].dis;
    }
    for (int i = 0; i < n; i++) {
        fa[i] = i;
    }
    sort(e, e + m);
    for (int i = 0; i < m; i++) {
        int x = get(e[i].from), y = get(e[i].to);
        if (x == y) continue;
        fa[x] = y;
        maxx = e[i].dis;
    }
    cout << n - 1 << " " << maxx << endl;
    return 0;
}

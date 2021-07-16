#include <bits/stdc++.h>

using namespace std;

struct edge {
    int from, to, v;

    bool operator<(const edge& x) const {
        return v < x.v;
    }
} e[5005];

struct data {
    int a, b;

    data() {
        a = b = 0;
    }
    data(int _a, int _b) {
        int g = __gcd(_a, _b);
        a = _a / g;
        b = _b / g;
    }

    bool operator<(const data& x) const {
        return a * x.b < b * x.a;
    }
    bool operator>(const data& x) const {
        return a * x.b > b * x.a;
    }
    bool operator==(const data& x) const {
        return a * x.b == b * x.a;
    }
} ans(100000, 1);

int n, m, s, t, fa[510], rnk[510];

int find(int x) {
    if (fa[x] != x) return find(fa[x]);
    return x;
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (rnk[x] < rnk[y]) swap(x, y);
    fa[y] = x;
    rnk[x] = max(rnk[x], rnk[y] + 1);
}

bool check(int l, int r) {
    for (int i = 1; i <= n; i++) {
        fa[i] = i, rnk[i] = 1;
    }
    for (int i = l; i <= r; i++) {
        merge(e[i].from, e[i].to);
    }
    return find(s) == find(t);
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> e[i].from >> e[i].to >> e[i].v;
    }
    cin >> s >> t;
    sort(e + 1, e + 1 + m);
    for (int i = 1; i <= m; i++) {
        if (e[i].v != e[i - 1].v) {
            int l = i - 1;
            int r = m + 1;
            int mid = l + r >> 1;
            while (data(e[mid].v, e[i].v) > ans) {
                r = mid;
                mid = (l + r) >> 1;
            }
            if (!check(i, r)) continue;
            while (l + 1 < r) {
                mid = (l + r) >> 1;
                if (check(i, mid)) {
                    r = mid;
                } else {
                    l = mid;
                }
            }
            if (data(e[r].v, e[i].v) < ans) {
                ans = data(e[r].v, e[i].v);
            }
        }
    }
    if (ans.a == 100000) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << ans.a;
        if (ans.b != 1) {
            cout << '/' << ans.b;
        }
        cout << endl;
    }
    return 0;
}

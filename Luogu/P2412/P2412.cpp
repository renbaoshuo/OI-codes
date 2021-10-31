#include <bits/stdc++.h>

using namespace std;

struct node {
    int l, r;
    string s;

    node() {
        l = r = 0;
        s = "";
    }
    node(int _l, int _r) {
        l = _l;
        r = _r;
        s = "";
    }
} tr[50005 << 2];
int n, m, x, y;
string a[50005], b[50005];
map<string, string> m1;

void pushup(int u) {
    tr[u].s = max(tr[u << 1].s, tr[u << 1 | 1].s);
}

void build(int u, int l, int r) {
    tr[u] = node(l, r);
    if (l == r) {
        tr[u].s = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

string query(int u, int l, int r) {
    if (l <= tr[u].l && tr[u].r <= r) {
        return tr[u].s;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    string s;
    if (l <= mid) s = max(s, query(u << 1, l, r));
    if (r > mid) s = max(s, query(u << 1 | 1, l, r));
    return s;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        for (char c : b[i]) {
            a[i].push_back(tolower(c));
        }
        m1[a[i]] = b[i];
    }
    build(1, 1, n);
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        cout << m1[query(1, x, y)] << endl;
    }
    return 0;
}
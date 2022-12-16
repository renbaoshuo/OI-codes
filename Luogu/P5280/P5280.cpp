#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;
const int mod = 998244353;

int n, m, delta = 1, sum, ans;

struct node {
    int l, r, f, s, tag_f_add, tag_f_mul, tag_s_mul;

    node(const int &_l = 0, const int &_r = 0)
        : l(_l), r(_r), f(0), s(0), tag_f_add(0), tag_f_mul(1), tag_s_mul(1) {}
} tr[N << 2];

void build(int u, int l, int r) {
    tr[u] = node(l, r);

    if (l == r) return;

    int mid = l + r >> 1;

    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
}

void push_f_add(int u, int v) {
    tr[u].tag_f_add = (static_cast<long long>(tr[u].tag_f_add) + v) % mod;
    tr[u].f = (static_cast<long long>(tr[u].f) + v) % mod;
}

void push_f_mul(int u, int v) {
    tr[u].f = static_cast<long long>(tr[u].f) * v % mod;
    tr[u].tag_f_mul = static_cast<long long>(tr[u].tag_f_mul) * v % mod;
    tr[u].tag_f_add = static_cast<long long>(tr[u].tag_f_add) * v % mod;
}

void push_s_mul(int u, int v) {
    tr[u].s = static_cast<long long>(tr[u].s) * v % mod;
    tr[u].tag_s_mul = static_cast<long long>(tr[u].tag_s_mul) * v % mod;
}

void pushdown(int u) {
    if (tr[u].tag_f_mul != 1) {
        push_f_mul(u << 1, tr[u].tag_f_mul);
        push_f_mul(u << 1 | 1, tr[u].tag_f_mul);
        tr[u].tag_f_mul = 1;
    }

    if (tr[u].tag_s_mul != 1) {
        push_s_mul(u << 1, tr[u].tag_s_mul);
        push_s_mul(u << 1 | 1, tr[u].tag_s_mul);
        tr[u].tag_s_mul = 1;
    }

    if (tr[u].tag_f_add != 0) {
        push_f_add(u << 1, tr[u].tag_f_add);
        push_f_add(u << 1 | 1, tr[u].tag_f_add);
        tr[u].tag_f_add = 0;
    }
}

void modify(int u, int l, int r) {
    if (l <= tr[u].l && tr[u].r <= r) {
        ans = (((static_cast<long long>(ans) - tr[u].s) % mod) + mod) % mod;
        tr[u].s = (static_cast<long long>(tr[u].s) + delta) % mod;
        tr[u].tag_s_mul = (static_cast<long long>(tr[u].tag_s_mul) * 2) % mod;
        push_f_add(u, delta);
        sum = (static_cast<long long>(sum) + tr[u].s) % mod;

        return;
    }

    if (tr[u].l > r || tr[u].r < l) {
        ans = (((static_cast<long long>(ans) - tr[u].s) % mod) + mod) % mod;
        tr[u].s = (static_cast<long long>(tr[u].s) + tr[u].f) % mod;
        tr[u].tag_s_mul = (static_cast<long long>(tr[u].tag_s_mul) * 2) % mod;
        push_f_mul(u, 2);
        sum = (static_cast<long long>(sum) + tr[u].s) % mod;

        return;
    }

    pushdown(u);

    ans = (((static_cast<long long>(ans) - tr[u].s) % mod) + mod) % mod;
    sum = (static_cast<long long>(sum) + tr[u].s) % mod;

    modify(u << 1, l, r);
    modify(u << 1 | 1, l, r);
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    build(1, 1, n);

    while (m--) {
        int op;

        cin >> op;

        if (op == 1) {
            int l, r;

            cin >> l >> r;

            sum = 0;
            modify(1, l, r);
            ans = (2ll * ans + sum) % mod;
            delta = 2ll * delta % mod;
        } else {  // op == 2
            cout << ans << endl;
        }
    }

    return 0;
}

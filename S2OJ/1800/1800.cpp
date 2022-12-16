#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 5e5 + 5;

int cnt, tot, root[N], lst[N], tr[N << 5][2], siz[N << 5];

void insert(int val) {
    root[++tot] = ++cnt;

    int l = root[tot - 1], r = root[tot];

    for (int i = 30; i >= 0; i--) {
        bool x = val >> i & 1;

        tr[r][x ^ 1] = tr[l][x ^ 1];
        tr[r][x] = ++cnt;

        l = tr[l][x];
        r = tr[r][x];

        siz[r] = siz[l] + 1;
    }

    lst[tot] = cnt;
}

int query_max_xor(int l, int r, int val) {
    int res = 0;

    l = root[l], r = root[r];

    for (int i = 30; i >= 0; i--) {
        bool x = val >> i & 1,
             v = siz[tr[r][x ^ 1]] > siz[tr[l][x ^ 1]] ? (x ^ 1) : x;

        l = tr[l][v];
        r = tr[r][v];
        res |= v << i;
    }

    return res;
}

int query_leq_cnt(int l, int r, int val) {
    int res = 0;

    l = root[l], r = root[r];

    for (int i = 30; i >= 0; i--) {
        bool x = val >> i & 1;

        if (x) res += siz[tr[r][0]] - siz[tr[l][0]];

        l = tr[l][x];
        r = tr[r][x];
    }

    res += siz[r] - siz[l];

    return res;
}

int query_kth(int l, int r, int k) {
    int res = 0;

    l = root[l], r = root[r];

    for (int i = 30; i >= 0; i--) {
        if (siz[tr[r][0]] - siz[tr[l][0]] >= k) {
            l = tr[l][0];
            r = tr[r][0];
        } else {
            res += 1 << i;
            k -= siz[tr[r][0]] - siz[tr[l][0]];

            l = tr[l][1];
            r = tr[r][1];
        }
    }

    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;

    cin >> q;

    while (q--) {
        int op;

        cin >> op;

        switch (op) {
            case 0: {
                int x;

                cin >> x;

                insert(x);

                break;
            }

            case 1: {
                int l, r, x;

                cin >> l >> r >> x;

                cout << query_max_xor(l - 1, r, x) << endl;

                break;
            }

            case 2: {
                int k;

                cin >> k;

                cnt = lst[tot -= k];

                break;
            }

            case 3: {
                int l, r, x;

                cin >> l >> r >> x;

                cout << query_leq_cnt(l - 1, r, x) << endl;

                break;
            }

            case 4: {
                int l, r, k;

                cin >> l >> r >> k;

                cout << query_kth(l - 1, r, k) << endl;

                break;
            }
        }
    }

    return 0;
}

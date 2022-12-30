#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 6e5 + 5;

int n, m, sum;
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

int query(int l, int r, int val) {
    int res = 0;

    l = root[l], r = root[r];

    for (int i = 30; i >= 0; i--) {
        bool x = val >> i & 1;

        if (siz[tr[r][x ^ 1]] > siz[tr[l][x ^ 1]]) {
            res |= 1 << i;
            x = x ^ 1;
        }

        l = tr[l][x];
        r = tr[r][x];
    }

    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    insert(0);

    for (int i = 1, x; i <= n; i++) {
        cin >> x;

        insert(sum ^= x);
    }

    while (m--) {
        char op;

        cin >> op;

        if (op == 'A') {
            int x;

            cin >> x;

            insert(sum ^= x);
        } else {  // op == 'Q'
            int l, r, x;

            cin >> l >> r >> x;

            cout << query(l - 1, r, x ^ sum) << endl;
        }
    }

    return 0;
}

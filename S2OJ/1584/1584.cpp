#include <iostream>
#include <tuple>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e5 + 5;

int n, m, q, idx, cnt, lst[N];
long long c[N], val[N], ans[N];
std::vector<std::tuple<int, int, int>> changes;
std::vector<std::tuple<int, int, bool>> queries[N];

int lowbit(int x) {
    return x & -x;
}

void add(int x, int y) {
    for (; x <= m; x += lowbit(x)) c[x] += y;
}

long long sum(int x) {
    long long res = 0;
    for (; x; x -= lowbit(x)) res += c[x];
    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> q;

    changes.emplace_back(1, n, 0);

    for (int i = 1; i <= q; i++) {
        int op;

        cin >> op;

        switch (op) {
            case 1: {
                int l, r, x;

                cin >> l >> r >> x;

                changes.emplace_back(l, r, x);
                idx++;

                break;
            }

            case 2: {
                int i, x;

                cin >> i >> x;

                lst[i] = idx;
                val[i] = x;

                break;
            }

            case 3: {
                int i, j;

                cin >> i >> j;

                ans[++cnt] = val[i];
                queries[lst[i]].emplace_back(j, cnt, false);
                queries[idx].emplace_back(j, cnt, true);

                break;
            }
        }
    }

    for (int i = 0; i < changes.size(); i++) {
        int l, r, x;

        std::tie(l, r, x) = changes[i];

        add(l, x);
        add(r + 1, -x);

        for (auto query : queries[i]) {
            int pos, id, type;

            std::tie(pos, id, type) = query;

            if (type) ans[id] += sum(pos);
            else ans[id] -= sum(pos);
        }
    }

    for (int i = 1; i <= cnt; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}

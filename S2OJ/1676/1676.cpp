#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

int n, m, k, l[N], r[N], x[N], y[N], a[N];
std::vector<int> nums;
bool vis[N];

struct node {
    int l, r, x, y;
    bool vis;

    node(int _l = 0)
        : l(_l), r(0), x(0), y(0), vis(false) {}
} s[N];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        cin >> s[i].l >> s[i].x >> s[i].y >> s[i].r;
    }

    std::sort(s + 1, s + 1 + n, [&](auto lhs, auto rhs) -> bool {
        return lhs.l < rhs.l;
    });

    for (int i = 1, x; i <= k; i++) {
        cin >> x;

        auto p = std::upper_bound(s + 1, s + 1 + n, node(x), [&](auto lhs, auto rhs) -> bool {
                     return lhs.l < rhs.l;
                 })
               - 1;

        if (x < p->l || x > p->r) {
            cout << "Failed" << endl;
        } else if (p->vis) {
            cout << "Again" << endl;
        } else if (p->x <= x && x <= p->y) {
            cout << "Perfect" << endl;

            p->vis = true;
        } else {
            cout << "Normal" << endl;

            p->vis = true;
        }
    }

    return 0;
}

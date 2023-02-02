#include <iostream>
#include <cmath>
#include <numeric>
#include <queue>
#include <tuple>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 4e5 + 5;

int n, b, c[N], s[N], ans;
std::tuple<int, int, int> a[N];
std::queue<int> q;
bool vis[N];

struct node : std::vector<int> {
    int l, r;

    node(const int &_l = 0, const int &_r = 0, const std::vector<int> &_base = std::vector<int>())
        : std::vector<int>(_base), l(_l), r(_r) {}
} tr[N << 2];

void build(int u, int l, int r) {
    tr[u] = node(l, r);

    if (l == r) return;

    int mid = l + r >> 1;

    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
}

void insert(int u, int x) {
    if (std::get<0>(a[x]) <= tr[u].l && tr[u].r <= std::get<1>(a[x])) {
        tr[u].emplace_back(x);

        return;
    }

    int mid = (tr[u].l + tr[u].r) >> 1;

    if (std::get<0>(a[x]) <= mid) insert(u << 1, x);
    if (std::get<1>(a[x]) > mid) insert(u << 1 | 1, x);
}

void update(int u, int x) {
    std::vector<int> res;

    for (auto p : tr[u]) {
        if (!std::get<2>(a[p])) continue;

        if (--std::get<2>(a[p])) res.emplace_back(p);
        else q.emplace(p);
    }

    tr[u] = node(tr[u].l, tr[u].r, res);

    if (tr[u].l == tr[u].r) return;

    int mid = (tr[u].l + tr[u].r) >> 1;

    if (x <= mid) update(u << 1, x);
    else update(u << 1 | 1, x);
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    b = std::ceil(std::sqrt(n));

    build(1, 1, n);

    for (int i = 1, l, r, k; i <= n; i++) {
        cin >> l >> r >> k;

        a[i] = {l, r, k};

        if (k == 0) {
            q.emplace(i);
            vis[i] = true;
        }
    }

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        if (ans++ % b == 0) {
            std::partial_sum(c + 1, c + n + 1, s + 1);

            for (int i = 1; i <= n; i++) {
                if (vis[i]) continue;

                int l, r, k;

                std::tie(l, r, k) = a[i];

                if (s[r] - s[l - 1] + b >= k) {
                    std::get<2>(a[i]) -= s[r] - s[l - 1];
                    insert(1, i);
                    vis[i] = true;
                }
            }
        }

        update(1, x);
        c[x] = true;
    }

    cout << ans << endl;

    return 0;
}

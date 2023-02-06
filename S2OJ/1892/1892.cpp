#include <iostream>
#include <algorithm>
#include <iterator>
#include <map>
#include <stack>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e5 + 5;

int n, m, q;
int cnt = 1, edge_cnt;
std::map<int, int> map[N];
std::vector<std::pair<int, int>> qs[N];
std::vector<int> ans;

struct edge {
    int l, r, x, y, w;

    edge(const int &_x = 0,
         const int &_y = 0,
         const int &_l = 0,
         const int &_w = 0)
        : l(_l), r(0), x(_x), y(_y), w(_w) {}
} edges[N << 1];

struct dsu_item {
    int f, w, s;

    dsu_item(const int &_f = 0, const int &_w = 0)
        : f(_f), w(_w), s(1) {}
} dsu[N];

struct seg_node : std::vector<edge> {
    int l, r;

    seg_node(const int &_l = 0,
             const int &_r = 0,
             const std::vector<edge> &_v = std::vector<edge>())
        : std::vector<edge>(_v), l(_l), r(_r) {}
} tr[N << 2];

class liner_base {
  private:
    int b[31];

  public:
    void insert(int w) {
        for (int i = 29; i >= 0; --i) {
            if (!(w >> i)) continue;

            if (!b[i]) {
                b[i] = w;

                break;
            }

            w ^= b[i];
        }
    }

    int query(int w) {
        for (int i = 29; i >= 0; --i) {
            if (!((w >> i) & 1)) continue;

            w ^= b[i];
        }

        return w;
    }
} lb[std::__lg(N << 2) + 1];

int find(int x, int &w) {
    while (x != dsu[x].f) {
        w ^= dsu[x].w;
        x = dsu[x].f;
    }

    return x;
}

void merge(int x, int y, int w, int d) {
    if (x == y) {
        lb[d].insert(w);

        return;
    }

    if (dsu[x].s < dsu[y].s) std::swap(x, y);

    dsu[y].f = x;
    dsu[y].w = w;
    dsu[x].s += dsu[y].s;
}

int query(int x, int y, int d) {
    int w = 0;

    x = find(x, w);
    y = find(y, w);

    if (x != y) return -1;

    return lb[d].query(w);
}

void build(int u, int l, int r) {
    tr[u] = seg_node(l, r);

    if (l == r) return;

    int mid = (l + r) >> 1;

    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
}

void insert(int u, const edge &e) {
    if (e.l <= tr[u].l && tr[u].r <= e.r) {
        tr[u].emplace_back(e);

        return;
    }

    int mid = (tr[u].l + tr[u].r) >> 1;

    if (e.l <= mid) insert(u << 1, e);
    if (e.r > mid) insert(u << 1 | 1, e);
}

void solve(int u, int l, int r, int d) {
    std::stack<std::pair<int, dsu_item>> st;

    lb[d] = lb[d - 1];

    for (auto e : tr[u]) {
        int wx = 0, wy = 0;
        int x = find(e.x, wx);
        int y = find(e.y, wy);

        st.emplace(x, dsu[x]);
        st.emplace(y, dsu[y]);

        merge(x, y, wx ^ wy ^ e.w, d);
    }

    if (l == r) {
        for (auto o : qs[l]) {
            ans.emplace_back(query(o.first, o.second, d));
        }
    } else {
        int mid = (l + r) >> 1;

        solve(u << 1, l, mid, d + 1);
        solve(u << 1 | 1, mid + 1, r, d + 1);
    }

    while (!st.empty()) {
        dsu[st.top().first] = st.top().second;
        st.pop();
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        dsu[i] = dsu_item(i, 0);
    }

    for (int i = 1, x, y, d; i <= m; i++) {
        cin >> x >> y >> d;

        map[x][y] = map[y][x] = ++edge_cnt;

        edges[edge_cnt] = edge(x, y, 1, d);
    }

    cin >> q;

    for (int i = 1, op, x, y; i <= q; i++) {
        cin >> op >> x >> y;

        if (op == 1) {
            int d;

            cin >> d;

            map[x][y] = map[y][x] = ++edge_cnt;
            edges[edge_cnt] = edge(x, y, ++cnt, d);
        } else if (op == 2) {
            edges[map[x][y]].r = cnt++;
        } else {  // op == 3
            qs[cnt].emplace_back(x, y);
        }
    }

    build(1, 1, cnt);

    for (int i = 1; i <= edge_cnt; i++) {
        if (!edges[i].r) edges[i].r = cnt;

        insert(1, edges[i]);
    }

    solve(1, 1, cnt, 1);

    std::copy(ans.begin(), ans.end(), std::ostream_iterator<int>(cout, "\n"));

    return 0;
}

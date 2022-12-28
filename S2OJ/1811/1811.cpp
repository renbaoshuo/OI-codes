#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include <tuple>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

int n, base, fa[N];
std::tuple<int, int, int, int> c[N];
std::vector<std::tuple<int, int, bool>> p;
std::vector<int> g[N];

double pos(int id, bool p) {
    int x, y, r;

    std::tie(x, y, r, std::ignore) = c[id];

    double d = std::sqrt(std::pow(r, 2) - std::pow(base - x, 2));

    if (p) return y - d;
    return y + d;
}

std::multiset<std::pair<int, bool>, bool (*)(std::pair<int, bool>, std::pair<int, bool>)> set{[](std::pair<int, bool> lhs, std::pair<int, bool> rhs) {
    return pos(lhs.first, lhs.second) > pos(rhs.first, rhs.second);
}};

int dfs(int u) {
    int res = 0;

    for (int v : g[u]) {
        res += dfs(v);
    }

    return std::max(res, std::get<3>(c[u]));
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1, x, y, r, w; i <= n; i++) {
        cin >> x >> y >> r >> w;

        c[i] = std::make_tuple(x, y, r, w);
        p.emplace_back(x - r, i, false);
        p.emplace_back(x + r, i, true);
    }

    std::sort(p.begin(), p.end(), [](std::tuple<int, int, bool> lhs, std::tuple<int, int, bool> rhs) {
        int x1, x2;
        bool op1, op2;

        std::tie(x1, std::ignore, op1) = lhs;
        std::tie(x2, std::ignore, op2) = rhs;

        return x1 == x2 ? op1 > op2 : x1 < x2;
    });

    for (auto o : p) {
        int x, id, op;

        std::tie(x, id, op) = o;

        if (op) {
            set.erase({id, 0});
            set.erase({id, 1});
        } else {
            base = x;
            set.emplace(id, 0);

            auto it = set.find({id, 0});

            if (it != set.begin()) {
                int id2;
                bool op2;

                std::tie(id2, op2) = *std::prev(it);

                if (op2) fa[id] = fa[id2];
                else fa[id] = id2;
            }

            set.emplace(id, 1);
        }
    }

    for (int i = 1; i <= n; i++) {
        g[fa[i]].push_back(i);
    }

    cout << dfs(0) << endl;

    return 0;
}

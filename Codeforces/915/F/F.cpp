#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <tuple>
#include <utility>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e6 + 5;

int n, a[N], fa_min[N], fa_max[N], siz_min[N], siz_max[N];
long long ans;
std::pair<int, int> e[N];
std::tuple<int, int, int> edges_min[N], edges_max[N];

int find(int *fa, int x) {
    return fa[x] == x ? x : fa[x] = find(fa, fa[x]);
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i < n; i++) {
        cin >> e[i].first >> e[i].second;
    }

    std::fill(std::begin(siz_min), std::end(siz_min), 1);
    std::fill(std::begin(siz_max), std::end(siz_max), 1);

    std::iota(fa_min, fa_min + N, 0);
    std::iota(fa_max, fa_max + N, 0);

    std::transform(e + 1, e + n, edges_min + 1, [&](const std::pair<int, int> &edge) -> std::tuple<int, int, int> {
        return std::make_tuple(edge.first, edge.second, std::min(a[edge.first], a[edge.second]));
    });
    std::transform(e + 1, e + n, edges_max + 1, [&](const std::pair<int, int> &edge) -> std::tuple<int, int, int> {
        return std::make_tuple(edge.first, edge.second, std::max(a[edge.first], a[edge.second]));
    });

    std::sort(edges_min + 1, edges_min + n, [&](const std::tuple<int, int, int> &a, const std::tuple<int, int, int> &b) {
        return std::get<2>(a) > std::get<2>(b);
    });
    std::sort(edges_max + 1, edges_max + n, [&](const std::tuple<int, int, int> &a, const std::tuple<int, int, int> &b) {
        return std::get<2>(a) < std::get<2>(b);
    });

    cout << std::accumulate(edges_max + 1, edges_max + n, 0ll, [&](long long acc, const std::tuple<int, int, int> &cur) -> long long {
                int u, v, w;

                std::tie(u, v, w) = cur;

                u = find(fa_max, u), v = find(fa_max, v);

                if (u != v) {
                    acc += static_cast<long long>(w) * siz_max[u] * siz_max[v];
                    fa_max[u] = v;
                    siz_max[v] += siz_max[u];
                }

                return acc;
            }) - std::accumulate(edges_min + 1, edges_min + n, 0ll, [&](long long acc, const std::tuple<int, int, int> &cur) -> long long {
                int u, v, w;

                std::tie(u, v, w) = cur;

                u = find(fa_min, u), v = find(fa_min, v);

                if (u != v) {
                    acc += static_cast<long long>(w) * siz_min[u] * siz_min[v];
                    fa_min[u] = v;
                    siz_min[v] += siz_min[u];
                }

                return acc;
            })
         << endl;

    return 0;
}

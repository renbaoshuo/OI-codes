#include <iostream>
#include <algorithm>
#include <iomanip>
#include <iterator>
#include <queue>
#include <tuple>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 55;
const double eps = 1e-6;

int n, m, s[N][N];
std::vector<std::tuple<int, int, int>> g[N * N];
int cnt[N * N];
double dist[N * N];
bool vis[N * N];

int id(int x, int y) {
    return (x - 1) * (m + 1) + y;
}

bool check(double x) {
    std::fill(std::begin(cnt), std::end(cnt), 0);
    std::fill(std::begin(dist), std::end(dist), -1e9);
    std::fill(std::begin(vis), std::end(vis), false);

    std::queue<int> q;

    q.emplace(1);
    dist[1] = 0;
    vis[1] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        vis[u] = false;

        for (auto e : g[u]) {
            int v, a, b;

            std::tie(v, a, b) = e;

            double w = static_cast<double>(b) - x * a;

            if (dist[v] < dist[u] + w) {
                dist[v] = dist[u] + w;

                if (!vis[v]) {
                    cnt[v] = cnt[u] + 1;

                    if (cnt[v] > (n + 1) * (m + 1)) return false;

                    vis[v] = true;
                    q.emplace(v);
                }
            }
        }
    }

    return true;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1, x; j <= m; j++) {
            cin >> x;

            s[i][j] = s[i][j - 1] + x;
        }
    }

    for (int i = 1; i <= n + 1; i++) {
        for (int j = 1, x; j <= m; j++) {
            cin >> x;

            g[id(i, j)].emplace_back(id(i, j + 1), x, 0);
            g[id(i, j + 1)].emplace_back(id(i, j), x, 0);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1, x; j <= m + 1; j++) {
            cin >> x;

            g[id(i, j)].emplace_back(id(i + 1, j), x, -s[i][j - 1]);
            g[id(i + 1, j)].emplace_back(id(i, j), x, s[i][j - 1]);
        }
    }

    double l = 0, r = 1000;

    while (r - l > eps) {
        double mid = (l + r) / 2;

        if (check(mid)) r = mid;
        else l = mid;
    }

    cout << std::fixed << std::setprecision(3) << l << endl;

    return 0;
}

#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <queue>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 3005;
const double eps = 1e-4;

int n, row, line;
std::pair<int, int> a[N];
bool vis[N];

bool check(double x) {
    std::fill_n(vis, N, false);

    std::queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (a[i].first - 1 < x || line - a[i].second < x) {
            vis[i] = true;
            q.push(i);
        }
    }

    while (!q.empty()) {
        auto u = q.front();
        q.pop();

        if (row - a[u].first < x || a[u].second - 1 < x) {
            return false;
        }

        for (int i = 1; i <= n; i++) {
            if (!vis[i] && std::sqrt(std::pow(a[u].first - a[i].first, 2) + std::pow(a[u].second - a[i].second, 2)) < x * 2) {
                vis[i] = true;
                q.push(i);
            }
        }
    }

    return true;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> row >> line;

    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    double l = 0, r = std::min(row, line);

    while (r - l > eps) {
        double mid = (l + r) / 2;

        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }

    cout << std::fixed << std::setprecision(2) << l << endl;

    return 0;
}

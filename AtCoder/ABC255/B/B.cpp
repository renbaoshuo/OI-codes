#include <iostream>
#include <cmath>
#include <iomanip>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1005;

int n, k, a[N];
bool has[N];
std::pair<int, int> points[N];
double dis[N][N], dist[N], ans;

double getdis(std::pair<int, int> a, std::pair<int, int> b) {
    return std::sqrt(1ll * (a.first - b.first) * (a.first - b.first) + 1ll * (a.second - b.second) * (a.second - b.second));
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    for (int i = 1; i <= k; i++) {
        cin >> a[i];
        has[a[i]] = true;
    }

    for (int i = 1; i <= n; i++) {
        cin >> points[i].first >> points[i].second;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            dis[i][j] = dis[j][i] = getdis(points[i], points[j]);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!has[i]) {
            dist[i] = 9999999999;
            for (int j = 1; j <= n; j++) {
                if (i != j) {
                    if (has[j]) {
                        dist[i] = std::min(dist[i], dis[i][j]);
                    }
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        ans = std::max(ans, dist[i]);
    }

    cout << std::fixed << std::setprecision(10) << ans << endl;

    return 0;
}

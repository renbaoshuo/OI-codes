#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 20;
const double eps = 1e-6;

int t, n, m, cnt, f[1 << N], s[N << 4];
std::pair<double, double> points[N];

inline std::pair<double, double> e(const std::pair<double, double> &_a, const std::pair<double, double> &_b) {
    return std::make_pair(
        (_a.second - _b.second * _a.first / _b.first) / (_a.first * (_a.first - _b.first)),
        (_a.second - _b.second * _a.first * _a.first / (_b.first * _b.first)) / (_a.first - _a.first * _a.first / _b.first));
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;

    while (t--) {
        cnt = 0;
        memset(f, 0x3f, sizeof(f));
        memset(s, 0x00, sizeof(s));

        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            cin >> points[i].first >> points[i].second;
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (std::abs(points[i].first - points[j].first) < eps) continue;

                auto r = e(points[i], points[j]);
                if (r.first > -eps) continue;

                cnt++;
                for (int k = 0; k < n; k++) {
                    if (std::abs(r.first * points[k].first * points[k].first + r.second * points[k].first - points[k].second) < eps) {
                        s[cnt] |= 1 << k;
                    }
                }
            }
        }

        f[0] = 0;
        for (int i = 0; i < 1 << n; i++) {
            // 两只及以上
            for (int j = 1; j <= cnt; j++) {
                f[i | s[j]] = std::min(f[i | s[j]], f[i] + 1);
            }
            // 一只
            for (int j = 0; j < n; j++) {
                f[i | 1 << j] = std::min(f[i | 1 << j], f[i] + 1);
            }
        }

        cout << f[(1 << n) - 1] << endl;
    }

    return 0;
}

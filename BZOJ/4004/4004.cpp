#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 505;
const double eps = 1e-4;

int n, m, ans, sum;
double p[N][N];

struct node {
    int w;
    double v[N];

    double& operator[](const int& _i) {
        return v[_i];
    }

    bool operator<(const node& _y) const {
        return w < _y.w;
    }
} q[N];

inline bool insert(double* a) {
    for (int i = 1; i <= m; i++) {
        if (std::abs(a[i]) > eps) {
            if (std::abs(p[i][i]) > eps) {  // > 0
                double k = a[i] / p[i][i];
                for (int j = i; j <= m; j++) {
                    a[j] -= k * p[i][j];
                }
            } else {
                for (int j = i; j <= m; j++) {
                    p[i][j] = a[j];
                }

                return true;
            }
        }
    }

    return false;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> q[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        cin >> q[i].w;
    }

    std::sort(q + 1, q + 1 + n);

    for (int i = 1; i <= n; i++) {
        if (insert(q[i].v)) {
            ans++;
            sum += q[i].w;
        }
    }

    cout << ans << ' ' << sum << endl;

    return 0;
}

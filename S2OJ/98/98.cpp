#include <iostream>
#include <algorithm>
#include <cmath>
#include <complex>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const double PI = std::acos(-1);

void FFT(std::vector<std::complex<double>>& a) {
    if (a.size() == 1) return;

    int m = a.size() >> 1;
    std::vector<std::complex<double>> a0, a1;

    for (int i = 0; i < m; i++) {
        a0.emplace_back(a[i << 1]);
        a1.emplace_back(a[i << 1 | 1]);
    }

    FFT(a0), FFT(a1);

    std::complex<double>
        w0{std::cos(PI / m), std::sin(PI / m)},
        w1{1.0, 0.0};

    for (int i = 0; i < m; i++) {
        a[i] = a0[i] + w1 * a1[i];
        a[i + m] = a0[i] - w1 * a1[i];
        w1 *= w0;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;

    cin >> n >> m;

    int k = 1 << (std::__lg(n + m) + 1);
    std::vector<std::complex<double>> f(k), g(k);

    for (int i = 0; i <= n; i++) {
        cin >> f[i];
    }

    for (int i = 0; i <= m; i++) {
        cin >> g[i];
    }

    FFT(f), FFT(g);

    for (int i = 0; i < k; i++) {
        f[i] *= g[i];
    }

    FFT(f);
    std::reverse(f.begin() + 1, f.end());

    for (int i = 0; i <= n + m; i++) {
        cout << static_cast<int>(std::round(f[i].real() / k)) << ' ';
    }

    cout << endl;

    return 0;
}

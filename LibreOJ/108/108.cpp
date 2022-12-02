#include <iostream>
#include <algorithm>
#include <cmath>
#include <complex>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const double PI = std::acos(-1);

void fast_fourier_transform(std::vector<std::complex<double>>& a) {
    if (a.size() == 1) return;

    // assert(a.size() == 1 << std::__lg(a.size()));
    int k = std::__lg(a.size());

    for (int i = 0; i < a.size(); i++) {
        int t = 0;

        for (int j = 0; j < k; j++) {
            if (i & (1 << j)) {
                t |= 1 << (k - j - 1);
            }
        }

        if (i < t) std::swap(a[i], a[t]);
    }

    for (int len = 2; len <= a.size(); len <<= 1) {
        std::complex<double> wlen(std::cos(2 * PI / len), std::sin(2 * PI / len));

        for (int i = 0; i < a.size(); i += len) {
            std::complex<double> w(1);

            for (int j = 0; j < len / 2; j++) {
                std::complex<double> u = a[i + j],
                                     v = a[i + j + len / 2] * w;

                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }
}

void dft(std::vector<std::complex<double>>& a) {
    fast_fourier_transform(a);
}

void idft(std::vector<std::complex<double>>& a) {
    fast_fourier_transform(a);
    std::reverse(a.begin() + 1, a.end());
    std::transform(a.begin(), a.end(), a.begin(), [&](std::complex<double> x) {
        return static_cast<int>(std::round(x.real() / a.size()));
    });
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

    dft(f);
    dft(g);

    for (int i = 0; i < k; i++) {
        f[i] *= g[i];
    }

    idft(f);

    for (int i = 0; i <= n + m; i++) {
        cout << static_cast<int>(f[i].real()) << ' ';
    }

    cout << endl;

    return 0;
}

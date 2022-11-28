#include <iostream>
#include <algorithm>
#include <cmath>
#include <complex>
#include <valarray>

using std::cin;
using std::cout;
const char endl = '\n';

const double PI = std::acos(-1);

void fast_fourier_transform(std::valarray<std::complex<double>>& a) {
    if (a.size() == 1) return;

    int m = a.size() >> 1;

    std::valarray<std::complex<double>>
        even = a[std::slice(0, m, 2)],
        odd = a[std::slice(1, m, 2)];

    fast_fourier_transform(even);
    fast_fourier_transform(odd);

    for (int i = 0; i < m; i++) {
        auto t = std::polar(1.0, -2 * PI * i / a.size()) * odd[i];
        a[i] = even[i] + t;
        a[i + m] = even[i] - t;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;

    cin >> n >> m;

    int k = 1 << (std::__lg(n + m) + 1);
    std::valarray<std::complex<double>> f(k), g(k);

    for (int i = 0; i <= n; i++) {
        cin >> f[i];
    }

    for (int i = 0; i <= m; i++) {
        cin >> g[i];
    }

    fast_fourier_transform(f);
    fast_fourier_transform(g);

    for (int i = 0; i < k; i++) {
        f[i] *= g[i];
    }

    fast_fourier_transform(f);
    std::reverse(std::begin(f) + 1, std::end(f));

    for (int i = 0; i <= n + m; i++) {
        cout << static_cast<int>(std::round(f[i].real() / k)) << ' ';
    }

    cout << endl;

    return 0;
}

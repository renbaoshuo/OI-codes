#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

struct Matrix : public std::vector<std::vector<long long>> {
    int n, m;

    Matrix(const int &_n = 0, const int &_m = 0)
        : std::vector<std::vector<long long>>(_n, std::vector<long long>(_m)),
          n(_n),
          m(_m) {}

    Matrix(const Matrix &_matrix)
        : std::vector<std::vector<long long>>(_matrix), n(_matrix.n), m(_matrix.m) {}

    Matrix operator=(const Matrix &_matrix) {
        std::vector<std::vector<long long>>::operator=(_matrix);
        n = _matrix.n;
        m = _matrix.m;

        return *this;
    }

    Matrix operator^(Matrix rhs) {
        Matrix res(n, rhs.m);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < rhs.m; ++j) {
                res[i][j] = 0;

                for (int k = 0; k < m; ++k) {
                    res[i][j] ^= (*this)[i][k] * rhs[k][j];
                }
            }
        }

        return res;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    std::vector<long long> a;

    cin >> n >> m >> q;

    std::copy_n(std::istream_iterator<long long>(cin), n, std::back_inserter(a));

    std::vector<Matrix> g;
    g.emplace_back(n, n);

    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;

        u--, v--;

        g[0][u][v] = g[0][v][u] = 1;
    }

    for (int i = 1; i <= 32; i++) {
        g.emplace_back(g.back() ^ g.back());
    }

    while (q--) {
        long long x;

        cin >> x;

        Matrix f(1, n);
        f[0] = a;

        for (long long w = 1, i = 0; w <= x; w <<= 1, i++) {
            if (x & w) f = f ^ g[i];
        }

        cout << f[0][0] << endl;
    }

    return 0;
}

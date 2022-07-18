#include <iostream>
#include <algorithm>
#include <cstring>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 10;
const int mod = 1e8;

class Matrix {
  private:
    long long data[N][N];

  public:
    Matrix() {
        memset(data, 0x00, sizeof(data));
    }

    long long* operator[](int i) {
        return data[i];
    }

    Matrix operator*(Matrix b) const {
        Matrix c;

        int n = 2;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                for (int k = 1; k <= n; k++) {
                    c[i][j] = (c[i][j] + data[i][k] * b[k][j] % mod) % mod;
                }
            }
        }

        return c;
    }
} base, ans;

Matrix binpow(Matrix a, int k) {
    Matrix res;
    res[1][1] = 1;
    res[1][2] = 1;

    while (k) {
        if (k & 1) res = res * a;
        a = a * a;
        k >>= 1;
    }

    return res;
}

long long fib(int n) {
    if (n <= 2) {
        return !!n;
    }

    Matrix tmp;

    tmp[1][1] = 1, tmp[1][2] = 1;
    tmp[2][1] = 1, tmp[2][2] = 0;

    return binpow(tmp, n - 2)[1][1];
}

int n, m;

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n >> m;

    cout << fib(std::__gcd(n, m)) % mod << endl;

    return 0;
}

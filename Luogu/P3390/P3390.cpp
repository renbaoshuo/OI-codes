#include <cstring>
#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 105;
const int mod = 1e9 + 7;

int n;
long long k;

class Matrix {
  private:
    int data[N][N];

  public:
    Matrix() {
        std::memset(data, 0x00, sizeof(data));
    }

    int* operator[](int i) {
        return data[i];
    }

    void build(int n) {
        for (int i = 1; i <= n; i++) {
            data[i][i] = 1;
        }
    }

    Matrix operator*(Matrix b) const {
        Matrix c;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                for (int k = 1; k <= n; k++) {
                    c[i][j] = (c[i][j] + 1ll * data[i][k] * b[k][j] % mod) % mod;
                }
            }
        }

        return c;
    }
} base, ans;

Matrix binpow(Matrix a, long long b) {
    Matrix res;
    res.build(n);

    while (b) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }

    return res;
}

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> base[i][j];
        }
    }

    ans = binpow(base, k);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}

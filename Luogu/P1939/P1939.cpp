#include <cstring>
#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 10;
const int mod = 1e9 + 7;

class Matrix {
  private:
    int data[N][N];

  public:
    Matrix() {
        memset(data, 0x00, sizeof(data));
    }

    int* operator[](int i) {
        return data[i];
    }

    void build() {
        int n = 3;

        for (int i = 1; i <= n; i++) {
            data[i][i] = 1;
        }
    }

    Matrix operator*(Matrix b) const {
        Matrix c;

        int n = 3;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                for (int k = 1; k <= n; k++) {
                    c[i][j] = (c[i][j] + 1ll * data[i][k] * b[k][j] % mod) % mod;
                }
            }
        }

        return c;
    }
};

Matrix binpow(Matrix a, int k) {
    Matrix res;
    res.build();

    while (k) {
        if (k & 1) res = res * a;
        a = a * a;
        k >>= 1;
    }

    return res;
}

int t, n;

int main() {
    std::ios::sync_with_stdio(false);

    cin >> t;

    Matrix base, pow;

    base[1][1] = 1;
    base[2][1] = 1;
    base[3][1] = 1;

    pow[1][1] = 1, pow[1][2] = 0, pow[1][3] = 1;
    pow[2][1] = 1, pow[2][2] = 0, pow[2][3] = 0;
    pow[3][1] = 0, pow[3][2] = 1, pow[3][3] = 0;

    while (t--) {
        cin >> n;
        cout << (base * binpow(pow, n - 1))[1][1] << endl;
    }

    return 0;
}

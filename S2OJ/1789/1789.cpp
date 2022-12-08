#include <iostream>
#include <array>
#include <cstring>
#include <numeric>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;
const int mod = 1e9 + 7;

class Matrix {
  private:
    long long data[10][10];

  public:
    Matrix() {
        memset(data, 0x00, sizeof(data));
    }

    long long* operator[](long long i) {
        return data[i];
    }

    Matrix operator*(Matrix b) const {
        Matrix c;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    c[i][j] = (c[i][j] + data[i][k] * b[k][j] % mod) % mod;
                }
            }
        }

        return c;
    }

    Matrix operator-(Matrix b) const {
        Matrix c;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                c[i][j] = (data[i][j] - b[i][j] + mod) % mod;
            }
        }

        return c;
    }
} base, ans;

Matrix binpow(Matrix a, long long k) {
    Matrix res;

    res[1][1] = 1;
    res[2][2] = 1;

    while (k) {
        if (k & 1) res = res * a;
        a = a * a;
        k >>= 1;
    }

    return res;
}

int t, n, k;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;

    while (t--) {
        cin >> n >> k;

        Matrix tmp;

        tmp[1][1] = 0, tmp[1][2] = 1;
        tmp[2][1] = 1, tmp[2][2] = 1;

        cout << binpow(binpow(tmp, n + 1) - tmp, k)[2][2] << endl;
    }

    return 0;
}

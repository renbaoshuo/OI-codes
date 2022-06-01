#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1005,
          mod = 1e9 + 7;

int n, m, p;

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

    Matrix operator*(Matrix b) const {
        Matrix c;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= p; j++) {
                for (int k = 1; k <= m; k++) {
                    c[i][j] = (c[i][j] + 1ll * data[i][k] * b[k][j] % mod) % mod;
                }
            }
        }

        return c;
    }
} a, b, c;

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n >> m >> p;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= p; j++) {
            cin >> b[i][j];
        }
    }

    c = a * b;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= p; j++) {
            cout << (c[i][j] % mod + mod) % mod << ' ';
        }
        cout << endl;
    }

    return 0;
}

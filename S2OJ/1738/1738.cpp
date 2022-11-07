#include <iostream>
#include <algorithm>
#include <cstring>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e6 + 5,
          K = 105;
const int mod = 1e9 + 7;

int n, k, a[N];
long long m, f[N], s, ans;
std::pair<long long, int> sum[N];

class Matrix {
  private:
    long long data[K][K];

  public:
    Matrix() {
        memset(data, 0x00, sizeof(data));
    };

    void build() {
        for (int i = 1; i <= k; i++) data[i][i] = 1;
    }

    long long *operator[](int x) {
        return data[x];
    }

    Matrix operator*(Matrix b) {
        Matrix res;

        for (int i = 1; i <= k; i++) {
            for (int j = 1; j <= k; j++) {
                for (int l = 1; l <= k; l++) {
                    res[i][j] = (res[i][j] + data[i][l] * b[l][j]) % mod;
                }
            }
        }

        return res;
    }
} z, res;

Matrix binpow(Matrix a, long long b) {
    Matrix res;

    res.build();

    while (b) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }

    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        f[i] = (s + 1) % mod;
        s = ((s - sum[a[i]].first) % mod + mod) % mod;
        sum[a[i]].first = f[i];
        s = (s + sum[a[i]].first) % mod;
        sum[a[i]].second = i;
    }

    std::sort(sum + 1, sum + 1 + k, [&](auto a, auto b) -> bool { return a.second < b.second; });

    for (int i = 1; i <= k; i++) {
        res[1][i] = sum[i].first;
    }

    res[1][k + 1] = s;
    res[1][k + 2] = 1;

    for (int i = 1; i < k; i++) {
        z[i + 1][i] = 1;
    }

    z[1][k + 1] = mod - 1;
    z[k + 1][k] = 1;
    z[k + 1][k + 1] = 2;
    z[k + 2][k] = 1;
    z[k + 2][k + 1] = 1;
    z[k + 2][k + 2] = 1;

    k += 2;

    res = res * binpow(z, m);

    cout << res[1][k - 1] << endl;

    return 0;
}

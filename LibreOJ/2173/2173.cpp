#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 5e4 + 5,
          M = 205;
const int mod = 1e9 + 7;

int s[N][M], c[M][M];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    s[0][0] = s[1][1] = 1;

    for (int i = 2; i < N; i++) {
        s[i][1] = static_cast<long long>(s[i - 1][1]) * (i - 1) % mod;
    }

    for (int i = 2; i < N; i++) {
        for (int j = 1; j < M && j <= i; j++) {
            s[i][j] = (static_cast<long long>(s[i - 1][j - 1]) + static_cast<long long>(s[i - 1][j]) * (i - 1)) % mod;
        }
    }

    for (int i = 0; i < M; i++) {
        c[i][0] = c[i][i] = 1;
    }

    for (int i = 2; i < M; i++) {
        for (int j = 1; j < i; j++) {
            c[i][j] = (static_cast<long long>(c[i - 1][j]) + c[i - 1][j - 1]) % mod;
        }
    }

    int t;

    cin >> t;

    while (t--) {
        int n, a, b;

        cin >> n >> a >> b;

        cout << static_cast<long long>(s[n - 1][a + b - 2]) * c[a + b - 2][a - 1] % mod << endl;
    }

    return 0;
}

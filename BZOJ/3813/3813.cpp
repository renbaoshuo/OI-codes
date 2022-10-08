#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;
const int mod = 19961993;
const int primes[]{0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281};

int n, a[N], c[61][N], p[61][N];

int lowbit(int x) {
    return x & -x;
}

void add(int* c, int x, int y) {
    for (; x <= 100000; x += lowbit(x)) c[x] += y;
}

int sum(int* c, int x) {
    int res = 0;
    for (; x; x -= lowbit(x)) res += c[x];
    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= 100000; i++) {
        a[i] = 3;
        add(c[2], i, 1);
    }

    for (int i = 1; i <= 60; i++) {
        p[i][0] = 1;

        for (int j = 1; j <= 100000; j++) {
            p[i][j] = static_cast<long long>(p[i][j - 1]) * (j > 1 ? primes[i] : (primes[i] - 1)) % mod;
        }
    }

    for (int i = 1, op, x, y; i <= n; i++) {
        cin >> op >> x >> y;

        if (op == 0) {
            int ans = 1;

            for (int j = 1; j <= 60; j++) {
                ans = static_cast<long long>(ans) * p[j][sum(c[j], y) - sum(c[j], x - 1)] % mod;
            }

            cout << ans << endl;
        } else {  // op == 1
            for (int i = 1; i <= 60; i++) {
                if (a[x] % primes[i] == 0) {
                    int cnt = 0, t = a[x];

                    while (t % primes[i] == 0) {
                        t /= primes[i];
                        cnt++;
                    }

                    add(c[i], x, -cnt);
                }
            }

            a[x] = y;

            for (int i = 1; i <= 60; i++) {
                if (a[x] % primes[i] == 0) {
                    int cnt = 0, t = a[x];

                    while (t % primes[i] == 0) {
                        t /= primes[i];
                        cnt++;
                    }

                    add(c[i], x, cnt);
                }
            }
        }
    }

    return 0;
}

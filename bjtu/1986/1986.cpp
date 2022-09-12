#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

const int primes[] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 47, 51, 53};
const int ci[] = {0, 6, 3, 2, 1, 1, 1, 1, 1, 1, 1};

int n, cnt;
long long a[N];
long long k = 9316358251200;

long long binpow(long long a, long long b) {
    long long res = 1;

    while (b) {
        if (b & 1) res *= a;
        a *= a;
        b >>= 1;
    }

    return res;
}

void dfs(int step, long long now) {
    if (step == 10) {
        a[++cnt] = now;
        return;
    }

    for (int i = 0; i <= ci[step + 1]; i++) {
        dfs(step + 1, now * binpow(primes[step + 1], i));
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    dfs(0, 1);

    for (int i = 1; i <= n; i++) {
        cout << k * i + 1 << ' ';
    }

    cout << endl;

    for (int i = 2; i <= n + 1; i++) {
        cout << a[i] << ' ';
    }

    cout << endl;

    return 0;
}

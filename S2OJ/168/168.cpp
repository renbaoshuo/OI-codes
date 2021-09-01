#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;

int q, p, op, k, prime[1000005], miu[1000005], phi[1000005];
long long sig[1000005];
bool is_prime[1000005];

template <typename T>
inline void read(T& x) {
    x = 0;
    int f = 1;
    char ch;
    while (!isdigit(ch = getchar())) {
        if (ch == '-') f = -1;
    }
    while (isdigit(ch)) {
        x = x * 10 + (ch ^ 48);
        ch = getchar();
    }
    x *= f;
}

template <typename T>
void write(T x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) {
        write(x / 10);
    }
    putchar(x % 10 + '0');
}

int main() {
    phi[1] = miu[1] = sig[1] = 1;
    for (int i = 2; i <= 1000000; i++) {
        if (!is_prime[i]) {
            prime[++p] = i;
            phi[i] = i - 1;
            miu[i] = -1;
            sig[i] = i + 1;
        }
        for (int j = 1; j <= p && prime[j] * i <= 1000000; j++) {
            is_prime[i * prime[j]] = 1, miu[i * prime[j]] = -miu[i];
            phi[i * prime[j]] = phi[i] * phi[prime[j]];
            sig[i * prime[j]] = sig[i] * sig[prime[j]];
            if (i % prime[j] == 0) {
                miu[i * prime[j]] = 0;
                phi[i * prime[j]] = phi[i] * prime[j];
                sig[i * prime[j]] -= sig[i / prime[j]] * prime[j];
                break;
            }
        }
    }
    read(q);
    for (int i = 0; i < q; i++) {
        read(op);
        read(k);
        if (op == 1) {
            write(prime[k]);
            putchar('\n');
        } else {
            write(sig[k]);
            putchar(' ');
            write(miu[k]);
            putchar(' ');
            write(phi[k]);
            putchar('\n');
        }
    }
    return 0;
}

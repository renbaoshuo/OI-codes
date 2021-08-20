#include <bits/stdc++.h>

using namespace std;

const unsigned long long mod = 1e18;

unsigned long long n;

unsigned long long mul(unsigned long long a, unsigned long long b) {
    unsigned long long res = 0;
    while (b) {
        if (b & 1) res = (res + a) % mod;
        a = (a << 1) % mod;
        b >>= 1;
    }
    return res;
}

struct matrix {
    unsigned long long f[4][4];

    matrix() {
        memset(f, 0x00, sizeof(f));
    }

    void init() {
        for (int i = 0; i < 4; i++) {
            f[i][i] = 1;
        }
    }

    matrix operator*(matrix b) {
        matrix res;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    res[i][j] = (res[i][j] + mul(f[i][k], b[k][j])) % mod;
                }
            }
        }
        return res;
    }

    matrix operator^(unsigned long long b) {
        matrix t;
        t.init();
        while (b) {
            if (b & 1) t = t * *this;
            *this = *this * *this;
            b >>= 1;
        }
        return t;
    }

    unsigned long long* operator[](int x) {
        return f[x];
    }
} a, b;

int main() {
    cin >> a[0][2] >> a[0][1] >> a[0][0];
    cin >> b[0][0] >> b[1][0] >> b[2][0];
    cin >> a[0][3] >> n;
    b.f[0][1] = b.f[1][2] = b.f[3][0] = b.f[3][3] = 1;
    if (n <= 2) {
        cout << a[0][2 - n] << endl;
        exit(0);
    }
    int len = 0;
    a = a * (b ^ (n - 2));
    for (int i = 0; i < 18 - to_string(a[0][0]).size(); i++) {
        cout << 0;
    }
    cout << a[0][0] << endl;
    return 0;
}

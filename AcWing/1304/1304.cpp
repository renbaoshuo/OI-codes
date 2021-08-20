#include <bits/stdc++.h>

using namespace std;

int n, m, k;

void mul(int c[][4], int a[][4], int b[][4]) {
    int t[4][4];
    memset(t, 0x00, sizeof(t));
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                t[i][j] = (t[i][j] + 1ll * a[i][k] * b[k][j]) % m;
            }
        }
    }
    memcpy(c, t, sizeof(t));
}

int main() {
    cin >> n >> m;
    k = n - 1;
    int f[4][4] = {1, 1, 1, 0};
    int a[4][4] = {
        {0, 1, 0, 0},
        {1, 1, 1, 0},
        {0, 0, 1, 1},
        {0, 0, 0, 1},
    };
    while (k) {
        if (k & 1) mul(f, f, a);
        mul(a, a, a);
        k >>= 1;
    }
    cout << ((1ll * n * f[0][2] - f[0][3]) % m + m) % m << endl;
    return 0;
}

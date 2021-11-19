#include <bits/stdc++.h>

using namespace std;

long long t, d, a[200005], f[200005][25];
int n, m, x;
char op;
bool flag;

void change(int u) {
    f[u][0] = a[u];
    for (int i = 1; u - (1 << i) >= 0; i++) {
        f[u][i] = max(f[u][i - 1], f[u - (1 << (i - 1))][i - 1]);
    }
}

long long find(int x, int y) {
    int d = (int)(log(y - x + 1) / log(2));
    return max(f[y][d], f[x + (1 << d) - 1][d]);
}

int main() {
    cin >> m >> d;
    while (m--) {
        cin >> op >> x;
        if (op == 'A') {
            a[++n] = (x + t) % d;
            change(n);
        } else if (op == 'Q') {
            if (x == 1) {
                cout << (t = a[n]) << endl;
            } else {
                cout << (t = find(n - x + 1, n)) << endl;
            }
        }
    }
    return 0;
}

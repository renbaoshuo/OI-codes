#include <bits/stdc++.h>

using namespace std;

int n;
double f[10005], g[10005];

int main() {
    cin >> n;
    f[n] = g[n] = 0;
    for (int i = n - 1; i >= 0; i--) {
        f[i] = f[i + 1] + 1.00 * n / (n - i);
        g[i] = 1.00 * i / (n - i) * (2 * f[i] + 1) + g[i + 1] + 2 * f[i + 1] + 1;
    }
    cout << fixed << setprecision(2) << 1.00 * (g[0] + f[0]) / 2 << endl;
    return 0;
}

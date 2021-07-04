#include <bits/stdc++.h>

using namespace std;

int n, m, x, y, ans, f[100005];

int find(int x) {
    if (f[x] == x) return x;
    return f[x] = find(f[x]);
}

void unity(int x, int y) {
    f[find(x)] = find(y);
}

int main() {
    while (cin >> n, n) {
        ans = 0;
        cin >> m;
        for (int i = 1; i <= n; i++) {
            f[i] = i;
        }
        for (int i = 1; i <= m; i++) {
            cin >> x >> y;
            unity(x, y);
        }
        for (int i = 1; i <= n; i++) {
            if (find(i) == i) ans++;
        }
        cout << --ans << endl;
    }
    return 0;
}

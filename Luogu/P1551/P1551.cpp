#include <bits/stdc++.h>

using namespace std;

int n, m, p, x, y, j, f[5005];

int find(int x) {
    if (f[x] == x) return f[x];
    return f[x] = find(f[x]);
}

int main() {
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++) {
        f[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        f[find(x)] = find(y);
    }
    for (int i = 1; i <= p; i++) {
        cin >> x >> y;
        if (find(x) == find(y)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}

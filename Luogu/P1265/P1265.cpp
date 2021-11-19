#include <bits/stdc++.h>

using namespace std;

struct point {
    long long x, y;
};

int n, m;
bool v[5005];
long long d[5005];
point city[5005];

void prim() {
    memset(d, 0x3f, sizeof(d));
    memset(v, 0x00, sizeof(v));
    d[1] = 0;
    for (int i = 1; i <= n - 1; i++) {
        int x = 0;
        for (int j = 1; j <= n; j++) {
            if (!v[j] && (x == 0 || d[j] < d[x])) {
                x = j;
            }
        }
        v[x] = 1;
        for (int y = 1; y <= n; y++) {
            if (!v[y]) {
                d[y] = min(d[y], (city[x].x - city[y].x) * (city[x].x - city[y].x) + (city[x].y - city[y].y) * (city[x].y - city[y].y));
            }
        }
    }
    return;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> city[i].x >> city[i].y;
    }
    prim();
    double ans = 0.00;
    for (int i = 1; i <= n; i++) {
        ans += sqrt((double)(d[i]));
    }
    cout << fixed << setprecision(2) << ans << endl;
    return 0;
}

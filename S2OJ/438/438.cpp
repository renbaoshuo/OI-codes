#include <bits/stdc++.h>

using namespace std;

double dis2d(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

double dis3d(int x1, int y1, int z1, int x2, int y2, int z2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2) + pow(z1 - z2, 2));
}

int main() {
    int n, r, d, v;
    double s = 9999999.00, f[1005][1005];
    struct {
        int x, y, z;
    } a[1005];
    cin >> n >> r >> d >> v;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y >> a[i].z;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
                f[i][j] = i == j ? 0 : 0x3f3f3f3f;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            double dis1 = dis2d(a[i].x, a[i].y, a[j].x, a[j].y);
            if (dis1 <= r && abs(a[i].z - a[j].z) <= d) {
                double dis2 = dis3d(a[i].x, a[i].y, a[i].z, a[j].x, a[j].y, a[j].z);
                f[i][j] = dis2;
                f[j][i] = dis2;
            }
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
        }
    }
    if(f[1][n] == 0x3f3f3f3f) {
        cout << "No Solution" << endl;
    } else {
        cout << fixed << setprecision(3) << f[1][n] / v << endl;
    }
    return 0;
}

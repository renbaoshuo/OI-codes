#include <bits/stdc++.h>

using namespace std;

const int fx[] = {0, -2, -1, 1, 2, 2, 1, -1, -2};
const int fy[] = {0, 1, 2, 2, 1, -1, -2, -2, -1};
int       bx, by, mx, my;
long long f[30][30];
bool      b[30][30];

int main() {
    cin >> bx >> by >> mx >> my;
    bx += 2;
    by += 2;
    mx += 2;
    my += 2;
    f[2][2]   = 1;
    b[mx][my] = true;
    for (int i = 1; i <= 8; i++) {
        b[mx + fx[i]][my + fy[i]] = true;
    }
    for (int i = 2; i <= bx; i++) {
        for (int j = 2; j <= by; j++) {
            if (b[i][j]) {
                continue;
            }
            else {
                f[i][j] = max(f[i][j], f[i - 1][j] + f[i][j - 1]);
            }
        }
    }
    cout << f[bx][by] << endl;
    return 0;
}

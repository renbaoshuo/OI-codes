#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 35;

int n, f[N][N], root[N][N];

void dfs(int l, int r) {
    if (l > r) return;

    cout << root[l][r] << ' ';

    if (l == r) return;
    dfs(l, root[l][r] - 1);
    dfs(root[l][r] + 1, r);
}

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> f[i][i];
        f[i][i - 1] = 1;
        root[i][i] = i;
    }

    for (int len = 2; len <= n; len++) {
        for (int l = 1, r = len; r <= n; l++, r++) {
            f[l][r] = f[l][l] + f[l + 1][r];
            root[l][r] = l;

            for (int k = l + 1; k < r; k++) {
                if (f[l][r] < f[l][k - 1] * f[k + 1][r] + f[k][k]) {
                    f[l][r] = f[l][k - 1] * f[k + 1][r] + f[k][k];
                    root[l][r] = k;
                }
            }
        }
    }

    cout << f[1][n] << endl;

    dfs(1, n);

    cout << endl;

    return 0;
}

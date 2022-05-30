#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 15,
          M = 0xfff + 5;  // = (11111111111)2 + 5
const int mod = 1e8;

int m, n, a[N], f[N][M], ans;
bool s[M];

int main() {
    std::ios::sync_with_stdio(false);

    cin >> m >> n;

    for (int i = 1; i <= m; i++) {
        for (int j = 1, x; j <= n; j++) {
            cin >> x;
            a[i] <<= 1;
            a[i] += x;
        }
    }

    for (int i = 0; i < 0xfff; i++) {
        // 行内不存在相邻的草地
        if (!((i << 1) & i) && !((i >> 1) & i)) {
            s[i] = true;
        }
    }

    f[0][0] = 1;
    for (int i = 1; i <= m; i++) {
        // 当前行的状态
        for (int j = 0; j < 0xfff; j++) {
            // j 是合法的状态，且没有草被种在贫瘠的土地上
            if (s[j] && (a[i] & j) == j) {
                // 枚举上一行的状态
                for (int k = 0; k < 0xfff; k++) {
                    if (!(k & j)) {  // k 和 j 间不存在相邻的土地
                        f[i][j] = (f[i][j] + f[i - 1][k]) % mod;
                    }
                }
            }
        }
    }

    for (int i = 0; i < 0xfff; i++) {
        ans = (ans + f[m][i]) % mod;
    }

    cout << ans << endl;

    return 0;
}

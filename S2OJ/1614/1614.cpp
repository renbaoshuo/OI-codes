#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int K = 17;

int k, a[1 << K], b[1 << K], c[1 << K], f[K + 1][1 << K];

void dfs(int s, int d, int x) {
    int t = ((1 << k) - 1) ^ s;

    for (int i = t;; i = (i - 1) & t) {
        if (d) f[d][i] = std::max(f[d - 1][i], f[d - 1][i | (1 << x)]);
        c[s | i] = std::max(c[s | i], f[d][i] + a[s]);
        if (!i) break;
    }

    for (int i = x + 1; i < k; i++) {
        dfs(s | (1 << i), d + 1, i);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> k;

    for (int i = 0; i < 1 << k; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < 1 << k; i++) {
        cin >> b[i];

        f[0][i] = b[i];
    }

    dfs(0, 0, -1);

    for (int i = 0; i < 1 << k; i++) {
        cout << c[i] << ' ';
    }

    cout << endl;

    return 0;
}

#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

int n, cnt, a[N], b[N], c[N], p[N], f[N];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];

        p[a[i]] = i;
    }

    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    for (int i = 1; i <= n; i++) {
        if (p[b[i]] > c[cnt]) {
            c[++cnt] = p[b[i]];
            f[i] = cnt;
        } else {
            int k = std::lower_bound(c + 1, c + cnt + 1, p[b[i]]) - c;
            c[k] = p[b[i]];
            f[i] = k;
        }
    }

    cout << cnt << endl;

    return 0;
}

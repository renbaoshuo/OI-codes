#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1005;

int n, m, a[N], ans;

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        for (int j = 1, x; j <= n; j++) {
            cin >> x;
            if (x) a[j]++;
        }
    }

    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        if (x == (a[i] > m - a[i])) ans++;
    }

    cout << ans << endl;

    return 0;
}

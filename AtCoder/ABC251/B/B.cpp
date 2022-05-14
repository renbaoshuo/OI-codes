#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 305;

int n, w, a[N], ans;
bool vis[1000005];

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n >> w;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n - 2; i++) {
        for (int j = i + 1; j <= n - 1; j++) {
            for (int k = j + 1; k <= n; k++) {
                if (a[i] + a[j] + a[k] <= w) {
                    vis[a[i] + a[j] + a[k]] = true;
                }
            }
        }
    }

    for (int i = 1; i <= n - 1; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (a[i] + a[j] <= w) {
                vis[a[i] + a[j]] = true;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (a[i] <= w) {
            vis[a[i]] = true;
        }
    }

    for (int i = 1; i <= 1000000; i++) {
        if (vis[i]) ans++;
    }

    cout << ans << endl;

    return 0;
}

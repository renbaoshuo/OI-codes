#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 70;

int n, m, l, a[N], next[N];
bool vis[N]{false, true};

void dfs(int now, int last, int rest) {
    if (!rest) {
        if (now == m) {
            cout << l << endl;

            exit(0);
        }

        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                vis[i] = true;
                dfs(now + 1, i, l - a[i]);
                vis[i] = false;

                break;
            }
        }
    }

    int p = std::lower_bound(a + last + 1, a + n + 1, rest, std::greater<int>()) - a;

    for (int i = p; i <= n; i++) {
        if (!vis[i]) {
            vis[i] = true;
            dfs(now, i, rest - a[i]);
            vis[i] = false;

            if (rest == a[i] || rest == l) return;
            i = next[i];
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int sum = std::accumulate(a + 1, a + 1 + n, 0);

    std::sort(a + 1, a + 1 + n, std::greater<int>());

    for (int i = n; i; i--) {
        next[i] = a[i] == a[i + 1] ? next[i + 1] : i;
    }

    for (l = a[1]; l <= sum / 2; l++) {
        if (sum % l) continue;

        m = sum / l;
        dfs(1, 1, l - a[1]);
    }

    cout << sum << endl;

    return 0;
}

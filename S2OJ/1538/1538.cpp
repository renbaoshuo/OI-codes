#include <iostream>
#include <algorithm>
#include <array>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 3005;

int n, root, max_dep;
long long ans;
std::vector<int> g[N];
std::array<int, N> f1, f2, cnt;

void dfs(int u, int f, int d) {
    cnt[d]++;
    max_dep = std::max(max_dep, d);

    for (int v : g[u]) {
        if (v == f) continue;

        dfs(v, u, d + 1);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1, x; i <= n; i++) {
        cin >> x;

        if (x) {
            g[x].emplace_back(i);
            g[i].emplace_back(x);
        } else {
            root = i;
        }
    }

    dfs(root, 0, 1);

    for (int i = 1; i <= n; i++) {
        std::fill(f1.begin(), f1.end(), 0);
        std::fill(f2.begin(), f2.end(), 0);

        for (int u : g[i]) {
            max_dep = 0;
            std::fill(cnt.begin(), cnt.end(), 0);

            dfs(u, i, 1);

            for (int j = 1; j <= max_dep; j++) {
                ans += f1[j] * cnt[j];
                f1[j] += f2[j] * cnt[j];
                f2[j] += cnt[j];
            }
        }
    }

    cout << ans << endl;

    return 0;
}

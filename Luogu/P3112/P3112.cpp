#include <iostream>
#include <algorithm>
#include <limits>
#include <tuple>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 25;

int n, h, ans = -1;
std::tuple<int, int, int> a[N];
bool vis[N];

void dfs(int x) {
    if (x == n + 1) {
        int hh = 0, ss = std::numeric_limits<int>::max();

        for (int i = 1; i <= n; i++) {
            if (!vis[i]) continue;

            hh += std::get<0>(a[i]);

            int sum = 0;

            for (int j = i + 1; j <= n; j++) {
                if (!vis[j]) continue;

                sum += std::get<1>(a[j]);
            }

            ss = std::min(ss, std::get<2>(a[i]) - sum);
        }

        if (hh >= h) {
            ans = std::max(ans, ss);
        }

        return;
    }

    dfs(x + 1);
    vis[x] = true;
    dfs(x + 1);
    vis[x] = false;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> h;

    for (int i = 1; i <= n; i++) {
        cin >> std::get<0>(a[i]) >> std::get<1>(a[i]) >> std::get<2>(a[i]);
    }

    std::sort(a + 1, a + 1 + n, [&](decltype(a[0]) x, decltype(a[0]) y) -> bool {
        return std::get<1>(x) + std::get<2>(x) > std::get<1>(y) + std::get<2>(y);
    });

    dfs(0);

    if (ans == -1) {
        cout << "Mark is too tall" << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}

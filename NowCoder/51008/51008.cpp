#include <iostream>
#include <cmath>
#include <functional>
#include <queue>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

int n, m, p = 1, a[N], pre[N], suf[N], ans;
bool vis[N];
std::priority_queue<
    std::pair<int, int>,
    std::vector<std::pair<int, int>>,
    std::greater<>>
    q;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1, x; i <= n; i++) {
        cin >> x;

        if (a[p] * x < 0) {
            a[++p] = x;
        } else {
            a[p] += x;
        }
    }

    int cnt = 0;
    for (int i = 1; i <= p; i++) {
        pre[i] = i - 1;
        suf[i] = i + 1;

        if (a[i] > 0) {
            ans += a[i];
            cnt++;
        }

        q.emplace(std::abs(a[i]), i);
    }

    while (cnt > m) {
        while (vis[q.top().second]) q.pop();

        auto o = q.top();
        q.pop();

        if (pre[o.second] != 0 && suf[o.second] != p + 1 || a[o.second] > 0) {
            cnt--;
            ans -= o.first;

            int l = pre[o.second],
                r = suf[o.second];

            a[o.second] += a[l] + a[r];
            q.emplace(std::abs(a[o.second]), o.second);

            pre[suf[l]] = pre[l];
            suf[pre[l]] = suf[l];
            vis[l] = true;

            pre[suf[r]] = pre[r];
            suf[pre[r]] = suf[r];
            vis[r] = true;
        }
    }

    cout << ans << endl;

    return 0;
}

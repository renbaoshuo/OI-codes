#include <iostream>
#include <functional>
#include <queue>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e5 + 5;

int n, m, a[N], pre[N], suf[N], ans;
bool vis[N];
std::priority_queue<std::pair<int, int>> q;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    if (n / 2 < m) {
        cout << "Error!" << endl;

        exit(0);
    }

    for (int i = 1; i <= n; i++) {
        cin >> a[i];

        pre[i] = i - 1 ? i - 1 : n;
        suf[i] = i == n ? 1 : i + 1;

        q.emplace(a[i], i);
    }

    for (int i = 1; i <= m; i++) {
        while (!q.empty() && vis[q.top().second]) q.pop();

        auto o = q.top();
        q.pop();

        vis[pre[o.second]] = vis[suf[o.second]] = true;
        a[o.second] = a[pre[o.second]] + a[suf[o.second]] - a[o.second];
        q.emplace(a[o.second], o.second);
        ans += o.first;

        pre[o.second] = pre[pre[o.second]];
        suf[o.second] = suf[suf[o.second]];
        pre[suf[o.second]] = o.second;
        suf[pre[o.second]] = o.second;
    }

    cout << ans << endl;

    return 0;
}

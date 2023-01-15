#include <iostream>
#include <queue>
#include <utility>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 5e5 + 5;

int n, k, a[N << 1], l[N << 1], r[N << 1];
long long ans;
std::priority_queue<std::pair<int, int>> q;
bool vis[N << 1];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];

        q.emplace(a[i], i);
        l[i] = i - 1;
        r[i] = i + 1;
    }

    for (int i = 1, cnt = n; i <= k; i++) {
        while (!q.empty() && vis[q.top().second]) q.pop();

        if (q.empty() || q.top().first < 0) break;

        int id = q.top().second;
        ans += q.top().first;
        q.pop();

        vis[id] = vis[l[id]] = vis[r[id]] = true;
        a[++cnt] = a[l[id]] + a[r[id]] - a[id];
        l[cnt] = l[l[id]], r[cnt] = r[r[id]];
        r[l[cnt]] = cnt, l[r[cnt]] = cnt;

        q.emplace(a[cnt], cnt);
    }

    cout << ans << endl;

    return 0;
}

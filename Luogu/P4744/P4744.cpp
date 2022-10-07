#include <iostream>
#include <algorithm>
#include <cmath>
#include <functional>
#include <queue>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

int n, k, p = 1, a[N], pre[N], nxt[N], ans;
bool vis[N];
std::priority_queue<std::pair<int, int>> q;
std::vector<int> nums;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    for (int i = 1, x; i <= n; i++) {
        cin >> x;

        if (static_cast<long long>(a[p]) * x < 0) {
            a[++p] = x;
        } else {
            a[p] += x;
        }

        nums.emplace_back(x);
    }

    std::sort(nums.begin(), nums.end(), std::greater<>());

    if (nums[0] < 0) {
        for (int i = 0; i < k; i++) {
            ans += nums[i];
        }

        cout << ans << endl;

        exit(0);
    }

    if (a[1] > 0 && a[p] > 0) {
        a[1] += a[p--];
    }

    int cnt = 0;
    for (int i = 1; i <= p; i++) {
        pre[i] = i == 1 ? p : i - 1;
        nxt[i] = i == p ? 1 : i + 1;

        if (a[i] > 0) {
            ans += a[i];
            cnt++;
            a[i] = -a[i];
        }

        q.emplace(a[i], i);
    }

    while (cnt > k) {
        int i = q.top().second;
        q.pop();

        if (vis[i]) continue;

        cnt--;
        ans += a[i];

        int l = pre[i],
            r = nxt[i];

        a[i] = a[l] + a[r] - a[i];

        pre[i] = pre[l];
        nxt[pre[l]] = i;
        vis[l] = true;

        pre[nxt[r]] = i;
        nxt[i] = nxt[r];
        vis[r] = true;

        q.emplace(a[i], i);
    }

    cout << ans << endl;

    return 0;
}

#include <iostream>
#include <limits>
#include <queue>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 100005;

int n, k, a[N], pre[N], suf[N];
long long c[N], ans;
std::priority_queue<
    std::pair<int, long long>,
    std::vector<std::pair<int, long long>>,
    auto(*)(std::pair<int, long long>, std::pair<int, long long>)->bool>
q([](std::pair<int, long long> a, std::pair<int, long long> b) -> bool {
    return a.second > b.second;
});

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i < n; i++) {
        c[i] = static_cast<long long>(a[i + 1]) - a[i];
        pre[i] = i - 1;
        suf[i] = i + 1;
    }
    suf[n - 1] = 0;

    for (int i = 1; i < n; i++) {
        q.emplace(i, c[i]);
    }

    while (k--) {
        auto o = q.top();
        q.pop();

        if (o.second != c[o.first]) {
            k++;

            continue;
        }

        ans += o.second;

        int l = pre[o.first],
            r = suf[o.first];

        suf[o.first] = suf[r];
        pre[suf[o.first]] = o.first;
        pre[o.first] = pre[l];
        suf[pre[o.first]] = o.first;

        c[o.first] = (l && r) ? std::min(static_cast<long long>(std::numeric_limits<int>::max()), c[l] + c[r] - c[o.first]) : std::numeric_limits<int>::max();
        c[l] = c[r] = std::numeric_limits<int>::max();

        q.emplace(o.first, c[o.first]);
    }

    cout << ans << endl;

    return 0;
}

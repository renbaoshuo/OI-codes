#include <iostream>
#include <deque>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e6 + 5;

int n, d, a[N], ans;
long long p, sum, s[N], t[N];
std::deque<int> q;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> p >> d;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];

        s[i] = s[i - 1] + a[i];
    }

    for (int i = 1; i <= n; i++) {
        t[i] = s[i] - s[i - d];
    }

    ans = d;
    sum = s[d + 1];
    q.push_back(d);

    for (int i = d + 1, l = 1, r = 0; i <= n; sum += a[++i]) {
        while (!q.empty() && t[q.back()] <= t[i]) q.pop_back();
        q.push_back(i);
        while (sum - t[q.front()] > p) {
            if (q.front() < l + d) q.pop_front();
            sum -= a[l++];
        }
        ans = std::max(ans, i - l + 1);
    }

    cout << ans << endl;

    return 0;
}

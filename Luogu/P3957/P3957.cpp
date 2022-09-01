#include <iostream>
#include <algorithm>
#include <deque>
#include <limits>
#include <utility>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 5e5 + 5;
const long long INF = 0x3f3f3f3f3f3f3f3f;

int n, d;
long long k, f[N], sum;
std::pair<long long, long long> a[N];

bool check(long long l, long long r) {
    std::deque<long long> q;

    for (int i = 1, j = 0; i <= n; i++) {
        f[i] = -INF;

        while (j < i && l <= a[i].first - a[j].first) {
            if (f[j] != -INF) {
                while (!q.empty() && f[q.back()] <= f[j]) q.pop_back();
                q.push_back(j);
            }

            j++;
        }

        while (!q.empty() && a[i].first - a[q.front()].first > r) {
            q.pop_front();
        }

        if (!q.empty()) {
            f[i] = std::max(f[i], f[q.front()] + a[i].second);
        }

        if (f[i] >= k) return true;
    }

    return false;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> d >> k;

    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;

        sum += a[i].second;
    }

    long long l = 0, r = INF;

    while (l < r) {
        long long mid = l + r >> 1;

        if (check(std::max(d - mid, 0ll), d + mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    cout << (r == INF ? -1 : r) << endl;

    return 0;
}

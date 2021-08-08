#include <bits/stdc++.h>

using namespace std;

int n;
long long ans, cnt, x;
pair<long long, long long> q[300005];

bool cmp(pair<long long, long long> a, pair<long long, long long> b) {
    return (a.first - b.first) * (a.second + b.second) > (a.first + b.first) * (a.second - b.second);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> q[i].first >> q[i].second;
    }
    sort(q, q + n, cmp);
    for (int i = 0; i < n; i++) {
        cnt += abs(2 * q[i].second * x + q[i].second * q[i].first);
        x += q[i].first;
    }
    ans = max(ans, cnt);
    x = 0;
    cnt = 0;
    for (int i = n - 1; i >= 0; i--) {
        cnt += abs(2 * q[i].second * x + q[i].second * q[i].first);
        x += q[i].first;
    }
    ans = max(ans, cnt);
    cout << ans << endl;
    return 0;
}

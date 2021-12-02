#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;

int n, now;
long long ans;
std::pair<int, int> a[100005];
std::priority_queue<int> q;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i].second;
    }
    q.push(0);
    for (int i = 1; i <= n; i++) {
        int max = q.top();
        int maxn = now;
        for (int j = now + 1; j <= n; j++) {
            if ((a[j].first - a[now].first) * 2 + a[j].second >= max) {
                max = (a[j].first - a[now].first) * 2 + a[j].second;
                maxn = j;
            }
        }
        if (maxn != now) q.push(max);
        for (int j = now + 1; j < maxn; j++) {
            q.push(a[j].second);
        }
        now = maxn;
        ans += q.top();
        q.pop();
        cout << ans << endl;
    }
    return 0;
}

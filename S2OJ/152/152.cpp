#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;

long long n, k, a[1000005], sum, cnt, pos, ans, num, res;

bool check(int x);

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int l = 1;
    int r = a[n] - a[1];
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) {
            r = mid - 1;
            num = cnt;
            pos = mid;
            ans = res;
        } else {
            l = mid + 1;
        }
    }
    cout << ans - (num - k) * pos << endl;
    return 0;
}

bool check(int x) {
    cnt = 0;
    res = 0;
    sum = 0;
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        while (!q.empty() && a[i] - a[q.front()] > x) {
            sum -= a[q.front()];
            q.pop();
        }
        cnt += q.size();
        res += q.size() * a[i] - sum;
        q.push(i);
        sum += a[i];
    }
    return cnt >= k;
}

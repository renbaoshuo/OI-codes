#include <bits/stdc++.h>

using namespace std;

struct node {
    long long p, q;
} a[50005];

int n, k;
long long m, ans;
priority_queue<long long, vector<long long>, greater<long long>> q;

int main() {
    cin >> n >> k >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i].p >> a[i].q;
    }
    sort(a, a + n, [](node a, node b) { return a.q < b.q; });
    for (int i = 0; i < k; i++) {
        ans += a[i].q;
        q.push(a[i].p - a[i].q);
        if (ans > m) {
            cout << i << endl;
            exit(0);
        }
        if (i == n - 1) {
            cout << n << endl;
            exit(0);
        }
    }
    sort(a + k, a + n, [](node a, node b) { return a.p < b.p; });
    for (int i = k; i < n; i++) {
        auto t = q.top();
        ans += a[i].p;
        if (a[i].q + t < a[i].p) {
            q.pop();
            ans += t + a[i].q - a[i].p;
            q.push(a[i].p - a[i].q);
        }
        if (ans > m) {
            cout << i << endl;
            exit(0);
        }
    }
    cout << n << endl;
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int n, t, l, r, d[10005];

int check(int x) {
    int f = 0;
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 1; i <= x; i++) {
        q.push(d[i]);
    }
    if (f > t) {
        return false;
    }
    int z = x + 1, c = 0;
    for (int i = z; i <= n; i++) {
        f += q.top() - c;
        c = q.top();
        q.pop();
        if (f > t) {
            return false;
        }
        q.push(d[i] + c);
    }
    for (int i = 1; i <= x; i++) {
        f += q.top() - c;
        c = q.top();
        q.pop();
        if (f > t) {
            return false;
        }
    }
    return true;
}

int main() {
    cin >> n >> t;
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }
    l = 0, r = n;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << l << endl;
    return 0;
}

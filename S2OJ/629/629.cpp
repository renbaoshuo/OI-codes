#pragma GCC optimize(2)

#include <bits/stdc++.h>

using namespace std;

int n, x, ans;
char op;
priority_queue<int, vector<int>, greater<int>> q;

int main() {
    std::ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> op >> x;
        if (op == 'c') {
            q.push(x);
        } else {
            while (q.size() >= x && i != n) q.pop();
        }
    }
    while (!q.empty()) {
        ans += q.top();
        q.pop();
    }
    cout << ans << endl;
    return 0;
}

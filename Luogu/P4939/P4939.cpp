#include <bits/stdc++.h>

using namespace std;

int n, m, op, x, y, t[10000005];

int lowbit(int k) {
    return k & -k;
}

void add(int x, int v) {
    for (int i = x; i <= n + 1; i += lowbit(i)) {
        t[i] += v;
    }
}

int sum(int x) {
    int ans = 0;
    for (int i = x; i > 0; i -= lowbit(i)) {
        ans += t[i];
    }
    return ans;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> op >> x;
        if (op == 0) {
            cin >> y;
            add(x, 1);
            add(y + 1, -1);
        } else if (op == 1) {
            cout << sum(x) << endl;
        }
    }
    return 0;
}

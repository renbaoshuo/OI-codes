#include <bits/stdc++.h>

using namespace std;

int n, m, a, l, r, sum[100005];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        sum[i] = sum[i - 1] + a;
    }
    for (int i = 1; i <= m; i++) {
        cin >> l >> r;
        cout << sum[r] - sum[l - 1] << endl;
    }
    return 0;
}

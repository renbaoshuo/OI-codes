#include <bits/stdc++.h>

using namespace std;

int n, m, k, t, x, y, ans, sum;

int main() {
    cin >> n >> m >> k >> t;
    for (int i = 0; i < k; i++) {
        sum = 0;
        cin >> x >> y;
        for (int i = max(1, x - t); i <= min(n, x + t); i++) {
            for (int j = max(1, y - t); j <= min(m, y + t); j++) {
                if (sqrt((x - i) * (x - i) + (y - j) * (y - j)) <= t) {
                    sum++;
                }
            }
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;
    return 0;
}

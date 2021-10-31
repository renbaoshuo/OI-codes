#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, d, p[100005], ans = 0;
    cin >> n >> d;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    sort(p, p + n);
    for (int i = 0; i < n; i++) {
        ans += (upper_bound(p + i, p + n, p[i] + d) - p) - i - 1;
    }
    cout << ans << endl;
    return 0;
}

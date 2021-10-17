#include <bits/stdc++.h>

using namespace std;

int x, y, n;

double dfs(double x, double y, int k) {
    if (k == 1) return max(x, y) / min(x, y);
    double ans = 0x3f3f3f3f;
    for (int i = 1; i <= k / 2; i++) {
        ans = min({ans, max(dfs(x / k * i, y, i), dfs(x - x / k * i, y, k - i)), max(dfs(x, y / k * i, i), dfs(x, y - y / k * i, k - i))});
    }
    return ans;
}

int main() {
    cin >> x >> y >> n;
    cout << fixed << setprecision(6) << dfs(x, y, n) << endl;
    return 0;
}

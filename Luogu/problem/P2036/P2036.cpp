#include <bits/stdc++.h>

using namespace std;

struct {
    int s, b;
} a[15];
int n, ans = 0x3f3f3f3f;

void dfs(int now, int s, int b) {
    if (now > n) {
        if (s == 1 && b == 0) return;
        ans = min(abs(s - b), ans);
        return;
    }
    dfs(now + 1, s * a[now].s, b + a[now].b);
    dfs(now + 1, s, b);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].s >> a[i].b;
    }
    dfs(1, 1, 0);
    cout << ans << endl;
    return 0;
}

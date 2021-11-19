#include <bits/stdc++.h>

using namespace std;

int n, ans = 999999;

void dfs(int cnt, int k, int last) {
    if (k > ans) {
        return;
    }
    if (cnt > n) {
        return;
    }
    if (cnt == n) {
        ans = min(ans, k);
        return;
    }
    int i = last;
    while (i * i * i * i <= n - cnt) {
        i++;
    }
    while (i >= last) {
        dfs(cnt + i * i * i * i, k + 1, i);
        i--;
    }
    return;
}

int main() {
    cin >> n;
    dfs(0, 0, 1);
    cout << ans << endl;
    return 0;
}

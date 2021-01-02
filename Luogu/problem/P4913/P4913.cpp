#include <bits/stdc++.h>

using namespace std;

int n, l[1000005], r[1000005];

int dfs(int now, int cnt) {
    if (l[now] == 0 && r[now] == 0) {
        return cnt;
    }
    else if (l[now] == 0) {
        return dfs(r[now], cnt + 1);
    }
    else if (r[now] == 0) {
        return dfs(l[now], cnt + 1);
    }
    return max(dfs(l[now], cnt + 1), dfs(r[now], cnt + 1));
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
    }
    cout << dfs(1, 1) << endl;
    return 0;
}

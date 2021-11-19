// https://www.luogu.com.cn/record/36322094

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, a[100005], minn = 100000, t = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n - m + 1; i++) {
        for (int j = 1; j <= m; j++) {
            t += a[i + j - 1];
        }
        minn = min(t, minn);
        t = 0;
    }
    cout << minn << endl;
    return 0;
}
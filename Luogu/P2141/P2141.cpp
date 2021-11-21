#include <bits/stdc++.h>

using namespace std;

int n, a[105], ans;
bool vis[105];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k <= n; k++) {
                if (a[i] + a[j] == a[k] && !vis[k]) {
                    ans++;
                    vis[k] = true;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}

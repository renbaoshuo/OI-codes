#include <bits/stdc++.h>

using namespace std;

int l, m, u, v, ans;
bool t[10005];

int main() {
    cin >> l >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        for (int j = u; j <= v; j++) {
            t[j] = true;
        }
    }
    for (int i = 0; i <= l; i++) {
        ans += !t[i];
    }
    cout << ans << endl;
    return 0;
}

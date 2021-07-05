#include <bits/stdc++.h>

using namespace std;

int n, u, v, deg[100005], ans;

int main() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        ans = max({ans, ++deg[u], ++deg[v]});
    }
    cout << ++ans << endl;
    return 0;
}

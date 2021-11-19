#include <bits/stdc++.h>

using namespace std;

/* Template: 树形 DP */
vector<int> son[6005];
int n, l, k, f[6005][2], h[6005];
bool v[6005];

void dp(int x) {
    int y;
    f[x][0] = 0;
    f[x][1] = h[x];
    for (int i = 0; i < son[x].size(); i++) {
        y = son[x][i];
        dp(y);
        f[x][0] += max(f[y][0], f[y][1]);
        f[x][1] += f[y][0];
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    for (int i = 1; i < n; i++) {
        cin >> l >> k;
        v[l] = 1;
        son[k].push_back(l);
    }
    int root;
    for (int i = 1; i <= n; i++) {
        if (!v[i]) {
            root = i;
            break;
        }
    }
    dp(root);
    cout << max(f[root][0], f[root][1]) << endl;
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int n, m, a, b, fa[100005];
char op;

int getfa(int x) {
    return fa[x] == x ? fa[x] : fa[x] = getfa(fa[x]);
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
    for (int i = 0; i < m; i++) {
        cin >> op >> a >> b;
        if (op == 'M') {
            fa[getfa(a)] = getfa(b);
        } else {
            cout << (getfa(a) == getfa(b) ? "Yes" : "No") << endl;
        }
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int n, m, x, y, fa[40005], res;
char d;

int get(int x, int y) {
    return x * n + y;
}

int find(int x) {
    return fa[x] == x ? fa[x] : fa[x] = find(fa[x]);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n * n; i++) {
        fa[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        cin >> x >> y >> d;
        int a = get(--x, --y);
        int b = d == 'D' ? get(x + 1, y) : get(x, y + 1);
        int pa = find(a);
        int pb = find(b);
        if (pa == pb) {
            res = i;
            break;
        } else {
            fa[pa] = pb;
        }
    }
    if (!res) {
        cout << "draw" << endl;
    } else {
        cout << res << endl;
    }
    return 0;
}

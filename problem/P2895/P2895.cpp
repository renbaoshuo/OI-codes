#include <bits/stdc++.h>

using namespace std;

const int dx[] = {0, 0, 0, -1, 1};
const int dy[] = {0, 1, -1, 0, 0};

struct node {
    int x, y, t;

    node() {
        x = y = t = 0;
    }
    node(int _x, int _y, int _t) {
        x = _x, y = _y, t = _t;
    }
};

int n, x, y, t, m[305][305], f[305][305];

int main() {
    memset(m, 0x3f, sizeof(m));
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x >> y >> t;
        m[x][y] = min(m[x][y], t);
        for (int j = 1; j <= 4; j++) {
            int xx = x + dx[j];
            int yy = y + dy[j];
            if (xx < 0 || yy < 0) continue;
            m[xx][yy] = min(m[xx][yy], t);
        }
    }
    queue<node> q;
    f[0][0] = 1;
    if (m[0][0] == 0x3f3f3f3f) {
        cout << 0 << endl;
        return 0;
    }
    q.push(node(0, 0, 0));
    while (!q.empty()) {
        int xx = q.front().x;
        int yy = q.front().y;
        int tt = q.front().t;
        q.pop();
        for (int i = 1; i <= 4; i++) {
            int u = xx + dx[i];
            int v = yy + dy[i];
            if (f[u][v] || u < 0 || v < 0 || tt + 1 >= m[u][v]) continue;
            if (m[u][v] == 0x3f3f3f3f) {
                cout << tt + 1 << endl;
                return 0;
            }
            q.push(node(u, v, tt + 1));
            f[u][v] = 1;
        }
    }
    cout << -1 << endl;
    return 0;
}

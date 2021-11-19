#include <bits/stdc++.h>

using namespace std;

const int to[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int n, m, book[705][705];
bool vis[705][705];
char g[705][705];
pair<int, int> y, v, t;

struct node {
    int x, y, step;

    node()
        : x(0), y(0), step(0) {}
    node(int _x, int _y)
        : x(_x), y(_y), step(0) {}
    node(pair<int, int> _point)
        : x(_point.first), y(_point.second), step(0) {}
    node(pair<int, int> _point, int _step)
        : x(_point.first), y(_point.second), step(_step) {}
    node(int _x, int _y, int _step)
        : x(_x), y(_y), step(_step) {}
};

/**
 * @brief Preprocess the map
 */
void bfsV() {
    memset(vis, 0x00, sizeof(vis));
    memset(book, 0xff, sizeof(book));
    queue<node> q;
    q.push(v);
    vis[v.first][v.second] = true;
    book[v.first][v.second] = 0;
    while (!q.empty()) {
        int now;
        auto u = q.front();
        q.pop();

        // Top
        now = u.x - 1;
        while (now >= 0 && g[now][u.y] != 'I') {
            if (book[now][u.y] == -1) {
                book[now][u.y] = u.step;
            }
            now--;
        }

        // Bottom
        now = u.x + 1;
        while (now < n && g[now][u.y] != 'I') {
            if (book[now][u.y] == -1) {
                book[now][u.y] = u.step;
            }
            now++;
        }

        // Left
        now = u.y - 1;
        while (now >= 0 && g[u.x][now] != 'I') {
            if (book[u.x][now] == -1) {
                book[u.x][now] = u.step;
            }
            --now;
        }

        // Right
        now = u.y + 1;
        while (now < m && g[u.x][now] != 'I') {
            if (book[u.x][now] == -1) {
                book[u.x][now] = u.step;
            }
            now++;
        }

        // Expand
        for (int i = 0; i < 4; i++) {
            node e = node(u.x + to[i][0], u.y + to[i][1], u.step + 1);
            if (e.x >= 0 && e.x < n && e.y >= 0 && e.y < m && g[e.x][e.y] != 'I' && !vis[e.x][e.y]) {
                vis[e.x][e.y] = true;
                q.push(e);
            }
        }
    }
}

/**
 * @brief Search path to treasure
 */
void bfsY() {
    memset(vis, 0x00, sizeof(vis));
    queue<node> q;
    q.push(node(y, 1));
    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            node e = node(u.x + to[i][0], u.y + to[i][1], u.step + 1);
            if (e.x >= 0 && e.x < n && e.y >= 0 && e.y < m && e.step <= book[e.x][e.y] && !vis[e.x][e.y]) {
                vis[e.x][e.y] = true;
                // Reached
                if (e.x == t.first && e.y == t.second) {
                    cout << "YES" << endl;
                    return;
                }
                // Expand
                q.push(e);
            }
        }
    }
    // Can't reach treasure
    cout << "NO" << endl;
}

int main() {
    // Read from stdin
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> g[i];
    }
    // Mark you, viking and treasure
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 'Y') y = make_pair(i, j);
            if (g[i][j] == 'V') v = make_pair(i, j);
            if (g[i][j] == 'T') t = make_pair(i, j);
        }
    }
    bfsV();
    bfsY();
    return 0;
}

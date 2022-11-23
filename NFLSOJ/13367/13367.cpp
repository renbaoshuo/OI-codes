#include <iostream>
#include <fstream>
#include <string>

// using std::cin;
// using std::cout;
std::ifstream cin("field.in");
std::ofstream cout("field.out");
const char endl = '\n';

const int N = 505,
          M = (N << 1) * (N << 1);

int h, w, fa[M], x1[M], y1[M], x2[M], y2[M], ans;
std::string g[N << 1];
bool flag;

int id(int x, int y) {
    return (x - 1) * w + y;
}

int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void merge(int x, int y) {
    x = find(x), y = find(y);

    if (x == y) return;

    flag = true;
    fa[y] = x;

    x1[x] = std::min(x1[x], x1[y]);
    y1[x] = std::min(y1[x], y1[y]);

    x2[x] = std::max(x2[x], x2[y]);
    y2[x] = std::max(y2[x], y2[y]);
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> h >> w;

    for (int i = 1; i <= 2 * h + 1; i++) {
        cin >> g[i];

        g[i] = ' ' + g[i];
    }

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            int p = id(i, j);
            fa[p] = p;
            x1[p] = x2[p] = i;
            y1[p] = y2[p] = j;
        }
    }

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j < w; j++) {
            if (g[i * 2][j * 2 + 1] == '.') {
                merge(id(i, j), id(i, j + 1));
            }
        }
    }

    for (int j = 1; j <= w; j++) {
        for (int i = 1; i < h; i++) {
            if (g[i * 2 + 1][j * 2] == '.') {
                merge(id(i, j), id(i + 1, j));
            }
        }
    }

    while (true) {
        flag = false;

        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                if (x2[find(id(i, j))] > i) {
                    merge(id(i, j), id(i + 1, j));
                }
            }
        }

        for (int i = h; i >= 1; i--) {
            for (int j = 1; j <= w; j++) {
                if (x1[find(id(i, j))] < i) {
                    merge(id(i, j), id(i - 1, j));
                }
            }
        }

        for (int j = 1; j <= w; j++) {
            for (int i = 1; i <= h; i++) {
                if (y2[find(id(i, j))] > j) {
                    merge(id(i, j), id(i, j + 1));
                }
            }
        }

        for (int j = w; j >= 1; j--) {
            for (int i = 1; i <= h; i++) {
                if (y1[find(id(i, j))] < j) {
                    merge(id(i, j), id(i, j - 1));
                }
            }
        }

        if (!flag) break;
    }

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (find(id(i, j)) == id(i, j)) ans++;
        }
    }

    cout << ans << endl;

    return 0;
}

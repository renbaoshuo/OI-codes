#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e3 + 5,
          M = 1e5 + 5;

int n, m;
int cnt, fa[N];  // cnt: number of connected components

struct node {
    int x, y, t;
} a[M];

int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);

    if (x != y) {
        fa[x] = y;
        cnt--;
    }
}

bool cmp(const node &a, const node &b) {
    return a.t < b.t;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    // 初始化并查集
    cnt = n;

    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }

    for (int i = 1; i <= m; i++) {
        cin >> a[i].x >> a[i].y >> a[i].t;
    }

    std::sort(a + 1, a + 1 + m, cmp);

    for (int i = 1; i <= m; i++) {
        merge(a[i].x, a[i].y);

        if (cnt == 1) {
            cout << a[i].t << endl;

            exit(0);
        }
    }

    // 无解
    cout << -1 << endl;

    return 0;
}

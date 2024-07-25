#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e6 + 5;

int n, fa[N], cnt;

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);

    if (x != y) {
        fa[x] = y;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }

    for (int i = 1, x; i <= n; i++) {
        cin >> x;

        merge(i, x);
    }

    for (int i = 1; i <= n; i++) {
        if (fa[i] == i) cnt++;
    }

    cout << cnt << endl;

    return 0;
}

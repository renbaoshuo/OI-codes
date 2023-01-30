#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = (1 << 12) + 5;

int n, m, op;
long long c[N][N];

int lowbit(int x) {
    return x & -x;
}

void add(int x, int y, int v) {
    for (int i = x; i <= n; i += lowbit(i)) {
        for (int j = y; j <= m; j += lowbit(j)) {
            c[i][j] += v;
        }
    }
}

void add(int x1, int y1, int x2, int y2, int v) {
    add(x1, y1, v);
    add(x1, y2 + 1, -v);
    add(x2 + 1, y1, -v);
    add(x2 + 1, y2 + 1, v);
}

long long sum(int x, int y) {
    long long res = 0;

    for (int i = x; i; i -= lowbit(i)) {
        for (int j = y; j; j -= lowbit(j)) {
            res += c[i][j];
        }
    }

    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    while (cin >> op) {
        if (op == 1) {
            int a, b, c, d, k;

            cin >> a >> b >> c >> d >> k;

            add(a, b, c, d, k);
        } else {  // op == 2
            int x, y;

            cin >> x >> y;

            cout << sum(x, y) << endl;
        }
    }

    return 0;
}

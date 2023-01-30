#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = (1 << 12) + 5;

int n, m, op;
long long c1[N][N], c2[N][N], c3[N][N], c4[N][N];

int lowbit(int x) {
    return x & -x;
}

void add(int x, int y, int v) {
    for (int i = x; i <= n; i += lowbit(i)) {
        for (int j = y; j <= m; j += lowbit(j)) {
            c1[i][j] += v;
            c2[i][j] += v * x;
            c3[i][j] += v * y;
            c4[i][j] += v * x * y;
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
            res += (x + 1) * (y + 1) * c1[i][j]
                 - (y + 1) * c2[i][j]
                 - (x + 1) * c3[i][j]
                 + c4[i][j];
        }
    }

    return res;
}

long long sum(int x1, int y1, int x2, int y2) {
    return sum(x2, y2) - sum(x1 - 1, y2) - sum(x2, y1 - 1) + sum(x1 - 1, y1 - 1);
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
            int a, b, c, d;

            cin >> a >> b >> c >> d;

            cout << sum(a, b, c, d) << endl;
        }
    }

    return 0;
}

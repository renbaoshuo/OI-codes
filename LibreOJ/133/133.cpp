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

long long sum(int x, int y) {
    long long res = 0;

    for (int i = x; i; i -= lowbit(i)) {
        for (int j = y; j; j -= lowbit(j)) {
            res += c[i][j];
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
            int x, y, k;

            cin >> x >> y >> k;

            add(x, y, k);
        } else {  // op == 2
            int a, b, c, d;

            cin >> a >> b >> c >> d;

            cout << sum(a, b, c, d) << endl;
        }
    }

    return 0;
}

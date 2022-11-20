#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 5e5 + 5;

int n, m, c[N];

int lowbit(int x) {
    return x & -x;
}

void add(int x, int y) {
    for (; x <= n; x += lowbit(x)) c[x] += y;
}

int sum(int x) {
    int res = 0;
    for (; x; x -= lowbit(x)) res += c[x];
    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1, x; i <= n; i++) {
        cin >> x;

        add(i, x);
        add(i + 1, -x);
    }

    while (m--) {
        int op;

        cin >> op;

        if (op == 1) {
            int x, y, k;

            cin >> x >> y >> k;

            add(x, k);
            add(y + 1, -k);
        } else {  // op == 2
            int x;

            cin >> x;

            cout << sum(x) << endl;
        }
    }

    return 0;
}

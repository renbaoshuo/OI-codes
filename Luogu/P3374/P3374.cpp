#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 5e5 + 5;

int n, m, op, x, y;
int c[N];

inline int lowbit(int x) {
    return x & -x;
}

void add(int x, int y) {
    for (; x <= n; x += lowbit(x)) c[x] += y;
}

int sum(int x) {
    int ans = 0;
    for (; x; x -= lowbit(x)) ans += c[x];
    return ans;
}

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        add(i, x);
    }

    while (m--) {
        cin >> op >> x >> y;

        if (op == 1) {
            add(x, y);
        } else {  // op == 2
            cout << sum(y) - sum(x - 1) << endl;
        }
    }

    return 0;
}

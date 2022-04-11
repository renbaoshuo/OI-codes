#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

int n, m, l, r, d, x, a[N], c[N];
char op;

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
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    while (m--) {
        cin >> op;

        if (op == 'C') {
            cin >> l >> r >> d;

            add(l, d);
            add(r + 1, -d);
        } else {  // op == 'Q'
            cin >> x;
            cout << a[x] + sum(x) << endl;
        }
    }

    return 0;
}

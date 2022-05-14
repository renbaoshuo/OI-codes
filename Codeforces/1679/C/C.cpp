#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

int n, q, c1[N], c2[N], r[N], c[N];

inline int lowbit(int x) {
    return x & -x;
}

void add(int *c, int x, int y) {
    for (; x <= n; x += lowbit(x)) c[x] += y;
}

int sum(int *c, int x) {
    int ans = 0;
    for (; x; x -= lowbit(x)) ans += c[x];
    return ans;
}

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n >> q;

    while (q--) {
        int t;

        cin >> t;

        switch (t) {
            case 1: {
                int x, y;

                cin >> x >> y;

                if (!r[x]++) add(c1, x, 1);
                if (!c[y]++) add(c2, y, 1);

                break;
            }

            case 2: {
                int x, y;

                cin >> x >> y;

                if (!--r[x]) add(c1, x, -1);
                if (!--c[y]) add(c2, y, -1);

                break;
            }

            case 3: {
                int x1, y1, x2, y2;

                cin >> x1 >> y1 >> x2 >> y2;

                cout << ((sum(c1, x2) - sum(c1, x1 - 1) == x2 - x1 + 1) || (sum(c2, y2) - sum(c2, y1 - 1) == y2 - y1 + 1) ? "Yes" : "No") << endl;

                break;
            }
        }
    }

    return 0;
}

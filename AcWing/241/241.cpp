#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e5 + 5;

int n, y[N], l[N], r[N], c1[N], c2[N];
long long ans1, ans2;

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

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> y[i];
    }

    for (int i = 1; i <= n; i++) {
        l[i] = sum(c1, y[i] - 1);
        add(c1, y[i], 1);
    }

    for (int i = n; i; i--) {
        r[i] = sum(c2, y[i] - 1);
        add(c2, y[i], 1);
    }

    for (int i = 1; i <= n; i++) {
        ans1 += 1ll * (i - 1 - l[i]) * (n - i - r[i]);
        ans2 += 1ll * l[i] * r[i];
    }

    cout << ans1 << ' ' << ans2 << endl;

    return 0;
}

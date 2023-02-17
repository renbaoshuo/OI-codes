#include <iostream>
#include <numeric>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 3e5 + 5;

int n, a[N], c1[N], c2[N], ans[N];

int lowbit(int x) {
    return x & -x;
}

void add(int* c, int x, int y) {
    for (; x <= n; x += lowbit(x)) c[x] += y;
}

int sum(int* c, int x) {
    int res = 0;
    for (; x; x -= lowbit(x)) res += c[x];
    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        ans[i] = sum(c1, n) - sum(c1, a[i]);
        add(c1, a[i], 1);
    }

    for (int i = n; i; i--) {
        ans[i] = std::min(ans[i], sum(c2, n) - sum(c2, a[i]));
        add(c2, a[i], 1);
    }

    cout << std::accumulate(ans + 1, ans + 1 + n, 0ll) << endl;

    return 0;
}

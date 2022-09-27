#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 3005;

int n, p[N], c[N], ans;

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

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    for (int i = n; i; i--) {
        ans += sum(p[i] - 1);
        add(p[i], 1);
    }

    cout << (ans * 2 - ans % 2) << endl;

    return 0;
}

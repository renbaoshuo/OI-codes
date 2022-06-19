#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 5e4 + 5;

int n;
long long c1[N], c2[N], s, ans;
std::pair<int, int> p[N];

inline int lowbit(int x) {
    return x & -x;
}

void add(long long* c, int x, int y) {
    for (; x <= 5e4; x += lowbit(x)) c[x] += y;
}

long long sum(long long* c, int x) {
    long long res = 0;
    for (; x; x -= lowbit(x)) res += c[x];
    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> p[i].first >> p[i].second;
    }

    std::sort(p + 1, p + 1 + n);

    for (int i = 1; i <= n; i++) {
        int a = sum(c1, p[i].second),
            b = sum(c2, p[i].second);

        ans += ((a * p[i].second - b) + ((s - b) - (i - a - 1) * p[i].second)) * p[i].first;

        add(c1, p[i].second, 1);
        add(c2, p[i].second, p[i].second);
        s += p[i].second;
    }

    cout << ans << endl;

    return 0;
}

#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e5 + 5;

int n, q, p[N];
long long s[N];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    std::sort(p + 1, p + 1 + n, std::greater<int>());

    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + p[i];
    }

    while (q--) {
        int x, y;

        cin >> x >> y;

        cout << s[x] - s[x - y] << endl;
    }

    return 0;
}

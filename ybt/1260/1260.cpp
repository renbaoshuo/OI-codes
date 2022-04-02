#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 20005;

int n, a[N], f[N], ans1, ans2;

int main() {
    std::ios::sync_with_stdio(false);

    while (cin >> a[++n]) {}

    for (int i = 1; i < n; i++) {
        f[i] = 1;
        for (int j = 1; j < i; j++) {
            if (a[j] >= a[i]) f[i] = std::max(f[i], f[j] + 1);
        }
        ans1 = std::max(ans1, f[i]);
    }

    for (int i = 1; i < n; i++) {
        f[i] = 1;
        for (int j = 1; j < i; j++) {
            if (a[j] < a[i]) f[i] = std::max(f[i], f[j] + 1);
        }
        ans2 = std::max(ans2, f[i]);
    }

    cout << ans1 << endl
         << ans2 << endl;

    return 0;
}

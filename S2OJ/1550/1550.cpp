#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

int n, a[N], c[N], p, ans;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    bool flag = n >= 3;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];

        if (a[i] == n) p = i;
    }

    flag &= a[1] == n - 1 && a[n] == n;

    for (int i = 1; i < p; i++) {
        if (a[i] > a[i + 1]) {
            ans++;
            std::swap(a[i], a[i + 1]);
        }
    }

    cout << static_cast<long long>(n) * (n - 1) + ans - flag << endl;

    return 0;
}

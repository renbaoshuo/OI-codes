#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 20005;

int s, n, a[N], f[N];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = s; j >= a[i]; j--) {
            f[j] = std::max(f[j], f[j - a[i]] + a[i]);
        }
    }

    cout << s - f[s] << endl;

    return 0;
}

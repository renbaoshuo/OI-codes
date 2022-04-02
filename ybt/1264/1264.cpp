#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 105;

int n, a[N], f1[N], f2[N], ans;

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        f1[i] = 1;
        for (int j = 1; j < i; j++) {
            if (a[i] > a[j]) f1[i] = std::max(f1[i], f1[j] + 1);
        }
    }
    for (int i = n; i; i--) {
        f2[i] = 1;
        for (int j = n; j > i; j--) {
            if (a[i] > a[j]) f2[i] = std::max(f2[i], f2[j] + 1);
        }
    }

    for (int k = 1; k <= n; k++) {
        ans = std::max(ans, f1[k] + f2[k] - 1);
    }

    cout << n - ans << endl;

    return 0;
}

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

const int N = 1005;

int _t, n, phi[N], ans;

int main() {
    // Init
    for (int i = 2; i <= 1000; i++) {
        phi[i] = i;
    }
    for (int i = 2; i <= 1000; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= 1000; j += i) {
                phi[j] = phi[j] / i * (i - 1);
            }
        }
    }
    // End: Init

    cin >> _t;
    for (int t = 1; t <= _t; t++) {
        ans = 0;
        cin >> n;
        for (int i = 2; i <= n; i++) {
            ans += phi[i];
        }
        cout << t << ' ' << n << ' ' << ans * 2 + 3 << endl;
    }
    return 0;
}

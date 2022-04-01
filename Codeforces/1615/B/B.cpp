#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int t, l, r, b[200005][32];

int main() {
    for (int i = 1; i < 200005; i++) {
        for (int k = 0; k < 32; k++) {
            b[i][k] = b[i - 1][k] + ((i >> k) & 1);
        }
    }
    cin >> t;
    while (t--) {
        cin >> l >> r;
        int max = 0;
        for (int k = 0; k < 32; k++) {
            max = std::max(max, b[r][k] - b[l - 1][k]);
        }
        cout << r - l + 1 - max << endl;
    }
    return 0;
}

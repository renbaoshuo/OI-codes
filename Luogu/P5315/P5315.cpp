#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

int n, l, g;

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n >> l >> g;

    for (int i = 1, w, h; i <= n; i++) {
        cin >> w >> h;

        while (w > g || h > g) w >>= 1, h >>= 1;

        if (w < l || h < l) {
            cout << "Too Young" << endl;
        } else if (w == h) {
            cout << "Sometimes Naive" << endl;
        } else {
            cout << "Too Simple" << endl;
        }
    }

    return 0;
}

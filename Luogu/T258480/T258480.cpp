#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

int t;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;

    while (t--) {
        long long s;
        int m;

        cin >> s >> m;

        if (s % 2 || m == 1) {
            cout << -1 << endl;
        } else {
            cout << 2 << ' ' << (s >> 1) << ' ' << (s >> 1) << endl;
        }
    }

    return 0;
}

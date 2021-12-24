#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int t, n, x, s;

int main() {
    cin >> t;
    while (t--) {
        s = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> x;
            s += x;
        }
        cout << !!(s % n) << endl;
    }
    return 0;
}

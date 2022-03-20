#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

int t;
long long k, n, x;

int main() {
    std::ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        x = 0;
        cin >> k >> n;
        for (int i = 1; i <= k; i++) {
            x = x * 10 + 9;
        }
        cout << (n % x == 0 ? "aya" : "baka") << endl;
    }
    return 0;
}

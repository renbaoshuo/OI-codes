#include <iostream>
#include <bitset>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e4 + 5;

int m, n;
std::bitset<N> s[55];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m >> n;

    for (int i = 1, k; i <= m; i++) {
        cin >> k;

        for (int j = 1, x; j <= k; j++) {
            cin >> x;

            s[i].set(x);
        }

        for (int j = 1; j < i; j++) {
            if (!(s[i] & s[j]).count()) {
                cout << "impossible" << endl;

                exit(0);
            }
        }
    }

    cout << "possible" << endl;

    return 0;
}

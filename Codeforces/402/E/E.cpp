#include <iostream>
#include <bitset>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2005;

int n;
std::bitset<N> g[N];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1, x; j <= n; j++) {
            cin >> x;

            g[i][j] = x;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (g[j][i]) g[j] |= g[i];
        }
    }

    for (int i = 1; i <= n; i++) {
        if (g[i].count() != n) {
            cout << "NO" << endl;

            exit(0);
        }
    }

    cout << "YES" << endl;

    return 0;
}

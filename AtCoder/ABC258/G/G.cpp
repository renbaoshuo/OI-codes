#include <iostream>
#include <bitset>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 3005;

int n;
long long ans;
std::bitset<N> g[N];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char c;
            cin >> c;

            if (c == '1') g[i][j] = g[j][i] = 1;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (g[i][j]) {
                ans += (g[i] & g[j]).count();
            }
        }
    }

    cout << ans / 3 << endl;

    return 0;
}

#include <iostream>
#include <limits>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1.5e5 + 5,
          M = 3e6 + 5;

int n, f[M], e[M];
int l = std::numeric_limits<int>::max(),
    r = std::numeric_limits<int>::min();
std::pair<int, int> a[N];
bool vis[M];

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1, x, y; i <= n; i++) {
        cin >> x >> y;
        r = std::max(r, y);
        e[x] = y;
        vis[x] = true;
    }

    for (int i = r; i; i--) {
        if (vis[i]) {
            f[i] = std::max(f[i + 1], f[e[i] + 1] + (e[i] - i + 1));
        } else {
            f[i] = f[i + 1];
        }
    }

    cout << f[1] << endl;

    return 0;
}

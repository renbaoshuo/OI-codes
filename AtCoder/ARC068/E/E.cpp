#include <iostream>
#include <numeric>

using std::cin;
using std::cout;
const char endl = '\n';

const int M = 1e5 + 5;

int n, m, c[M], s[M];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1, x, y; i <= n; i++) {
        cin >> x >> y;

        c[x--]++, c[y + 1]--;

        for (int l = 1, r; l <= x; l = r + 1) {
            r = std::min(x / (x / l), y / (y / l));

            if (x / l < y / l) {
                c[l]++;
                c[r + 1]--;
            }
        }
    }

    std::partial_sum(c + 1, c + 1 + m, s + 1);

    for (int i = 1; i <= m; i++) {
        cout << s[i] << endl;
    }

    return 0;
}

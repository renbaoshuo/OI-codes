#include <iostream>
#include <numeric>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

int n, m, c[N];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    while (n--) {
        int l, r;

        cin >> l >> r;

        l--;

        for (int i = 1, j = 0; i <= r; i = j + 1) {
            if (l / i == 0) j = r;
            else j = std::min(l / (l / i), r / (r / i));

            if (r / i - l / i > 0) {
                c[i]++, c[j + 1]--;
            }
        }
    }

    std::partial_sum(c + 1, c + 1 + m, c + 1);

    for (int i = 1; i <= m; i++) {
        cout << c[i] << endl;
    }

    return 0;
}

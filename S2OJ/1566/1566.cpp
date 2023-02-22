#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e6 + 5;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;

    cin >> t;

    while (t--) {
        int n, k;

        cin >> n >> k;

        std::vector<int> a(1), b(1), c(n + 1), d(n + 2);

        std::copy_n(std::istream_iterator<int>(cin), n, std::back_inserter(a));
        std::copy_n(std::istream_iterator<int>(cin), n, std::back_inserter(b));

        for (int i = 1; i <= n; i++) {
            c[i] = b[i] - a[i];
        }

        for (int i = 1; i <= n; i++) {
            d[i] = c[i] - c[i - 1];
        }

        for (int i = 1; i + k - 1 <= n; i++) {
            d[i + k] += d[i];
            d[i] = 0;
        }

        cout << (std::count(d.begin() + 1, d.begin() + 1 + n, 0) == n ? "YES" : "N0") << endl;
    }

    return 0;
}

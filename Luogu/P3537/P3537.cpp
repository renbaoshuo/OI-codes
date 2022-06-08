#include <iostream>
#include <algorithm>
#include <limits>
#include <tuple>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1005,
          P = 1e6 + 5;

int n, p, f[P];
bool ans[P];
std::tuple<int, int, int> a[N];
std::tuple<int, int, int, int> b[P];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> std::get<2>(a[i]) >> std::get<0>(a[i]) >> std::get<1>(a[i]);
    }

    std::sort(a + 1, a + 1 + n, [&](auto a, auto b) {
        return std::get<0>(a) < std::get<0>(b);
    });

    cin >> p;

    for (int i = 1; i <= p; i++) {
        cin >> std::get<1>(b[i]) >> std::get<2>(b[i]) >> std::get<3>(b[i]);
        std::get<0>(b[i]) = i;
    }

    std::sort(b + 1, b + 1 + p, [&](auto a, auto b) {
        return std::get<1>(a) < std::get<1>(b);
    });

    f[0] = std::numeric_limits<int>::max();
    for (int i = 1, j = 1; i <= p; i++) {
        while (std::get<0>(a[j]) <= std::get<1>(b[i]) && j <= n) {
            for (int k = 100000; k >= std::get<2>(a[j]); k--) {
                f[k] = std::max(f[k],
                                std::min(f[k - std::get<2>(a[j])],
                                         std::get<1>(a[j])));
            }
            j++;
        }

        if (f[std::get<2>(b[i])] > std::get<1>(b[i]) + std::get<3>(b[i])) {
            ans[std::get<0>(b[i])] = true;
        }
    }

    for (int i = 1; i <= p; i++) {
        cout << (ans[i] ? "TAK" : "NIE") << endl;
    }

    return 0;
}

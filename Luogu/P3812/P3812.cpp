#include <iostream>
#include <algorithm>
#include <iterator>
#include <limits>
#include <type_traits>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

template <typename T>
struct LinearBasis
    : std::enable_if<std::is_unsigned<T>::value, T> {
    T a[std::numeric_limits<T>::digits];

    LinearBasis() {
        std::fill(std::begin(a), std::end(a), 0);
    }

    void insert(unsigned long long x) {
        for (int i = std::numeric_limits<T>::digits - 1; ~i; i--) {
            if ((x >> i) & 1) {
                if (a[i]) {
                    x ^= a[i];
                } else {
                    a[i] = x;

                    return;
                }
            }
        }
    }

    T query() {
        T res(0);

        for (int i = std::numeric_limits<T>::digits - 1; ~i; i--) {
            if ((res ^ a[i]) > res) res ^= a[i];
        }

        return res;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    LinearBasis<unsigned long long> lb;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        unsigned long long x;

        cin >> x;

        lb.insert(x);
    }

    cout << lb.query() << endl;

    return 0;
}

#include <iostream>
#include <algorithm>
#include <functional>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1005;

int n, ans;
std::pair<int, unsigned long long> a[N];
unsigned long long p[N];

inline bool insert(unsigned long long x) {
    for (int i = 0; i <= 61; i++) {
        if (x & (1ull << i)) {
            if (p[i]) {
                x ^= p[i];
            } else {
                p[i] = x;

                return true;
            }
        }
    }

    return false;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i].second >> a[i].first;
    }

    std::sort(a + 1, a + 1 + n, std::greater<std::pair<int, unsigned long long>>());

    for (int i = 1; i <= n; i++) {
        if (insert(a[i].second)) {
            ans += a[i].first;
        }
    }

    cout << ans << endl;

    return 0;
}

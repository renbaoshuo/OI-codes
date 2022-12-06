#include <iostream>
#include <limits>
#include <set>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

int n;
long long k, p, s[N],
    ans = std::numeric_limits<long long>::max();
std::set<long long> set{{0}};

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k >> p;

    for (int i = 1; i <= n; i++) {
        long long x;

        cin >> x;

        s[i] = (s[i - 1] + x) % p;
    }

    for (int i = 1; i <= n; i++) {
        if (s[i] < k) {
            ans = std::min(ans, s[i] + p - *--set.upper_bound(s[i] - k + p));
        } else {
            ans = std::min(ans, s[i] - *--set.upper_bound(s[i] - k));
        }

        set.emplace(s[i]);
    }

    cout << ans << endl;

    return 0;
}

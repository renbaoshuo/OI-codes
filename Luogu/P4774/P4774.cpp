#include <iostream>
#include <set>
#include <tuple>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

int t, n, m;
long long max;
std::tuple<long long, long long, int, int> dragon[N];
std::multiset<long long> set;

long long exgcd(long long a, long long b, long long& x, long long& y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }

    long long g = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return g;
}

long long excrt() {
    long long res = 0, lcm = 1;

    for (int i = 1; i <= n; i++) {
        long long a = (__int128)(std::get<3>(dragon[i])) * lcm % std::get<1>(dragon[i]),
                  b = std::get<1>(dragon[i]),
                  c = (__int128)(std::get<0>(dragon[i]) - std::get<3>(dragon[i]) * res % b + b) % b,
                  x, y;

        long long g = exgcd(a, b, x, y);
        x = (x % b + b) % b;

        if (c % g) return -1;

        res += (__int128)(c / g) * x % (b / g) * lcm % (lcm * (b / g));
        lcm *= b / g;
        res %= lcm;
    }

    if (res < max) res += ((max - res - 1) / lcm + 1) * lcm;

    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;

    while (t--) {
        max = 0;
        set.clear();

        cin >> n >> m;

        for (int i = 1; i <= n; i++) {
            cin >> std::get<0>(dragon[i]);
        }

        for (int i = 1; i <= n; i++) {
            cin >> std::get<1>(dragon[i]);
        }

        for (int i = 1; i <= n; i++) {
            cin >> std::get<2>(dragon[i]);
        }

        for (int i = 1, x; i <= m; i++) {
            cin >> x;

            set.insert(x);
        }

        for (int i = 1; i <= n; i++) {
            auto it = set.upper_bound(std::get<0>(dragon[i]));

            if (it != set.begin()) it--;

            std::get<3>(dragon[i]) = *it;
            set.insert(std::get<2>(dragon[i]));
            max = std::max(max, (std::get<0>(dragon[i]) - 1) / *it + 1);

            set.erase(it);
        }

        cout << excrt() << endl;
    }

    return 0;
}

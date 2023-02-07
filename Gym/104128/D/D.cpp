#include <iostream>
#include <algorithm>
#include <cmath>
#include <functional>
#include <iterator>
#include <numeric>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e5 + 5;

int n, k, m;
long long c, d;
std::vector<long long> a;

bool check(long long x) {
    std::vector<long long> s(n);

    for (int i = 0; i < n; i++) {
        if (a[i] >= x) {
            s[0]++;

            continue;
        }

        if (d == 0) {
            if (a[i] + c >= x) {
                s[std::max(0, i - m + 1)]++;
                if (i + 1 < n) s[i + 1]--;
            }

            continue;
        }

        int l = std::max(0, i - m + 1),
            r = std::max(l, std::min(i + 1, i - static_cast<int>(std::ceil(static_cast<double>(x - a[i] - c) / d)) + 1));

        s[l]++;
        if (r < n) s[r]--;
    }

    std::partial_sum(s.begin(), s.end(), s.begin());

    return std::count_if(s.begin(), s.end(), std::bind(std::greater_equal<>(), std::placeholders::_1, k)) > 0;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k >> m >> c >> d;

    std::copy_n(std::istream_iterator<decltype(a)::value_type>(cin), n, std::back_inserter(a));

    long long l = 0, r = 1e18, res = 0;

    while (l <= r) {
        long long mid = (l + r) >> 1;

        if (check(mid)) {
            l = mid + 1;
            res = mid;
        } else {
            r = mid - 1;
        }
    }

    cout << res << endl;

    return 0;
}

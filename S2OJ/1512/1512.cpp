#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b, c, d_up = 0, d_down = 0;
    long long ans = 0;

    cin >> n >> a >> b;

    std::vector<int> nums, x(n);

    for (int& x : x) {
        cin >> x;
    }

    std::set<int> s1;
    std::multiset<int> s2;

    for (int i = 0; i < n; i++) {
        s1.insert(x[i]);
        s2.insert(x[i]);

        if (i == 0) {
            c = x[i];
        } else {  // i > 0
            if (c > x[i]) {
                ans += static_cast<long long>(a) * (c - x[i]);
                d_down++;
            } else if (c < x[i]) {
                ans += static_cast<long long>(b) * (x[i] - c);
                d_up++;
            }

            if (c != *s1.begin()) {
                auto it = --s1.lower_bound(c);
                int d = (d_up + s2.count(c)) * b - d_down * a;

                if (d < 0 && c != *it) {
                    ans += static_cast<long long>(d) * (c - *it);
                    d_up += s2.count(c);
                    d_down -= s2.count(*it);
                    c = *it;
                }
            }

            if (c != *s1.rbegin()) {
                auto it = s1.upper_bound(c);
                int d = (d_down + s2.count(c)) * a - d_up * b;

                if (d < 0 && c != *it) {
                    ans += static_cast<long long>(d) * (*it - c);
                    d_up -= s2.count(*it);
                    d_down += s2.count(c);
                    c = *it;
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}

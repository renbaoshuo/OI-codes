#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <queue>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e5 + 5;

int t, n, a[N], s[N];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;

    while (t--) {
        std::queue<int> q;

        cin >> n;

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        std::partial_sum(a + 1, a + 1 + n, s + 1, std::bit_xor<>());

        auto process = [&](int l, int r) -> void {
            for (int i = r - 2; i >= l; i -= 2) q.emplace(i);
            for (int i = l; i < r; i += 2) q.emplace(i);
        };

        if (!s[n]) {
            if (n % 2) {
                process(1, n);
            } else {
                for (int i = 1; i <= n; i += 2) {
                    if (!s[i]) {
                        process(1, i);
                        process(i + 1, n);
                        break;
                    }
                }
            }
        }

        if (!q.empty()) {
            cout << "YES" << endl
                 << q.size() << endl;

            while (!q.empty()) {
                cout << q.front() << ' ';
                q.pop();
            }

            cout << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}

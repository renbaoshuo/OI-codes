#include <iostream>
#include <deque>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 105,
          W = 4e4 + 5;

int n, k, v[N], w[N], s[N], f[W];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> v[i] >> w[i] >> s[i];
    }

    for (int i = 1; i <= n; i++) {
        int x = std::min(s[i], k / w[i]);
        for (int j = 0; j < w[i]; j++) {
            std::deque<std::pair<int, int>> q;

            int t = (k - j) / w[i];
            for (int k = 0; k <= t; k++) {
                while (!q.empty() && q.back().second <= f[j + k * w[i]] - k * v[i]) q.pop_back();
                q.push_back(std::make_pair(k, f[j + k * w[i]] - k * v[i]));
                while (!q.empty() && q.front().first + x < k) q.pop_front();

                f[j + k * w[i]] = std::max(f[j + k * w[i]], q.front().second + k * v[i]);
            }
        }
    }

    cout << f[k] << endl;

    return 0;
}

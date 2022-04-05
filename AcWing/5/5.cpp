#include <iostream>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int M = 2005;

int n, m, f[M];
std::vector<std::pair<int, int>> a;

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 1, v, w, s; i <= n; i++) {
        cin >> v >> w >> s;

        for (int k = 1; k <= s; k <<= 1) {
            s -= k;
            a.push_back(std::make_pair(k * v, k * w));
        }
        if (s > 0) a.push_back(std::make_pair(s * v, s * w));
    }

    for (int i = 0; i < a.size(); i++) {
        for (int j = m; j >= a[i].first; j--) {
            f[j] = std::max(f[j], f[j - a[i].first] + a[i].second);
        }
    }

    cout << f[m] << endl;

    return 0;
}

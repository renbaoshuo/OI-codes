#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

int n, siz[N];
long long dis;
std::pair<long long, int> d[N];
std::vector<std::pair<int, int>> ans;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> d[i].first;

        d[i].second = i;
    }

    std::fill(siz + 1, siz + 1 + n, 1);
    std::sort(d + 1, d + 1 + n);

    for (int i = n; i > 1; i--) {
        long long t = d[i].first - n + (siz[i] << 1);
        int p = std::lower_bound(d + 1, d + 1 + n, std::make_pair(t, 0)) - d;

        if (d[p].first != t) {
            cout << -1 << endl;

            exit(0);
        }

        ans.emplace_back(d[i].second, d[p].second);
        siz[p] += siz[i];
        dis += siz[i];
    }

    if (dis != d[1].first) {
        cout << -1 << endl;
    } else {
        for (auto e : ans) {
            cout << e.first << ' ' << e.second << endl;
        }
    }

    return 0;
}

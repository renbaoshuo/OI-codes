#include <iostream>
#include <algorithm>
#include <set>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

int n, c, fa[N], cnt[N], ans, max;
std::pair<int, int> points[N];
std::set<std::pair<int, int>> set;

int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

inline void merge(int x, int y) {
    fa[find(x)] = find(y);
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> c;

    for (int i = 1, x, y; i <= n; i++) {
        cin >> x >> y;

        points[i] = std::make_pair(x + y, x - y);
        fa[i] = i;
    }

    std::sort(points + 1, points + 1 + n);

    set.insert(std::make_pair(points[1].second, 1));
    for (int i = 2, l = 1; i <= n; i++) {
        while (points[i].first - points[l].first > c) {
            set.erase(std::make_pair(points[l].second, l));
            l++;
        }

        auto it = set.lower_bound(std::make_pair(points[i].second, 0));

        if (it != set.end() && it->first - points[i].second <= c) merge(i, it->second);
        if (it != set.begin() && points[i].second - (--it)->first <= c) merge(i, it->second);

        set.insert(std::make_pair(points[i].second, i));
    }

    for (int i = 1; i <= n; i++) {
        if (find(i) == i) ans++;

        max = std::max(max, ++cnt[find(i)]);
    }

    cout << ans << ' ' << max << endl;

    return 0;
}

#pragma GCC optimize("Ofast")

#include <iostream>
#include <cmath>
#include <map>
#include <string>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

long long n, x;
std::map<long long, int> map;

inline int len(long long x) {
    if (x == 0) return 0;

    return (int)log10(x) + 1;
}

int dfs(long long x) {
    if (map.count(x)) return map[x];

    map[x] = 0x3f3f3f3f;

    std::vector<int> a;
    long long t = x;
    while (t) {
        a.push_back(t % 10);
        t /= 10;
    }

    if (a.size() == n) return map[x] = 0;

    for (int i : a) {
        map[x] = std::min(map[x], dfs(x * i) + 1);
    }

    return map[x];
}

signed main() {
    std::ios::sync_with_stdio(false);

    cin >> n >> x;

    int ans = dfs(x);

    cout << (ans == 0x3f3f3f3f ? -1 : ans) << endl;

    return 0;
}

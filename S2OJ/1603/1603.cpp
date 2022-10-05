#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

bool work() {
    int n;
    long long k;
    std::vector<std::pair<long long, long long>> up, down;

    cin >> n >> k;

    for (int i = 1, a, b; i <= n; i++) {
        cin >> a >> b;

        if (b - a >= 0) up.emplace_back(a, b);
        else down.emplace_back(a, b);
    }

    std::sort(up.begin(), up.end(), [&](const auto &a, const auto &b) {
        return a.first < b.first;
    });

    std::sort(down.begin(), down.end(), [&](const auto &a, const auto &b) {
        return a.second > b.second;
    });

    for (auto o : up) {
        k -= o.first;

        if (k <= 0) return false;

        k += o.second;
    }

    for (auto o : down) {
        k -= o.first;

        if (k <= 0) return false;

        k += o.second;
    }

    return true;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;

    cin >> t;

    while (t--) cout << (work() ? "YES" : "NO") << endl;

    return 0;
}

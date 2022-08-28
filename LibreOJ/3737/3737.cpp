#include <iostream>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int mod = 1e9 + 7;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long ans = 1;

    cin >> n;

    std::vector<std::pair<int, int>> data(n);

    for (auto &item : data) {
        cin >> item.first;
    }

    for (auto &item : data) {
        cin >> item.second;
    }

    for (auto &item : data) {
        if (item.first == 1) {
            ans = (ans + item.second) % mod;
            item.first = -1;
        }
    }

    long double max = ans;
    auto max_it = data.end();

    for (auto it = data.begin(); it != data.end(); it++) {
        if (it->first == -1) continue;

        long double t = static_cast<long double>(ans + it->second) / it->first;

        if (t > max) {
            max = t;
            max_it = it;
        }
    }

    if (max_it != data.end()) {
        ans += max_it->second;
        max_it->first = -1;
    }

    for (const auto &item : data) {
        if (~item.first) {
            ans = (ans * item.first) % mod;
        }
    }

    cout << ans << endl;

    return 0;
}

#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long k;
    std::vector<std::tuple<int, long long, long long>> up, down;
    std::vector<int> ans;

    cin >> n >> k;

    for (int i = 1, a, b; i <= n; i++) {
        cin >> a >> b;

        if (b - a >= 0) up.emplace_back(i, a, b);
        else down.emplace_back(i, a, b);
    }

    std::sort(up.begin(), up.end(), [&](const auto &a, const auto &b) {
        return std::get<1>(a) < std::get<1>(b);
    });

    std::sort(down.begin(), down.end(), [&](const auto &a, const auto &b) {
        return std::get<2>(a) > std::get<2>(b);
    });

    for (auto o : up) {
        k -= std::get<1>(o);

        if (k <= 0) {
            cout << "NIE" << endl;

            exit(0);
        }

        k += std::get<2>(o);
    }

    for (auto o : down) {
        k -= std::get<1>(o);

        if (k <= 0) {
            cout << "NIE" << endl;

            exit(0);
        }

        k += std::get<2>(o);
    }

    cout << "TAK" << endl;

    for (auto o : up) {
        cout << std::get<0>(o) << ' ';
    }

    for (auto o : down) {
        cout << std::get<0>(o) << ' ';
    }

    cout << endl;

    return 0;
}

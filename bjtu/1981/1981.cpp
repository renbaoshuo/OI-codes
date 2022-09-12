#include <iostream>
#include <algorithm>
#include <utility>

using std::cin;
using std::cout;
const char endl = '\n';

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    while (n--) {
        std::pair<int, int> p[2];

        for (int i = 0; i < 2; i++) {
            cin >> p[i].first >> p[i].second;
        }

        std::sort(p, p + 2);

        cout << (p[1].first < p[0].second ? "YES" : "NO") << endl;
    }

    return 0;
}

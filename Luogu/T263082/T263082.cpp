#include <iostream>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

int n, a[N], b[N];
std::vector<std::pair<int, int>> ans;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];

        b[i] = a[i] - a[i - 1];
    }

    b[n + 1] = -a[n];

    for (int i = 1, j = 1; i <= n + 1; i++) {
        while (b[i] < 0) {
            while (j < i && b[j] <= 0) j++;
            b[j]--, b[i]++;
            ans.emplace_back(j, i - 1);
        }
    }

    cout << ans.size() << endl;

    for (const auto &e : ans) {
        cout << e.first << ' ' << e.second << endl;
    }

    return 0;
}

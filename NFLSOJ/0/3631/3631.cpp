// #include <iostream>
#include <algorithm>
#include <fstream>
#include <utility>
#include <vector>

// using std::cin;
// using std::cout;
std::ifstream cin("swap.in");
std::ofstream cout("swap.out");
const char endl = '\n';

const int N = 1e5 + 5;

int n, a[N], p[N];
std::vector<std::pair<int, int>> ans;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];

        p[a[i]] = i;
    }

    for (int i = 1; i <= n; i++) {
        if (a[i] != i) {
            int x = i, y = p[i];
            ans.emplace_back(p[x], p[y]);
            std::swap(a[x], a[y]);
            p[a[x]] = x, p[a[y]] = y;
        }
    }

    cout << ans.size() << endl;

    for (auto e : ans) {
        cout << e.first << ' ' << e.second << endl;
    }

    return 0;
}

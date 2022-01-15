#include <iostream>
#include <unordered_map>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

int n, q, a, x, k;
std::unordered_map<int, std::vector<int>> map;

int main() {
    std::ios::sync_with_stdio(false);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        map[a].push_back(i);
    }
    while (q--) {
        cin >> x >> k;
        if (!map.count(x) || map[x].size() < k) {
            cout << -1 << endl;
        } else {
            cout << map[x][k - 1] << endl;
        }
    }
    return 0;
}

#include <iostream>
#include <unordered_map>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

int t, n, a[N];
std::unordered_map<int, std::vector<int>> map;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;

    while (t--) {
        map.clear();

        cin >> n;

        for (int i = 1; i <= n; i++) {
            cin >> a[i];

            map[a[i]].push_back(i);
        }

        bool flag = true;

        for (auto it : map) {
            if (it.second.size() < 2) {
                flag = false;
                break;
            }
        }

        if (flag) {
            for (int i = 1; i <= n; i++) {
                if (map[a[i]].size() > 1) {
                    cout << map[a[i]][1] << ' ';
                    map[a[i]].erase(map[a[i]].begin() + 1);
                } else {
                    cout << map[a[i]][0] << ' ';
                    map[a[i]].clear();
                }
            }
            cout << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}

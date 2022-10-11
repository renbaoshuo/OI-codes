#include <iostream>
#include <map>

using std::cin;
using std::cout;
const char endl = '\n';

int n, k;
std::map<int, int> map;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    for (int i = 1, x; i <= n; i++) {
        cin >> x;

        for (int j = 1; j * j <= x; j++) {
            if (x % j == 0) {
                map[j]++;

                if (j != x / j) map[x / j]++;
            }
        }
    }

    for (auto it = map.rbegin(); it != map.rend(); it++) {
        if (it->second >= k) {
            cout << it->first << endl;

            exit(0);
        }
    }

    return 0;
}

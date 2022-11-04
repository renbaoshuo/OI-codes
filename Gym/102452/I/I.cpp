#include <iostream>
#include <cmath>
#include <functional>
#include <set>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e5 + 5;

int n, m, lst, cnt;
long long a[N], b[N];
std::set<std::pair<long long, int>> q[N];
std::vector<std::pair<int, std::set<std::pair<long long, int>>::iterator>> ids[N];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    while (m--) {
        int op;

        cin >> op;

        if (op == 1) {
            int y, k;

            cin >> y >> k;

            a[++cnt] = y ^= lst;
            int v = std::ceil(static_cast<double>(y) / k);

            for (int i = 1, x; i <= k; i++) {
                cin >> x;

                x ^= lst;
                ids[cnt].emplace_back(x, q[x].emplace(b[x] + v, cnt).first);
                a[cnt] += b[x];
            }
        } else {  // op == 2
            int x, y;
            std::set<int> ans;

            cin >> x >> y;

            b[x ^= lst] += y ^= lst;

            while (!q[x].empty() && q[x].begin()->first <= b[x]) {
                int id = q[x].begin()->second;

                long long rest = a[id];
                for (auto o : ids[id]) {
                    rest -= b[o.first];
                    q[o.first].erase(o.second);
                }

                if (rest <= 0) {
                    ans.emplace(id);
                    ids[id].clear();
                } else {
                    int v = std::ceil(static_cast<double>(rest) / ids[id].size());

                    for (auto &o : ids[id]) {
                        o.second = q[o.first].emplace(b[o.first] + v, id).first;
                    }
                }
            }

            cout << (lst = ans.size());
            for (int x : ans) cout << ' ' << x;
            cout << endl;
        }
    }

    return 0;
}

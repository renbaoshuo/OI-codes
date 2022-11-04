#include <iostream>
#include <cmath>
#include <functional>
#include <queue>
#include <set>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e5 + 5;

int n, m, lst, cnt;
long long a[N], b[N];
std::priority_queue<
    std::pair<long long, int>,
    std::vector<std::pair<long long, int>>,
    std::greater<std::pair<long long, int>>>
    q[N];
std::vector<int> ids[N];

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

                ids[cnt].emplace_back(x ^= lst);
                a[cnt] += b[x];
                q[x].emplace(b[x] + v, cnt);
            }
        } else {  // op == 2
            int x, y;
            std::set<int> ans;

            cin >> x >> y;

            b[x ^= lst] += y ^= lst;

            while (!q[x].empty() && q[x].top().first <= b[x]) {
                int id = q[x].top().second;
                q[x].pop();

                if (!a[id]) continue;

                long long rest = a[id];
                for (int p : ids[id]) {
                    rest -= b[p];
                }

                if (rest <= 0) {
                    ans.emplace(id);
                    a[id] = 0;
                } else {
                    int v = std::ceil(static_cast<double>(rest) / ids[id].size());

                    for (int p : ids[id]) {
                        q[p].emplace(b[p] + v, id);
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

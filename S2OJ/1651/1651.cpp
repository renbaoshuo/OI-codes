#include <iostream>
#include <cmath>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e5 + 5;

int n, q, k, b, l[N], id[N], w[N], cnt[505][505], t[N], sum, res;
std::vector<int> pos[N], large;
bool st[N];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q >> k;

    b = std::ceil(std::sqrt(n));

    for (int i = 1; i <= n; i++) {
        cin >> l[i];

        pos[l[i]].emplace_back(i);

        if (l[i] == l[i - 1]) w[l[i]]++;
    }

    for (int i = 1; i <= n; i++) {
        if (pos[i].size() > b) {
            large.emplace_back(i);
            id[i] = large.size();
        }
    }

    for (int i = 0; i < large.size(); i++) {
        for (int x : pos[large[i]]) {
            if (id[l[x - 1]]) {
                cnt[i + 1][id[l[x - 1]]]++;
            }

            if (id[l[x + 1]]) {
                cnt[i + 1][id[l[x + 1]]]++;
            }
        }
    }

    while (q--) {
        int x;

        cin >> x;

        st[x] ^= 1;

        int o = st[x] ? 1 : -1;

        sum += o * pos[x].size();
        res += o * w[x];

        if (id[x]) {
            for (int i = 1; i <= large.size(); i++) {
                if (i == id[x]) continue;

                if (st[large[i - 1]]) {
                    res += o * cnt[id[x]][i];
                }
            }

            res += o * t[x];
        } else {
            for (int y : pos[x]) {
                if (st[l[y - 1]] && l[y - 1] != l[y]) res += o;
                if (st[l[y + 1]] && l[y + 1] != l[y]) res += o;

                if (id[l[y - 1]] && l[y - 1] != l[y]) t[l[y - 1]] += o;
                if (id[l[y + 1]] && l[y + 1] != l[y]) t[l[y + 1]] += o;
            }
        }

        cout << sum - res << endl;
    }

    return 0;
}

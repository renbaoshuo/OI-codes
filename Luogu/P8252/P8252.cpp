#include <iostream>
#include <algorithm>
#include <functional>
#include <iterator>
#include <unordered_set>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

struct node {
    int id;
    std::vector<int> v;

    node(const int &_id = 0, const int &_sz = 0)
        : id(_id), v(_sz) {}
};

void solve() {
    int n;

    cin >> n;

    std::vector<node> v;
    std::vector<int> t(n, -1);

    for (int i = 1, k; i <= n; i++) {
        cin >> k;

        v.emplace_back(node(i, k));

        for (int &x : v.back().v) cin >> x, x--;
    }

    std::sort(v.begin(), v.end(), [&](const node &a, const node &b) -> bool {
        return a.v.size() > b.v.size();
    });

    for (int i = 0; i < n; i++) {
        std::unordered_set<int> set;

        for (int x : v[i].v) {
            if (t[x] != -1) set.emplace(t[x]);
        }

        if (set.size() == 1) {
            int id = *set.begin();

            for (int x : v[i].v) {
                if (t[x] != id) {
                    cout << "YES" << endl
                         << v[i].id << ' ' << v[id].id << endl;

                    return;
                }
            }
        } else if (set.size() > 1) {
            int id = *set.begin();

            for (int x : set) {
                if (v[x].v.size() < v[id].v.size()) id = x;
            }

            cout << "YES" << endl
                 << v[i].id << ' ' << v[id].id << endl;

            return;
        }

        for (int x : v[i].v) {
            t[x] = i;
        }
    }

    cout << "NO" << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;

    cin >> t;

    while (t--) solve();

    return 0;
}

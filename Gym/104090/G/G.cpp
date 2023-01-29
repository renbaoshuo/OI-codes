#include <iostream>
#include <functional>
#include <stack>
#include <unordered_set>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

// 树哈希
// https://peehs-moorhsum.blog.uoj.ac/blog/7891

unsigned long long h(unsigned long long x) {
    return x * x * x * 1237123 + 19260817;
}

unsigned long long f(unsigned long long x) {
    return h(x & ((1ull << 31) - 1)) + h(x >> 31);
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;

    cin >> t;

    while (t--) {
        int n, m;

        cin >> n >> m;

        std::vector<std::vector<int>> g(n + 1);

        for (int i = 1, x, y; i <= m; i++) {
            cin >> x >> y;

            g[x].emplace_back(y);
            g[y].emplace_back(x);
        }

        if (m > n) {
            cout << "NO" << endl;

            continue;
        }

        if (m < n) {
            cout << "YES" << endl;

            continue;
        }

        // assert(n == m);

        std::stack<int> st;
        std::vector<int> circle;
        std::vector<bool> vis1(n + 1);

        std::function<void(int, int)> dfs1 = [&](int u, int f) -> void {
            if (vis1[u]) {
                if (circle.empty()) {
                    while (!st.empty() && st.top() != u) {
                        circle.emplace_back(st.top());
                        st.pop();
                    }

                    circle.emplace_back(u);
                }

                return;
            }

            vis1[u] = true;
            st.emplace(u);

            for (int v : g[u]) {
                if (v == f) continue;

                dfs1(v, u);
            }

            if (!st.empty()) st.pop();
        };

        dfs1(1, 0);

        std::vector<bool> vis2(n + 1);
        std::vector<unsigned long long> hash(n + 1);
        std::unordered_set<unsigned long long> set;

        for (int x : circle) vis2[x] = true;

        std::function<void(int)> dfs2 = [&](int u) -> void {
            vis2[u] = true;
            hash[u] = 1;

            for (int v : g[u]) {
                if (vis2[v]) continue;

                dfs2(v);

                hash[u] += f(hash[v]);
            }
        };

        for (int x : circle) {
            dfs2(x);
            set.emplace(hash[x]);
        }

        bool flag = circle.size() % 2 == 0;

        for (int i = 0; i + 2 < circle.size(); i++) {
            if (hash[circle[i]] != hash[circle[i + 2]]) {
                flag = false;

                break;
            }
        }

        cout << (set.size() == 1 || flag ? "YES" : "NO") << endl;
    }

    return 0;
}

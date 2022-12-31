#include <iostream>
#include <algorithm>
#include <cmath>
#include <functional>
#include <iterator>
#include <memory>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int mod = 1e9 + 7;

class AcAutomaton {
  private:
    struct node {
        int cnt;
        std::shared_ptr<node> child[26], fail;

        node()
            : cnt(0), fail(nullptr) {
            std::fill(std::begin(child), std::end(child), nullptr);
        }
    };

    std::shared_ptr<node> root;

  public:
    std::vector<std::shared_ptr<node>> nodes;
    std::unordered_map<std::shared_ptr<node>, int> nodes_id;

    AcAutomaton()
        : root(std::make_shared<node>()), nodes({root}), nodes_id({{root, 0}}) {}

    void insert(std::string s) {
        std::shared_ptr<node> cur = root;

        for (char c : s) {
            if (cur->child[c - 'a'] == nullptr) {
                cur->child[c - 'a'] = std::make_shared<node>();
                nodes_id[cur->child[c - 'a']] = nodes.size();
                nodes.emplace_back(cur->child[c - 'a']);
            }

            cur = cur->child[c - 'a'];
        }

        cur->cnt++;
    }

    void build() {
        std::queue<std::shared_ptr<node>> q;

        for (int i = 0; i < 26; i++) {
            if (root->child[i] != nullptr) {
                q.emplace(root->child[i]);
                root->child[i]->fail = root;
            } else {
                root->child[i] = root;
            }
        }

        while (!q.empty()) {
            auto cur = q.front();
            q.pop();

            for (int i = 0; i < 26; i++) {
                if (cur->child[i] != nullptr) {
                    cur->child[i]->fail = cur->fail->child[i] == nullptr ? root : cur->fail->child[i];

                    q.emplace(cur->child[i]);
                } else {
                    cur->child[i] = cur->fail->child[i] == nullptr ? root : cur->fail->child[i];
                }
            }
        }
    }

    int query(std::string t) {
        int res = 0;
        std::shared_ptr<node> cur = root;

        for (char c : t) {
            cur = cur->child[c - 'a'] == nullptr ? root : cur->child[c - 'a'];

            for (auto i = cur; i != nullptr && i->cnt != -1; i = i->fail) {
                res += i->cnt;
                i->cnt = -1;
            }
        }

        return res;
    }
};

constexpr int binpow(int a, int b, int mod = ::mod) {
    int res = 1;
    a %= mod;

    while (b) {
        if (b & 1) res = static_cast<long long>(res) * a % mod;
        a = static_cast<long long>(a) * a % mod;
        b >>= 1;
    }

    return res;
}

void gauss(std::vector<std::vector<int>> &a, int n) {
    int r, c;

    for (r = c = 0; c <= n; c++) {
        int t = r;

        for (int i = r; i <= n; i++) {
            if (std::abs(a[i][c]) > std::abs(a[t][c])) t = i;
        }

        if (!a[t][c]) continue;

        std::swap(a[t], a[r]);

        for (int i = n + 1; i >= c; i--) {
            a[r][i] = static_cast<long long>(a[r][i]) * binpow(a[r][c], mod - 2) % mod;
        }

        for (int i = r + 1; i <= n; i++) {
            if (a[i][c] != 0) {
                for (int j = n + 1; j >= c; j--) {
                    a[i][j] = ((a[i][j] - static_cast<long long>(a[i][c]) * a[r][j]) % mod + mod) % mod;
                }
            }
        }

        r++;
    }

    if (r <= n) throw std::logic_error("No Solution");

    for (int i = n; i >= 0; i--) {
        for (int j = i + 1; j <= n; j++) {
            a[i][n + 1] = ((a[i][n + 1] - static_cast<long long>(a[i][j]) * a[j][n + 1]) % mod + mod) % mod;
        }
    }
}

const int inv_26 = binpow(26, mod - 2);

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;

    cin >> t;

    while (t--) {
        int n;
        AcAutomaton ac;

        cin >> n;

        for (int i = 1; i <= n; i++) {
            std::string s;

            cin >> s;

            ac.insert(s);
        }

        ac.build();

        std::vector<std::vector<int>> a(ac.nodes.size(), std::vector<int>(ac.nodes.size() + 1));

        for (int i = 0; i < ac.nodes.size(); i++) {
            a[i][i] = 1;

            if (ac.nodes[i]->cnt) continue;

            a[i].back() = 1;

            for (auto ch : ac.nodes[i]->child) {
                a[i][ac.nodes_id[ch]] = ((a[i][ac.nodes_id[ch]] - inv_26) % mod + mod) % mod;
            }
        }

        gauss(a, ac.nodes.size() - 1);

        cout << static_cast<long long>(a[0].back()) * binpow(a[0][0], mod - 2) % mod << endl;
    }

    return 0;
}

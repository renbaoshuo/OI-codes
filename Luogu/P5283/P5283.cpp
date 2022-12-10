#include <iostream>
#include <functional>
#include <numeric>
#include <queue>
#include <tuple>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 5e5 + 5;

class Trie {
  private:
    const int len = 30;

    struct node {
        int cnt;
        node* child[2];

        node()
            : cnt(0), child{0, 0} {}

        ~node() {
            if (child[0]) delete child[0];
            if (child[1]) delete child[1];
        }
    };

    node* root;

  public:
    Trie()
        : root(new node()) {}

    ~Trie() {
        delete root;
    }

    void insert(unsigned long long val) {
        node* cur = root;

        cur->cnt++;

        for (int i = 32; ~i; i--) {
            bool x = (val >> i) & 1;

            if (cur->child[x] == nullptr) cur->child[x] = new node();

            cur = cur->child[x];
            cur->cnt++;
        }
    }

    unsigned long long query(unsigned long long val, int k) {
        node* cur = root;
        unsigned long long res = 0;

        for (int i = 32; ~i; i--) {
            bool x = (val >> i) & 1;

            if (cur->child[x] && cur->child[x]->cnt >= k) {
                cur = cur->child[x];
            } else {
                if (cur->child[x]) k -= cur->child[x]->cnt;
                cur = cur->child[x ^ 1];
                res |= 1ll << i;
            }
        }

        return res;
    }
};

int n, k;
unsigned long long s[N], ans;
std::priority_queue<
    std::tuple<int, int, unsigned long long>,
    std::vector<std::tuple<int, int, unsigned long long>>,
    auto(*)(std::tuple<int, int, unsigned long long>, std::tuple<int, int, unsigned long long>)->bool>
    q{[](std::tuple<int, int, unsigned long long> lhs, std::tuple<int, int, unsigned long long> rhs) -> bool {
        return std::get<2>(lhs) < std::get<2>(rhs);
    }};
Trie trie;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    k <<= 1;
    trie.insert(0);

    for (int i = 1; i <= n; i++) {
        unsigned long long x;

        cin >> x;

        s[i] = s[i - 1] ^ x;
        trie.insert(s[i]);
    }

    for (int i = 0; i <= n; i++) {
        q.emplace(i, n + 1, trie.query(s[i], n + 1));
    }

    while (k--) {
        auto t = q.top();
        q.pop();

        ans += std::get<2>(t);

        if (std::get<1>(t)) {
            q.emplace(
                std::get<0>(t),
                std::get<1>(t) - 1,
                trie.query(s[std::get<0>(t)], std::get<1>(t) - 1));
        }
    }

    cout << (ans >> 1) << endl;

    return 0;
}

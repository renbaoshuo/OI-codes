#include <iostream>
#include <fstream>
#include <string>

// using std::cin;
// using std::cout;
std::ifstream cin("prefix.in");
std::ofstream cout("prefix.out");
const char endl = '\n';

const int N = 2.1e6 + 5;
const int mod = 1e9 + 7;

int n, k, fac[N], inv[N], fac_inv[N];

class Trie {
  private:
    struct node {
        int cnt;
        bool is_end;
        node *next[26];

        node()
            : cnt(0), is_end(false) {
            std::fill_n(next, 26, nullptr);
        }

        ~node() {
            for (int i = 0; i < 26; i++) {
                if (next[i]) {
                    delete next[i];
                }
            }
        }
    };

    node *root;

  public:
    Trie()
        : root(new node()) {}

    ~Trie() {
        delete root;
    }

    void insert(const std::string &s) {
        node *cur = root;

        for (auto c : s) {
            if (cur->next[c - 'a'] == nullptr) {
                cur->next[c - 'a'] = new node();
            }

            cur = cur->next[c - 'a'];
            cur->cnt++;
        }

        cur->is_end = true;
    }

    int query(const std::string &s) {
        node *cur = root;

        for (auto c : s) {
            if (cur->next[c - 'a'] == nullptr) {
                return 0;
            }

            cur = cur->next[c - 'a'];
        }

        return cur->is_end ? cur->cnt : 0;
    }

    int rank(const std::string &s) {
        node *cur = root;
        int res = 0;

        for (auto c : s) {
            for (int i = 0; i < c - 'a'; i++) {
                if (cur->next[i] != nullptr) {
                    res += cur->next[i]->cnt;
                }
            }

            if (cur->next[c - 'a'] == nullptr) {
                return 0;
            }

            cur = cur->next[c - 'a'];
        }

        return res + 1;
    }

    void remove(const std::string &s) {
        node *cur = root;

        for (auto c : s) {
            cur = cur->next[c - 'a'];
            cur->cnt--;
        }
    }
} trie;

int A(int n, int m) {
    return static_cast<long long>(fac[n]) * fac_inv[n - m] % mod;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    fac[0] = 1;
    for (int i = 1; i < N; i++) {
        fac[i] = static_cast<long long>(fac[i - 1]) * i % mod;
    }

    inv[0] = inv[1] = 1;
    for (int i = 2; i < N; i++) {
        inv[i] = static_cast<long long>(mod - (mod / i)) * inv[mod % i] % mod;
    }

    fac_inv[0] = fac_inv[1] = 1;
    for (int i = 2; i < N; i++) {
        fac_inv[i] = static_cast<long long>(fac_inv[i - 1]) * inv[i] % mod;
    }

    for (int i = 0; i < n; i++) {
        std::string s;

        cin >> s;

        trie.insert(s);
    }

    int p = 1;
    long long ans = 0;
    std::string s, t;

    cin >> s;

    for (char c : s) {
        t.push_back(c);

        if (trie.query(t)) {
            ans = (ans + static_cast<long long>(trie.rank(t) - 1) * A(n - p, k - p)) % mod;
            trie.remove(t);
            t.clear();
            p++;
        }
    }

    cout << (ans + 1) % mod << endl;

    return 0;
}

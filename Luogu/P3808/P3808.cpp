#include <iostream>
#include <memory>
#include <queue>
#include <string>

using std::cin;
using std::cout;
const char endl = '\n';

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
    AcAutomaton()
        : root(new node()) {}

    void insert(std::string s) {
        std::shared_ptr<node> cur = root;

        for (char c : s) {
            if (cur->child[c - 'a'] == nullptr) {
                cur->child[c - 'a'] = std::make_shared<node>();
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

            for (std::shared_ptr<node> i = cur; i != nullptr && i->cnt != -1; i = i->fail) {
                res += i->cnt;
                i->cnt = -1;
            }
        }

        return res;
    }
};

int n;
std::string s, t;
AcAutomaton ac;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> s;

        ac.insert(s);
    }

    ac.build();

    cin >> t;

    cout << ac.query(t) << endl;

    return 0;
}

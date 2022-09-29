#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>

using std::cin;
using std::cout;
const char endl = '\n';

class AcAutomaton {
  private:
    struct node {
        int cnt;
        node *child[26], *fail;

        node()
            : cnt(0), fail(nullptr) {
            std::fill_n(child, 26, nullptr);
        }

        ~node() {
            for (int i = 0; i < 26; i++) {
                if (child[i] != nullptr) {
                    delete child[i];
                }
            }
        }
    };

    node* root;

  public:
    AcAutomaton()
        : root(new node()) {}

    ~AcAutomaton() {
        delete root;
    }

    void insert(std::string s) {
        node* cur = root;

        for (char c : s) {
            if (cur->child[c - 'a'] == nullptr) {
                cur->child[c - 'a'] = new node();
            }

            cur = cur->child[c - 'a'];
        }

        cur->cnt++;
    }

    void build() {
        std::queue<node*> q;

        for (int i = 0; i < 26; i++) {
            if (root->child[i] != nullptr) {
                q.push(root->child[i]);
                root->child[i]->fail = root;
            }
        }

        while (!q.empty()) {
            auto cur = q.front();
            q.pop();

            for (int i = 0; i < 26; i++) {
                if (cur->child[i] == nullptr) continue;

                auto p = cur->fail;

                while (p != nullptr) {
                    if (p->child[i] != nullptr) {
                        cur->child[i]->fail = p->child[i];

                        break;
                    }

                    p = p->fail;
                }

                if (p == nullptr) cur->child[i]->fail = root;

                q.push(cur->child[i]);
            }
        }
    }

    int query(std::string t) {
        int res = 0;
        node* cur = root;

        for (char c : t) {
            while (cur != root && cur->child[c - 'a'] == nullptr) cur = cur->fail;
            cur = cur->child[c - 'a'] == nullptr ? root : cur->child[c - 'a'];

            node* p = cur;

            while (p != root && p->cnt >= 0) {
                res += p->cnt;
                p->cnt = -1;
                p = p->fail;
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

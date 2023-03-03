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
        std::weak_ptr<node> child[26], fail;

        node()
            : cnt(0), fail() {}
    };

    std::shared_ptr<node> root;
    std::vector<std::shared_ptr<node>> nodes;

  public:
    AcAutomaton()
        : root(new node()), nodes() {}

    void insert(std::string s) {
        std::shared_ptr<node> cur = root;

        for (char c : s) {
            auto child_ptr = cur->child[c - 'a'].lock();

            if (child_ptr == nullptr) {
                child_ptr = std::make_shared<node>();
                nodes.emplace_back(child_ptr);  // Trick: store all nodes in a vector to avoid early expiration of weak_ptr
                cur->child[c - 'a'] = child_ptr;
            }

            cur = child_ptr;
        }

        cur->cnt++;
    }

    void build() {
        std::queue<std::shared_ptr<node>> q;

        for (int i = 0; i < 26; i++) {
            auto child_ptr = root->child[i].lock();

            if (child_ptr != nullptr) {
                q.emplace(child_ptr);
                child_ptr->fail = root;
            }
        }

        while (!q.empty()) {
            auto cur = q.front();
            q.pop();

            for (int i = 0; i < 26; i++) {
                auto fail_ptr = cur->fail.lock(),
                     child_ptr = cur->child[i].lock();

                if (child_ptr != nullptr) {
                    if (fail_ptr != nullptr) {
                        auto fail_child_ptr = fail_ptr->child[i].lock();

                        child_ptr->fail = fail_child_ptr == nullptr ? root : fail_child_ptr;
                    } else {
                        child_ptr->fail = root;
                    }

                    q.emplace(child_ptr);
                } else {
                    if (fail_ptr != nullptr) {
                        auto fail_child_ptr = fail_ptr->child[i].lock();

                        cur->child[i] = fail_child_ptr == nullptr ? root : fail_child_ptr;
                    } else {
                        cur->child[i] = root;
                    }
                }
            }
        }
    }

    int query(std::string t) {
        int res = 0;
        auto cur = root;

        for (char c : t) {
            auto child_ptr = cur->child[c - 'a'].lock();

            cur = child_ptr == nullptr ? root : child_ptr;

            for (auto i = cur;
                 i != nullptr && i->cnt != -1;
                 i = i->fail.lock()) {
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

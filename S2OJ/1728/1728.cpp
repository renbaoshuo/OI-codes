#include <iostream>
#include <string>
#include <unordered_set>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e6 + 5;

class Hash {
  private:
    unsigned long long hash[N], p[N];

  public:
    Hash(std::string s = "", int base = 131) {
        p[0] = 1;

        for (int i = 1; i <= s.size(); i++) {
            hash[i] = hash[i - 1] * base + s[i - 1];
            p[i] = p[i - 1] * base;
        }
    }

    unsigned long long get(int l, int r) {
        return hash[r] - hash[l - 1] * p[r - l + 1];
    }

    const unsigned long long &operator[](int i) const {
        return p[i];
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    std::string u;

    cin >> n >> u;

    if (n % 2 == 0) {
        cout << "NOT POSSIBLE" << endl;

        exit(0);
    }

    Hash hash(u, 131);
    int mid = n >> 1;
    unsigned long long lst = 0;
    std::string ans;

    for (int i = 1; i <= n; i++) {
        if (i - 1 <= mid) {
            if (hash.get(1, i - 1) * hash[mid - i + 1] + hash.get(i + 1, mid + 1) == hash.get(mid + 2, n)) {
                if (lst && lst != hash.get(mid + 2, n)) {
                    cout << "NOT UNIQUE" << endl;

                    exit(0);
                } else if (!lst) {
                    ans = u.substr(mid + 1, mid);
                    lst = hash.get(mid + 2, n);
                }
            }
        } else {
            if (hash.get(1, mid) == hash.get(mid + 1, i - 1) * hash[n - i] + hash.get(i + 1, n)) {
                if (lst && lst != hash.get(1, mid)) {
                    cout << "NOT UNIQUE" << endl;

                    exit(0);
                } else if (!lst) {
                    ans = u.substr(0, mid);
                    lst = hash.get(1, mid);
                }
            }
        }
    }

    cout << (ans.empty() ? "NOT POSSIBLE" : ans) << endl;

    return 0;
}

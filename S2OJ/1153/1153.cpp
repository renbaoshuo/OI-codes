#include <iostream>
#include <algorithm>
#include <queue>
#include <string>

using std::cin;
using std::cout;
const char endl = '\n';

const int mod = 998244353;

int n, m, f[505][2005][(1 << 6) + 5], ans;
int root, cnt;

struct node {
    int state, state2;
    int child[2], fail;

    node()
        : state(0), fail(0) {
        std::fill(std::begin(child), std::end(child), 0);
    }
} tr[1005];

bool check(std::string s, int x) {
    if (x + 1 < s.size() - x - 1) return false;

    int i = x, j = x + 1;

    while (0 <= i && j < s.size()) {
        if (s[i] == s[j]) return false;

        i--, j++;
    }

    return true;
}

void insert(std::string s, const int& id) {
    int cur = root;

    for (int i = 0; i < s.size(); i++) {
        if (!tr[cur].child[s[i] - '0']) {
            tr[cur].child[s[i] - '0'] = ++cnt;
        }

        cur = tr[cur].child[s[i] - '0'];

        if (check(s, i)) {
            tr[cur].state2 |= 1 << id;
        }
    }

    tr[cur].state |= 1 << id;
}

void build() {
    std::queue<int> q;

    for (int i = 0; i < 2; i++) {
        if (tr[root].child[i]) {
            q.emplace(tr[root].child[i]);
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < 2; i++) {
            if (tr[cur].child[i]) {
                tr[tr[cur].child[i]].fail = tr[tr[cur].fail].child[i];
                q.emplace(tr[cur].child[i]);
                tr[tr[cur].child[i]].state |= tr[tr[tr[cur].child[i]].fail].state;
                tr[tr[cur].child[i]].state2 |= tr[tr[tr[cur].child[i]].fail].state2;
            } else {
                tr[cur].child[i] = tr[tr[cur].fail].child[i];
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        std::string s;

        cin >> s;

        insert(s, i);
        std::reverse(s.begin(), s.end());
        std::transform(s.begin(), s.end(), s.begin(), [&](char c) -> char {
            return c == '0' ? '1' : '0';
        });
        insert(s, i);
    }

    build();

    f[0][0][0] = 1;

    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= cnt; j++) {
            for (int s = 0; s < 1 << n; s++) {
                if (!f[i - 1][j][s]) continue;

                for (int k = 0; k < 2; k++) {
                    int cur = tr[j].child[k],
                        ns = s | tr[cur].state;

                    f[i][cur][ns] = (f[i][cur][ns] + f[i - 1][j][s]) % mod;
                }
            }
        }
    }

    int ans = 0;

    for (int i = 0; i <= cnt; i++) {
        for (int s = 0; s < 1 << n; s++) {
            if ((s | tr[i].state2) == (1 << n) - 1) {
                ans = (ans + f[m][i][s]) % mod;
            }
        }
    }

    cout << ans << endl;

    return 0;
}

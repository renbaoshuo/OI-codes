#include <iostream>
#include <algorithm>
#include <cstring>
#include <iterator>
#include <limits>
#include <memory>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

int k, nxt[15][1005];
long long sum[15][1005], f[2][1005][(1 << 14) + 5],
    ans = std::numeric_limits<long long>::min();
std::string s;
std::vector<std::string> a{""};
int root, cnt;

struct node {
    int val;
    int child[26], fail;

    node()
        : val(0), fail(0) {
        std::fill(std::begin(child), std::end(child), 0);
    }
} tr[1005];

void insert(std::string s, const int& _val) {
    int cur = root;

    for (char c : s) {
        if (!tr[cur].child[c - 'a']) {
            tr[cur].child[c - 'a'] = ++cnt;
        }

        cur = tr[cur].child[c - 'a'];
    }

    tr[cur].val += _val;
}

void build() {
    std::queue<int> q;

    for (int i = 0; i < 26; i++) {
        if (tr[root].child[i]) {
            q.emplace(tr[root].child[i]);
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < 26; i++) {
            if (tr[cur].child[i]) {
                tr[tr[cur].child[i]].fail = tr[tr[cur].fail].child[i];
                q.emplace(tr[cur].child[i]);
                tr[tr[cur].child[i]].val += tr[tr[tr[cur].child[i]].fail].val;
            } else {
                tr[cur].child[i] = tr[tr[cur].fail].child[i];
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> k;

    for (int i = 1; i <= k; i++) {
        std::string t;
        int c;

        cin >> t >> c;

        insert(t, c);
    }

    cin >> s;

    build();

    for (char c : s) {
        if (c == '?') {
            a.emplace_back("");
        } else {
            a.back().push_back(c);
        }
    }

    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j <= cnt; j++) {
            int cur = j;

            for (char c : a[i]) {
                cur = tr[cur].child[c - 'a'];
                sum[i][j] += tr[cur].val;
            }

            nxt[i][j] = cur;
        }
    }

    memset(f, 0xc0, sizeof(f));

    f[0][0][0] = 0;

    for (int i = 0, x = 0; i < a.size(); i++, x ^= 1) {
        memset(f[x ^ 1], 0xc0, sizeof(f[x ^ 1]));

        for (int j = 0; j <= cnt; j++) {
            for (int s = 0; s < 1 << 14; s++) {
                if (f[x][j][s] < -0x3f3f3f3f3f3f3f3f) continue;

                int p = nxt[i][j];

                if (i + 1 < a.size()) {
                    for (int k = 0; k < 14; k++) {
                        if (s & (1 << k)) continue;

                        f[x ^ 1][tr[p].child[k]][s | (1 << k)] = std::max(
                            f[x ^ 1][tr[p].child[k]][s | (1 << k)],
                            f[x][j][s] + sum[i][j] + tr[tr[p].child[k]].val);
                    }
                } else {
                    f[x ^ 1][p][s] = std::max(f[x ^ 1][p][s], f[x][j][s] + sum[i][j]);
                }
            }
        }
    }

    for (int i = 0; i <= cnt; i++) {
        for (int s = 0; s < 1 << 14; s++) {
            ans = std::max(ans, f[a.size() & 1][i][s]);
        }
    }

    cout << ans << endl;

    return 0;
}

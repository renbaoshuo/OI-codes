#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e6 + 5;

int n, q, cnt, tr[N][26], siz[N][26];
long long f[26][26], res;

void insert(std::string s) {
    int cur = 0;

    for (int i = 0; i < s.size(); i++) {
        int x = s[i] - 'a';

        if (!tr[cur][x]) {
            tr[cur][x] = ++cnt;
        }

        for (int j = 0; j < 26; j++) {
            if (!tr[cur][j] || j == x) continue;

            f[x][j] += siz[cur][j];
        }

        siz[cur][x]++;
        cur = tr[cur][x];
    }

    for (int i = 0; i < 26; i++) {
        if (!tr[cur][i]) continue;

        res += siz[cur][i];
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        std::string s;

        cin >> s;

        insert(s);
    }

    while (q--) {
        long long ans = 0;
        std::string t;

        cin >> t;

        for (int i = 0; i < 26; i++) {
            for (int j = i + 1; j < 26; j++) {
                ans += f[t[i] - 'a'][t[j] - 'a'];
            }
        }

        cout << ans + res << endl;
    }

    return 0;
}

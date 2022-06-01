#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 10005,
          M = 6;

const int mod = 1e6;

int n, m, k, t, a[M], f[N][245], ans;
std::string ks;
std::vector<std::string> r;

void dfs(std::string s) {
    if (s.size() >= m) {
        if (s == ks) t = r.size();
        r.push_back(s);

        return;
    }

    if (s.back() == '1') dfs(s + '2'), dfs(s + '3');
    else if (s.back() == '2') dfs(s + '1'), dfs(s + '3');
    else dfs(s + '1'), dfs(s + '2');
}

bool check(std::string s) {
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i - 1]) return false;
    }

    return true;
}

bool check(std::string s1, std::string s2) {
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] == s2[i]) return false;
    }

    return true;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;

    for (int i = 1; i <= m; i++) {
        cin >> a[i];
        ks.push_back(a[i] + '0');
    }

    if (!check(ks)) {
        cout << 0 << endl;

        exit(0);
    }

    dfs("1");
    dfs("2");
    dfs("3");

    if (k == 1) {
        f[1][t] = 1;
    } else {
        for (int i = 0; i < r.size(); i++) {
            f[1][i] = 1;
        }
    }

    for (int i = 2; i <= n; i++) {
        if (i == k) {
            for (int j = 0; j < r.size(); j++) {
                if (check(r[t], r[j])) {
                    f[i][t] = (f[i][t] + f[i - 1][j]) % mod;
                }
            }
        } else {
            for (int j = 0; j < r.size(); j++) {
                if (i - 1 == k) {
                    if (check(r[t], r[j])) {
                        f[i][j] = (f[i][j] + f[i - 1][t]) % mod;
                    }
                } else {
                    for (int k = 0; k < r.size(); k++) {
                        if (check(r[j], r[k])) {
                            f[i][j] = (f[i][j] + f[i - 1][k]) % mod;
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < r.size(); i++) {
        ans = (ans + f[n][i]) % mod;
    }

    cout << ans << endl;

    return 0;
}

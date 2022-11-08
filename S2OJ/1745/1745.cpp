#include <iostream>
#include <algorithm>
#include <string>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 10005,
          K = 2005;
const int mod = 993244353;

const std::string s1 = "sakana";
const std::string s2 = "chinanago";

int n, k, _f[N][K], *f[N];
std::string s;

bool check(const std::string &pat, const std::string &str) {
    if (pat.size() != str.size()) return false;

    for (int i = 0; i < pat.size(); i++) {
        if (pat[i] != '?' && pat[i] != str[i]) return false;
    }

    return true;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> s;

    k = n / std::max(s1.size(), s2.size());
    s = ' ' + s;

    for (int i = 0; i <= n; i++) {
        f[i] = _f[i] + k + 1;
    }

    f[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = -k; j <= k; j++) {
            if (s[i] == '?') f[i][j] = (f[i][j] + static_cast<long long>(f[i - 1][j]) * 26 % mod) % mod;
            else f[i][j] = f[i - 1][j];
        }

        if (i >= s1.size() && check(s.substr(i - s1.size() + 1, s1.size()), s1)) {
            for (int j = -k; j <= k; j++) {
                f[i][j] = ((f[i][j] - f[i - s1.size()][j]) % mod + mod) % mod;
                f[i][j + 1] = (f[i][j + 1] + f[i - s1.size()][j]) % mod;
            }
        }

        if (i >= s2.size() && check(s.substr(i - s2.size() + 1, s2.size()), s2)) {
            for (int j = -k; j <= k; j++) {
                f[i][j] = ((f[i][j] - f[i - s2.size()][j]) % mod + mod) % mod;
                f[i][j - 1] = (f[i][j - 1] + f[i - s2.size()][j]) % mod;
            }
        }
    }

    cout << f[n][0] << endl;

    return 0;
}

#include <iostream>
#include <algorithm>
#include <string>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 5e5 + 5;
const int mod = 114514;

int n, sum[N][26], pre[26][26], suf[26][26], cnt[26];
long long ans;
std::string s;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s;

    n = s.size();
    s = ' ' + s;

    for (int i = 1; i <= n; i++) {
        std::copy_n(sum[i - 1], 26, sum[i]);
        sum[i][s[i] - 'a']++;
    }

    for (int i = n; i; i--) {
        cnt[s[i] - 'a']++;
        for (int j = 0; j < 26; j++) {
            if (s[i] - 'a' == j) continue;

            suf[s[i] - 'a'][j] = (suf[s[i] - 'a'][j] + cnt[j]) % mod;
        }
    }

    std::fill_n(cnt, 26, 0);
    for (int i = 1; i <= n; i++) {
        cnt[s[i] - 'a']++;

        for (int j = 0; j < 26; j++) {
            if (cnt[j] < 2 || s[i] - 'a' == j) continue;

            pre[s[i] - 'a'][j] = (pre[s[i] - 'a'][j] + (static_cast<long long>(cnt[j]) * (cnt[j] - 1) / 2) % mod) % mod;
        }

        for (int j = 0; j < 26; j++) {
            if (s[i] - 'a' == j) continue;

            suf[s[i] - 'a'][j] = (suf[s[i] - 'a'][j] - (sum[n][j] - sum[i - 1][j]) % mod + mod) % mod;
        }

        for (int j = 0; j < 26; j++) {
            for (int k = 0; k < 26; k++) {
                if (j == k || j == s[i] - 'a' || k == s[i] - 'a') continue;

                ans += static_cast<long long>(pre[k][j]) * suf[j][k];
            }
        }

        ans %= mod;
    }

    cout << ans << endl;

    return 0;
}

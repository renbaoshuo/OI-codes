#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 2e6 + 5;
const int mod = 1e9 + 7;

std::vector<int> manacher(const std::string &_s) {
    int n = _s.size();
    std::string s(n * 2 + 3, '#');

    for (int i = 0; i < n; i++) {
        s[i * 2 + 2] = _s[i];
    }

    s[0] = '^';
    s[n * 2 + 2] = '$';

    std::vector<int> p(s.size(), 1);

    for (int i = 1, mid = 0, r = 0; i <= n * 2 + 1; i++) {
        p[i] = i < r ? std::min(p[mid * 2 - i], r - i) : 1;

        while (s[i - p[i]] == s[i + p[i]]) p[i]++;

        if (i + p[i] - 1 > r) {
            r = i + p[i] - 1;
            mid = i;
        }
    }

    return p;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long sum = 0, ans = 0;
    std::string s;

    cin >> n >> s;

    auto p = manacher(s);
    std::vector<long long> pre(p.size()), suf(p.size());

    for (int i = 2; i < p.size() - 2; i++) {
        pre[i - p[i] + 1]++, pre[i + 1]--;
        suf[i]++, suf[i + p[i]]--;
        ans = (ans + p[i] / 2) % mod;
    }

    ans = ans * (ans - 1) / 2;
    std::partial_sum(pre.begin(), pre.end(), pre.begin());
    std::partial_sum(suf.begin(), suf.end(), suf.begin());

    for (int i = 2; i < p.size() - 2; i += 2) {
        ans = ((ans - sum * pre[i] % mod) % mod + mod) % mod;
        sum = (sum + suf[i]) % mod;
    }

    cout << ans << endl;

    return 0;
}

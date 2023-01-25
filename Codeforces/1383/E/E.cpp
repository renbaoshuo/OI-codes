#include <iostream>
#include <algorithm>
#include <string>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e6 + 5;
const int mod = 1e9 + 7;

int n, cnt = 1,
       pre[N], w[N], sum[N], f[N];
std::string s;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s;

    n = s.size();

    for (char c : s) {
        if (c == '0') pre[cnt]++;
        else cnt++;
    }

    if (cnt == 1) {
        cout << n << endl;

        exit(0);
    }

    std::fill(w, w + 1 + n, 1);

    sum[1] = f[1] = 1;

    for (int i = 2; i < cnt; i++) {
        int l = w[0];

        for (int j = 0; j <= pre[i]; j++) {
            l = w[j];
            f[i] = (static_cast<long long>(f[i]) + sum[i - 1] - sum[l - 1] + mod) % mod;
        }

        for (int j = 0; j <= pre[i]; j++) {
            w[j] = i;
        }

        sum[i] = (static_cast<long long>(sum[i - 1]) + f[i]) % mod;
    }

    cout << static_cast<long long>(pre[1] + 1) * (pre[cnt] + 1) % mod * sum[cnt - 1] % mod << endl;

    return 0;
}

#include <iostream>
#include <string>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e6 + 5;

int t, n;
int cnt, len[N];
int cnt_odd, cnt_even;
std::string s;
long long ans;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t >> n >> s;

    s = ' ' + s;

    len[0] = 1;
    for (int i = 1; i <= n; i++) {
        len[s[i] == '1' ? ++cnt : cnt]++;
    }

    for (int i = 1; i <= cnt; i++) {
        if (i % 2 == 1) {
            ans += static_cast<long long>(cnt_even) * len[i];
            cnt_even += len[i - 1];
        } else {
            ans += static_cast<long long>(cnt_odd) * len[i];
            cnt_odd += len[i - 1];
        }
    }

    for (int i = 1; i <= cnt; i++) {
        if (len[i - 1] > 1 && len[i] > 1) {
            ans += static_cast<long long>(len[i - 1] - 1) * (len[i] - 1);
        }
    }

    cout << ans << endl;

    return 0;
}

#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 3e5 + 5;

int n, m, k;
long long now, ans, a[N], b[N], c[N], sum[N];
bool tag[N];

int main() {
    std::ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
        tag[b[i]] = true;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] %= k;
        sum[i] = (sum[i - 1] + a[i]) % k;
    }

    for (int i = 1; i <= m; i++) {
        c[sum[b[i]]]++;
    }
    ans = c[0];
    for (int i = 1; i <= n; i++) {
        if (tag[i]) c[sum[i]]--;
        ans = std::max(ans, now + c[a[i]]);
        if (!sum[i] && tag[i]) now++;
        ans = std::max(ans, now);
    }

    cout << ans << endl;
    return 0;
}

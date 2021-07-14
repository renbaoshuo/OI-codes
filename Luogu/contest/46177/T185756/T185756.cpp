#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;

pair<char, int> a[100005];
int n, ans = -0x3f3f3f3f, sum;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a, a + n);
    do {
        sum = 0;
        for (int i = 0; i < n; i++) {
            sum = a[i].first == '+' ? sum + a[i].second : sum * a[i].second;
        }
        sum %= mod;
        ans = max(sum, ans);
    } while (next_permutation(a, a + n));
    cout << ans % mod << endl;
    return 0;
}

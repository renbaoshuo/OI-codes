#include <bits/stdc++.h>

using namespace std;

int n, k;
long long a, cnt, sum[1000005];

int main() {
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        cin >> a;
        sum[i] = sum[i - 1] + a;
    }
    cnt = sum[k];
    for (int i = 2; i <= n - k; i++) {
        cnt = max(cnt, sum[i + k - 1] - sum[i - 1]);
    }
    cout << sum[n - 1] - cnt << endl;
    return 0;
}

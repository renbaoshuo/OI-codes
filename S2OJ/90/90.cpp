#include <bits/stdc++.h>

using namespace std;

int n, m, a[205], sum[205];
map<int, int> b;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }
    sum[0] = n;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j * j <= a[i] && j <= n; j++) {
            if (a[i] % j == 0) {
                sum[b[j]]--;
                sum[++b[j]]++;
                if (j * j != a[i] && a[i] / j <= n) {
                    sum[b[a[i] / j]]--;
                    sum[++b[a[i] / j]]++;
                }
            }
        }
    }
    for (int i = 0; i <= m; i++) {
        cout << sum[i] << endl;
    }
    return 0;
}

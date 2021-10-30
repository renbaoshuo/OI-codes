#include <bits/stdc++.h>

using namespace std;

int n, a[1005], f[1000005];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for (int i = n; i > 0; i--) {
        bool flag = false;
        for (int j = -1000; j <= 1000; j++) {
            flag = flag || a[i] == 1ll * j * j;
        }
        if (!flag) {
            cout << a[i] << endl;
            exit(0);
        }
    }
    return 0;
}

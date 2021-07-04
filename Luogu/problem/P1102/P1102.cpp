#include <bits/stdc++.h>

using namespace std;

int main() {
    long long     n, c, ans = 0;
    int           a[200005];
    map<int, int> b;
    cin >> n >> c;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[a[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        ans += b[a[i] + c];
    }
    cout << ans << endl;
    return 0;
}

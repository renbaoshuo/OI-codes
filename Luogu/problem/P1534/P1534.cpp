// R38865539

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, sum = 0, ans = 0, t1, t2;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t1 >> t2;
        sum += t1 + t2 - 8;
        ans += sum;
    }
    cout << ans << endl;
    return 0;
}

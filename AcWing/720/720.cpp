#include <bits/stdc++.h>

using namespace std;

int a, n, ans;

int main() {
    cin >> a;

    while (cin >> n, n <= 0) {}

    for (int i = 0; i < n; i++) {
        ans += i + a;
    }

    cout << ans << endl;

    return 0;
}

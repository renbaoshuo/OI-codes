#include <bits/stdc++.h>

using namespace std;

int n, ans[15], t;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        t = i;
        while (t) {
            ans[t % 10]++;
            t /= 10;
        }
    }
    for (int i = 0; i < 10; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}

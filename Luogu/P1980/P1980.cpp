#include <bits/stdc++.h>

using namespace std;

int n, x, ans;

int cntx(int num) {
    int res = 0;
    while (num) {
        res += num % 10 == x;
        num /= 10;
    }
    return res;
}

int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        ans += cntx(i);
    }
    cout << ans << endl;
    return 0;
}

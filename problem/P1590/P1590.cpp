// 70' Code (R38866815)

#include <bits/stdc++.h>

using namespace std;

bool find(int s, int x) {
    while (s) {
        if (s % 10 == x) {
            return true;
        }
        s /= 10;
    }
    return false;
}

int main() {
    int t, n, ans;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        ans = 0;
        for (int i = 1; i <= n; i++) {
            if (!find(i, 7)) {
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int t, n, m;
bool flag;

int main() {
    cin >> t;
    while (t--) {
        flag = true;
        cin >> n >> m;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0 && (i + 1 + n / i + 1) * 2 <= m) {
                cout << "Good" << endl;
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << "Miss" << endl;
        }
    }
    return 0;
}

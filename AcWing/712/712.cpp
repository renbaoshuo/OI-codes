#include <bits/stdc++.h>

using namespace std;

int main() {
    double x;
    int ans = 0;
    for (int i = 1; i <= 6; i++) {
        cin >> x;
        if (x > 0) ans++;
    }
    cout << ans << " positive numbers" << endl;
    return 0;
}

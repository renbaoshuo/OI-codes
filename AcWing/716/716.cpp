#include <bits/stdc++.h>

using namespace std;

int t, ans1, ans2;

int main() {
    for (int i = 1; i <= 100; i++) {
        cin >> t;

        if (t > ans1) {
            ans1 = t;
            ans2 = i;
        }
    }

    cout << ans1 << endl
         << ans2 << endl;

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main() {
    unsigned long long x, ans = 0;
    for (int i = 0; i < 3000000; i++) {
        cin >> x;
        ans ^= x;
    }
    cout << ans << endl;
    return 0;
}
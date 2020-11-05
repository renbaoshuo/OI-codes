#include <bits/stdc++.h>

using namespace std;

int main() {
    char c;
    int ans = 0;
    while (cin >> c) {
        if ('0' <= c && c <= '9') {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}

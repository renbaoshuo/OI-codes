#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, f[105], ans = 0;
    string s[105];
    char now = 'A';
    memset(f, 0x00, sizeof(f));
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    sort(s, s + n);
    for (int i = 0; i < n; i++) {
        if (s[i][0] == now) {
            ans++;
            now++;
        }
    }
    cout << ans << endl;
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

string s;
int    st, cnt = 0, a[1000005], ans[1000005];

int main() {
    cin >> s >> st;
    for (int i = 0; i < s.size(); i++) {
        a[i] = s[i] - 'A' + st;
    }
    for (int i = s.size() - 1; i >= 0; i--) {
        while (a[i] > 0) {
            ans[++cnt] = a[i] % 10;
            a[i] /= 10;
        }
    }
    for (int i = cnt - 1; i >= 3; i--) {
        for (int j = 1; j <= i; j++) {
            ans[j] = (ans[j] + ans[j + 1]) % 10;
        }
    }
    if (ans[3] == 1 && ans[2] == 0 && ans[1] == 0) {
        cout << 100 << endl;
    }
    else if ((ans[2] + ans[3]) % 10) {
        cout << (ans[2] + ans[3]) % 10 << (ans[1] + ans[2]) % 10 << endl;
    }
    else {
        cout << (ans[1] + ans[2]) % 10 << endl;
    }
    return 0;
}

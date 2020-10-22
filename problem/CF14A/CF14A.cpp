#include <bits/stdc++.h>

using namespace std;

int main() {
    int    n, m;
    int    minx = 0x3f3f3f, miny = 0x3f3f3f;
    int    maxx = 0x000000, maxy = 0x000000;
    string s[55];
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        if (find(s[i].begin(), s[i].end(), '*') != s[i].end()) {
            minx = min(minx, i);
            miny = min(miny, (int)(s[i].find_first_of('*') == string::npos ? miny : s[i].find_first_of('*')));
            maxy = max(maxy, (int)(s[i].find_last_of('*') == string::npos ? maxy : s[i].find_last_of('*')));
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (s[i].find('*') != string::npos) {
            maxx = i;
            break;
        }
    }
    for (int i = minx; i <= maxx; i++) {
        for (int j = miny; j <= maxy; j++) {
            cout << s[i][j];
        }
        cout << endl;
    }
    return 0;
}

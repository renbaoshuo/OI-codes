#include <bits/stdc++.h>

using namespace std;

int m, n, nxt[100005];
string p, s;

int main() {
    cin >> n >> p >> m >> s;
    nxt[0] = -1;
    for (int i = 1, j = -1; i < n; i++) {
        while (j >= 0 && p[j + 1] != p[i]) j = nxt[j];
        if (p[j + 1] == p[i]) j++;
        nxt[i] = j;
    }
    for (int i = 0, j = -1; i < m; i++) {
        while (j != -1 && s[i] != p[j + 1]) j = nxt[j];
        if (s[i] == p[j + 1]) j++;
        if (j == n - 1) {
            cout << i - j << ' ';
            j = nxt[j];
        }
    }
    cout << endl;
    return 0;
}

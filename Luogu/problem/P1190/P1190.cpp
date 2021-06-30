#include <bits/stdc++.h>

using namespace std;

int n, m, w[10005], p, t, s;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    p = m;
    while (p <= n) {
        for (int i = 0; i < m; i++) {
            w[i]--;
            if (!w[i]) {
                w[i] = w[p++];
            }
        }
        t++;
    }
    for (int i = 0; i < m; i++) {
        s = max(s, w[i]);
    }
    cout << t + s << endl;
    return 0;
}

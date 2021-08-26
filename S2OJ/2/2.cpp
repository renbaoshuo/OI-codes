#include <bits/stdc++.h>

using namespace std;

int n, nxt[300005], pre[300005], a[300005], cnt;
vector<int> b[300005];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == -1) ++cnt;
    }
    for (int i = 1; i < cnt; i++) {
        nxt[i] = i + 1;
    }
    nxt[cnt] = 1;
    for (int i = 2; i <= cnt; i++) {
        pre[i] = i - 1;
    }
    pre[1] = cnt;
    int now = 1;
    for (int i = 1; i <= n; i++) {
        if (a[i] == -1) {
            nxt[pre[now]] = nxt[now];
            pre[nxt[now]] = pre[now];
        } else {
            b[now].push_back(a[i]);
        }
        now = nxt[now];
    }
    cout << cnt << endl;
    for (int i = 1; i <= cnt; i++) {
        cout << b[i].size() << ' ';
        for (int j = 0; j < b[i].size(); ++j) {
            cout << b[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}

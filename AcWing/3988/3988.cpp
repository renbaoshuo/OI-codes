#include <bits/stdc++.h>

using namespace std;

int n, k, i, a[105];
map<int, int> b;

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[a[i]] = i;
    }
    if (b.size() < k) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        for (auto it : b) {
            cout << it.second << ' ';
            if (++i >= k) break;
        }
        cout << endl;
    }
    return 0;
}

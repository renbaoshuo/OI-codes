#include <bits/stdc++.h>

using namespace std;

int t, n, m, k, c, l;
vector<int> ans;

int main() {
    cin >> t;
    while (t--) {
        c = 1;
        cin >> n >> m >> k;
        if (n * m % k != 0) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            for (int i = 1; i <= n; i++) {
                ans.clear();
                if (i & 1) {
                    for (int j = 1; j <= m; j++) {
                        if (!--c) {
                            l++;
                            c = k;
                        }
                        ans.push_back(l);
                    }
                } else {
                    for (int j = m; j >= 1; j--) {
                        if (!--c) {
                            l++;
                            c = k;
                        }
                        ans.insert(ans.begin(), l);
                    }
                }
                for (auto i : ans) {
                    cout << i << ' ';
                }
                cout << endl;
            }
        }
    }
    return 0;
}

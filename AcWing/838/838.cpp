#include <bits/stdc++.h>

using namespace std;

int n, m, t;
map<int, int> a;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> t;
        a[t]++;
    }
    for (auto it = a.begin(); it != a.end(); it++) {
        for (int i = 0; i < it->second && m; i++, m--) {
            cout << it->first << ' ';
        }
    }
    cout << endl;
    return 0;
}

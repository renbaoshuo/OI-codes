#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, l;
    string s;
    unordered_map<string, set<int> > m;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> l;
        for (int j = 0; j < l; j++) {
            cin >> s;
            m[s].insert(i);
        }
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (!m.count(s)) {
            cout << endl;
        } else {
            for (set<int>::iterator it = m[s].begin(); it != --m[s].end(); it++) {
                cout << *it << ' ';
            }
            cout << *--m[s].end() << endl;
        }
    }
    return 0;
}

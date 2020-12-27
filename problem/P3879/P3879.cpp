#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, l;
    string s;
    map<string, vector<int>> m;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> l;
        for (int j = 0; j < l; j++) {
            cin >> s;
            m[s].push_back(i);
        }
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (!m.count(s)) {
            cout << endl;
        }
        else {
            for (int j = 0; j < m[s].size() - 1; j++) {
                if(m[s][j] != m[s][j+1]) {
                    cout << m[s][j] << ' ';
                }
            }
            cout << *--m[s].end() << endl;
        }
    }
    return 0;
}

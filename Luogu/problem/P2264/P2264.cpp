#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, ans = 0;
    string s;
    map<string, bool> m, m2;
    set<string> s2;
    bool flag = false;
    stringstream ss;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        m[s] = true;
    }
    getchar();
    getline(cin, s);
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    int pos = 0;
    while (s.find('.', pos) != string::npos) {
        s.insert(s.find('.', pos) + 1, " ");
        pos = s.find('.', pos) + 1;
    }
    while (s.find(',') != string::npos) {
        s.replace(s.find(','), 1, " ");
    }
    ss.str(s);
    while (ss >> s) {
        if (s.find('.') != string::npos) {
            s.erase(s.find('.'));
            flag = true;
        }
        if (s.find(',') != string::npos) {
            s.erase(s.find(','));
        }
        for (int i = 0; i < n; i++) {
            if (m[s] && !m2[s]) {
                s2.insert(s);
                m2[s] = true;
                break;
            }
        }
        if (flag) {
            flag = false;
            ans += s2.size();
            s2.clear();
            m2.clear();
        }
        s.clear();
    }
    cout << ans << endl;
    return 0;
}

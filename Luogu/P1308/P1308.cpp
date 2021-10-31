#include <bits/stdc++.h>

using namespace std;

int cnt, now;
string w, s;

int main() {
    getline(cin, w);
    getline(cin, s);
    w = ' ' + w + ' ';
    s = ' ' + s + ' ';
    transform(w.begin(), w.end(), w.begin(), ::tolower);
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    if (s.find(w) == string::npos) {
        cout << -1 << endl;
    } else {
        while ((now = s.find(w, now)) != string::npos) cnt++, now++;
        cout << cnt << ' ' << s.find(w) << endl;
    }
    return 0;
}

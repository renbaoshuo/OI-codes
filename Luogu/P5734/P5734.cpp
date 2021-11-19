// https://www.luogu.com.cn/record/35887921

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n = 0;
    cin >> n;
    string s = "";
    cin >> s;
    for (int i = 0; i < n; i++) {
        int act;
        cin >> act;
        if (act == 1) {
            string s1;
            cin >> s1;
            s += s1;
            cout << s;
        } else if (act == 2) {
            int st, ed;
            cin >> st >> ed;
            s = s.substr(st, ed);
            cout << s;
        } else if (act == 3) {
            int st;
            string s1;
            cin >> st >> s1;
            s.insert(st, s1);
            cout << s;
        } else if (act == 4) {
            string s1;
            cin >> s1;
            if (s.find(s1) < s.size()) {
                cout << s.find(s1);
            } else {
                cout << "-1";
            }
        }
        cout << endl;
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main() {
    int         n;
    set<string> disk;
    string      s, dir;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        dir = "";
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == '/') {
                disk.insert(dir);
            }
            dir += s[j];
        }
        disk.insert(dir);
        cout << disk.size() - 1 << endl;
    }
    return 0;
}

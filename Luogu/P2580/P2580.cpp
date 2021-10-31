#include <bits/stdc++.h>

using namespace std;

int n, m;
map<string, int> m1, m2;
string s;

int main() {
    cin >> n;
    while (n--) {
        cin >> s;
        m1[s]++;
    }
    cin >> m;
    while (m--) {
        cin >> s;
        m2[s]++;
        if (m2[s] > 1) {
            cout << "REPEAT" << endl;
        } else if (m1[s]) {
            cout << "OK" << endl;
        } else {
            cout << "WRONG" << endl;
        }
    }
    return 0;
}

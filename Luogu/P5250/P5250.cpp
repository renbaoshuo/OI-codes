#include <bits/stdc++.h>

using namespace std;

int main() {
    map<int, int> m;
    int i, j, n, x, y;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> x >> y;
        if (x == 1) {
            if (m.count(y)) {
                cout << "Already Exist" << endl;
            } else {
                m[y] = 1;
            }
        } else {
            if (m.empty()) {
                cout << "Empty" << endl;
            } else if (m.count(y)) {
                m.erase(y);
                cout << y << endl;
            } else {
                m[y] = 1;
                map<int, int>::iterator it = m.find(y);
                map<int, int>::iterator it2 = it;
                it++;
                if (it2 == m.begin()) {
                    cout << it->first << endl;
                    m.erase(it);
                } else if (it == m.end()) {
                    cout << (--it2)->first << endl;
                    m.erase(it2);
                } else if (y - (--it2)->first > it->first - y) {
                    cout << it->first << endl;
                    m.erase(it);
                } else {
                    cout << it2->first << endl;
                    m.erase(it2);
                }
                m.erase(y);
            }
        }
    }
    return 0;
}
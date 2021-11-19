#include <bits/stdc++.h>

using namespace std;

int main() {
    set<int> s;
    map<int, int> m;
    int n, t;
    cin >> n;
    while (n--) {
        cin >> t;
        s.insert(t);
        m[t]++;
    }
    for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
        cout << *it << ' ' << m[*it] << endl;
    }
    return 0;
}

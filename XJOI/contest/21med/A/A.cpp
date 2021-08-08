#include <bits/stdc++.h>

using namespace std;

int n, p;
string s;
stack<pair<char, int>> st;

int main() {
    cin >> n >> p >> s;
    s = ' ' + s;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == '{') {
            st.push(make_pair(s[i], i));
        } else if (st.top().second == p) {
            cout << i << endl;
            exit(0);
        } else if (i == p) {
            cout << st.top().second << endl;
            exit(0);
        } else {
            st.pop();
        }
    }
    return 0;
}

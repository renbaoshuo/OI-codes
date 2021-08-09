#include <bits/stdc++.h>

using namespace std;

int n, p;
string s;
stack<int> st;

int main() {
    cin >> n >> p >> s;
    s = ' ' + s;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == '{') {
            st.push(i);
        } else if (st.top() == p) {
            cout << i << endl;
            exit(0);
        } else if (i == p) {
            cout << st.top() << endl;
            exit(0);
        } else {
            st.pop();
        }
    }
    return 0;
}

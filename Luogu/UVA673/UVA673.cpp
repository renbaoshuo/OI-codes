#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    getchar();
    while (t--) {
        string s;
        stack<char> st;
        getline(cin, s);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[') {
                st.push(s[i]);
            } else if (st.empty() || s[i] == ')' && st.top() != '(' || s[i] == ']' && st.top() != '[') {
                cout << "No" << endl;
                goto end;
            } else {
                st.pop();
            }
        }
        if (st.empty()) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    end:;
    }
    return 0;
}

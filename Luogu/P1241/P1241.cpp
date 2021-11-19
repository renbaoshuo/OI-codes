#include <bits/stdc++.h>

using namespace std;

char b[105];
int n;
string s;
stack<int> st;

int main() {
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            st.push(i);
            b[i] = ')';
        }
        if (s[i] == '[') {
            st.push(i);
            b[i] = ']';
        }
        if (s[i] == ')' || s[i] == ']') {
            if (st.empty() || b[st.top()] != s[i]) {
                if (s[i] == ')') {
                    b[i] = '(';
                } else {
                    b[i] = '[';
                }
            } else {
                b[st.top()] = ' ';
                st.pop();
            }
        }
    }
    for (int i = 0; i < s.size(); i++) {
        if (b[i] == '(' || b[i] == '[') {
            cout << b[i];
        }
        cout << s[i];
        if (b[i] == ')' || b[i] == ']') {
            cout << b[i];
        }
    }
    cout << endl;
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main() {
    stack<int> st;
    char ch;
    int a, b, t = 0;
    while (cin >> ch, ch != '@') {
        if (ch == '.') {
            st.push(t);
            t = 0;
        } else if ('0' <= ch && ch <= '9') {
            t *= 10;
            t += ch - '0';
        } else {
            b = st.top();
            st.pop();
            a = st.top();
            st.pop();
            if (ch == '+') {
                st.push(a + b);
            } else if (ch == '-') {
                st.push(a - b);
            } else if (ch == '*') {
                st.push(a * b);
            } else if (ch == '/') {
                st.push(a / b);
            }
        }
    }
    cout << st.top() << endl;
    return 0;
}

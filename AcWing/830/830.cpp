#include <bits/stdc++.h>

using namespace std;

int n, a;
stack<int> st;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        while (!st.empty() && st.top() >= a) st.pop();
        if (st.empty()) {
            cout << -1 << ' ';
        } else {
            cout << st.top() << ' ';
        }
        st.push(a);
    }
    cout << endl;
    return 0;
}

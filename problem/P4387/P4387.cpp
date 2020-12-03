#include <bits/stdc++.h>

using namespace std;

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n, s = 1, a[100005], b[100005];
        stack<int> st;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
        }
        for (int i = 1; i <= n; i++) {
            st.push(a[i]);
            while (!st.empty() && st.top() == b[s]) {
                st.pop();
                s++;
            }
        }
        if (st.empty())
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}

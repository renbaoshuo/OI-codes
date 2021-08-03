#include <bits/stdc++.h>

using namespace std;

int n, a[3000005], f[3000005];
stack<int> st;

int main() {
    std::ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = n; i >= 1; i--) {
        while (!st.empty() && a[st.top()] <= a[i]) st.pop();
        f[i] = st.empty() ? 0 : st.top();
        st.push(i);
    }
    for (int i = 1; i <= n; i++) {
        cout << f[i] << ' ';
    }
    cout << endl;
    return 0;
}

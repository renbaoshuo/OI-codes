#include <iostream>
#include <stack>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 3e6 + 5;

int n, a[N], f[N];
std::stack<int> st;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = n; i; i--) {
        while (!st.empty() && a[st.top()] <= a[i]) st.pop();
        f[i] = st.empty() ? 0 : st.top();
        st.emplace(i);
    }

    for (int i = 1; i <= n; i++) {
        cout << f[i] << ' ';
    }

    cout << endl;

    return 0;
}

#include <iostream>
#include <stack>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

int n, h[N], ans[N];
std::stack<int> st;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }

    for (int i = n; i; i--) {
        // pop all elements that are smaller than h[i]
        while (!st.empty() && h[i] >= h[st.top()]) st.pop();
        // if the stack is not empty, the nearest element that is larger than h[i] is st.top()
        if (!st.empty()) ans[i] = st.top();
        // push h[i] into the stack
        st.push(i);
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}

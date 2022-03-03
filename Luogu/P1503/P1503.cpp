#include <iostream>
#include <set>
#include <stack>

using std::cin;
using std::cout;
const char endl = '\n';

int n, m, x;
char op;
std::set<int> set;
std::stack<int> st;

int main() {
    std::ios::sync_with_stdio(false);
    cin >> n >> m;
    set.insert(0);
    set.insert(n + 1);
    while (m--) {
        cin >> op;
        if (op == 'D') {
            cin >> x;
            set.insert(x);
            st.push(x);
        } else if (op == 'R') {
            set.erase(st.top());
            st.pop();
        } else {
            cin >> x;
            auto it = set.lower_bound(x);
            cout << (*it == x ? 0 : *it - *--it - 1) << endl;
        }
    }
    return 0;
}

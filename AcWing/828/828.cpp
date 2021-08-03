#include <bits/stdc++.h>

using namespace std;

int main() {
    int m;
    cin >> m;
    stack<int> q;
    while (m--) {
        string op;
        cin >> op;
        if (op == "push") {
            int x;
            cin >> x;
            q.push(x);
        }
        if (op == "pop") q.pop();
        if (op == "empty") cout << (q.empty() ? "YES" : "NO") << endl;
        if (op == "query") cout << q.top() << endl;
    }
    return 0;
}

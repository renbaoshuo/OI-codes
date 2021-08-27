#include <bits/stdc++.h>

using namespace std;

int m, x;
string op;
queue<int> q;

int main() {
    cin >> m;
    while (m--) {
        cin >> op;
        if (op == "push") {
            cin >> x;
            q.push(x);
        } else if (op == "pop") {
            q.pop();
        } else if (op == "empty") {
            cout << (q.empty() ? "YES" : "NO") << endl;
        } else {
            cout << q.front() << endl;
        }
    }
    return 0;
}

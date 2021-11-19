#include <bits/stdc++.h>

using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int> > q;
    int n;
    cin >> n;
    while (n--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x;
            cin >> x;
            q.push(x);
        } else if (op == 2) {
            cout << q.top() << endl;
        } else if (op == 3) {
            q.pop();
        }
    }
    return 0;
}

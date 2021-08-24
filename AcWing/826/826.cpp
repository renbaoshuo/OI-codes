#include <bits/stdc++.h>

using namespace std;

int m, k, x, t;
char op;
list<int> a;
list<int>::iterator it[100005];

int main() {
    cin >> m;
    while (m--) {
        cin >> op;
        if (op == 'H') {
            cin >> x;
            a.push_front(x);
            it[++t] = a.begin();
        } else if (op == 'D') {
            cin >> k;
            if (k == 0) {
                a.pop_front();
            } else {
                auto itk = it[k];
                a.erase(++itk);
            }
        } else {
            cin >> k >> x;
            auto itk = it[k];
            it[++t] = a.insert(++itk, x);
        }
    }
    for (int i : a) {
        cout << i << ' ';
    }
    cout << endl;
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int m, x, k, p;
string op;
list<int> a;
list<int>::iterator it[100005];

int main() {
    cin >> m;
    while (m--) {
        cin >> op;
        if (op == "L") {
            cin >> x;
            a.push_front(x);
            it[++p] = a.begin();
        } else if (op == "R") {
            cin >> x;
            a.push_back(x);
            it[++p] = --a.end();
        } else if (op == "D") {
            cin >> k;
            a.erase(it[k]);
        } else if (op == "IL") {
            cin >> k >> x;
            it[++p] = a.insert(it[k], x);
        } else {
            cin >> k >> x;
            auto itk = it[k];
            it[++p] = a.insert(++itk, x);
        }
    }
    for (int i : a) {
        cout << i << ' ';
    }
    cout << endl;
    return 0;
}

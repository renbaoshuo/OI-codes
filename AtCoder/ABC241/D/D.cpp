#include <iostream>
#include <set>

using std::cin;
using std::cout;
const char endl = '\n';

long long q, op, x, k;
std::multiset<long long> set, s2;

int main() {
    std::ios::sync_with_stdio(false);
    cin >> q;
    while (q--) {
        cin >> op >> x;
        if (op == 1) {
            set.insert(x);
            s2.insert(-x);
        } else if (op == 2) {
            bool flag = false;
            cin >> k;
            auto it = s2.lower_bound(-x);
            if (it == s2.end()) {
                cout << -1 << endl;
                continue;
            }
            for (int i = 1; i < k; i++) {
                if (++it == s2.end()) {
                    cout << -1 << endl;
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                cout << -*it << endl;
            }
        } else {
            bool flag = false;
            cin >> k;
            auto it = set.lower_bound(x);
            if (it == set.end()) {
                cout << -1 << endl;
                continue;
            }
            for (int i = 1; i < k; i++) {
                if (++it == set.end()) {
                    cout << -1 << endl;
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                cout << *it << endl;
            }
        }
    }
    return 0;
}

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

int n;
std::vector<int> a;

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n;

    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        a.push_back(x);
    }

    for (int i = 1, op, l, r, c; i <= n; i++) {
        cin >> op >> l >> r >> c;

        if (op == 0) {
            a.insert(a.begin() + l - 1, r);
        } else {  // op == 1
            cout << a[r - 1] << endl;
        }
    }

    return 0;
}

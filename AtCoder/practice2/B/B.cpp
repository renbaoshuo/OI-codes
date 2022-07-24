#include <iostream>
#include <atcoder/fenwicktree>

using std::cin;
using std::cout;
const char endl = '\n';

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;

    cin >> n >> q;

    atcoder::fenwick_tree<long long> tr(n);

    for (int i = 0; i < n; i++) {
        long long x;

        cin >> x;

        tr.add(i, x);
    }

    while (q--) {
        int op;
        long long x, y;

        cin >> op >> x >> y;

        if (op == 0) {
            tr.add(x, y);
        } else {  // op == 1
            cout << tr.sum(x, y) << endl;
        }
    }

    return 0;
}

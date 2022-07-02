#include <iostream>
#include <string>

using std::cin;
using std::cout;
const char endl = '\n';

int n, q, cnt;
std::string s;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q >> s;

    while (q--) {
        int op, x;

        cin >> op >> x;

        if (op == 1) {
            cnt = (cnt + x) % n;
        } else {
            x = (x - cnt + n) % n;
            cout << s.at(x ? x - 1 : n - 1) << endl;
        }
    }

    return 0;
}

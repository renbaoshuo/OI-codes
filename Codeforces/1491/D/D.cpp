#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;

    cin >> q;

    while (q--) {
        unsigned int u, v;
        int cnt_u = 0,
            cnt_v = 0;

        cin >> u >> v;

        bool flag = u <= v;
        for (int i = 0; i < 30; i++) {
            if (u & (1 << i)) cnt_u++;
            if (v & (1 << i)) cnt_v++;

            if (cnt_u < cnt_v) {
                flag = false;

                break;
            }
        }

        cout << (flag ? "YES" : "NO") << endl;
    }

    return 0;
}

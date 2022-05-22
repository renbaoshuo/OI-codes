#include <iostream>
#include <string>

using std::cin;
using std::cout;
const char endl = '\n';

int t, n;
std::string s;

inline int pre(int x) {
    return x == 1 ? n : x - 1;
}

inline int nxt(int x) {
    return x == n ? 1 : x + 1;
}

int main() {
    std::ios::sync_with_stdio(false);

    cin >> t;

    while (t--) {
        int cnt = 0;

        cin >> n >> s;

        for (char c : s) {
            if (c == '1') cnt++;
        }

        if (!cnt || (cnt & 1)) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;

            int lst = 0;
            for (int i = 1; i <= n; i++) {
                if (s[i - 1] == '1') lst = nxt(i);
            }

            for (int i = nxt(lst); i != lst; i = nxt(i)) {
                if (i == nxt(lst) || s[pre(i) - 1] == '1') {
                    cout << lst << ' ' << i << endl;
                } else {
                    cout << pre(i) << ' ' << i << endl;
                }
            }
        }
    }

    return 0;
}

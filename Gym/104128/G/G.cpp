#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
const char endl = '\n';

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;

    cin >> t;

    while (t--) {
        int n, cnt = 0, cnt_del = 0;
        bool flag = false;

        cin >> n;

        for (int i = 1, x; i <= n; i++) {
            cin >> x;

            if (x == 1) {
                cnt++;
            } else if (x == -1) {
                cnt--;

                if (cnt < 0) {
                    if (cnt_del) {
                        cnt_del--;
                        cnt += 2;
                    } else {
                        flag = true;
                    }
                }
            } else {  // x == 0
                if (cnt) {
                    cnt--;
                    cnt_del++;
                } else {
                    cnt++;
                }
            }
        }

        if (flag) {
            cout << -1 << endl;
        } else {
            int p = cnt + (n - cnt) / 2 + 1,
                q = cnt + 1,
                g = std::__gcd(p, q);

            cout << p / g << ' ' << q / g << endl;
        }
    }

    return 0;
}

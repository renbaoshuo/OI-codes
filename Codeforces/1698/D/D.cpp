#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int t, n, ans;

int main() {
    std::ios::sync_with_stdio(false);

    cin >> t;

    while (t--) {
        ans = 0;

        cin >> n;

        int l = 1, r = n;

        while (l <= r) {
            int mid = l + r >> 1;
            cout << "? " << 1 << ' ' << mid << endl;

            int cnt = 0;
            for (int i = 1, x; i <= mid; i++) {
                cin >> x;

                if (x <= mid) cnt++;
            }

            if (cnt & 1) {
                r = mid - 1;
                ans = mid;
            } else {
                l = mid + 1;
            }
        }

        cout << "! " << ans << endl;
    }

    return 0;
}

#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

int t, n;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;

    while (t--) {
        cin >> n;

        int cnt1 = 0, cnt2 = 0;
        for (int i = 0, x; i < n; i++) {
            cin >> x;

            if (x & 1) {
                cnt1++;
            } else {
                cnt2++;
            }
        }

        cout << std::min(cnt1, cnt2) << endl;
    }

    return 0;
}

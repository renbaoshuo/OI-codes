#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, cnt1 = 0, cnt2 = 0;
        std::string a, b;
        cin >> n >> a >> b;
        for (char c : a) {
            cnt1 += c == '1';
        }
        for (char c : b) {
            cnt2 += c == '1';
        }
        if (cnt1 != cnt2 && n - cnt1 + 1 != cnt2) {
            cout << -1 << endl;
            continue;
        }
        int m0 = 0, m1 = 0;
        for (int i = 0; i < n; i++) {
            if (b[i] == '1') {
                if (a[i] == '0') {
                    m0++;
                } else {
                    m1++;
                }
            }
        }
        int a1 = (cnt2 - m1) * 2,
            a2 = (cnt2 - m0) * 2 - 1;
        if (cnt1 != cnt2) {
            cout << a2 << endl;
        } else if (n - cnt1 + 1 != cnt2) {
            cout << a1 << endl;
        } else {
            cout << std::min(a1, a2) << endl;
        }
    }
    return 0;
}

#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;

    cin >> t;

    while (t--) {
        bool flag = false, ans = true;
        int n;
        long long sum = 0;

        cin >> n;

        for (int i = 1, x; i <= n; i++) {
            cin >> x;

            if ((sum += x) < 0) ans = false;

            if (sum == 0) flag = true;
            else if (flag) ans = false;
        }

        cout << (ans && !sum ? "Yes" : "No") << endl;
    }

    return 0;
}

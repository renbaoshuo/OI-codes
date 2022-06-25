#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

int t, n, a[N];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;

    while (t--) {
        int cnt = 0;

        cin >> n;

        for (int i = 1; i <= n; i++) {
            cin >> a[i];

            if (!a[i - 1] && a[i]) cnt++;
        }

        cout << std::min(2, cnt) << endl;
    }

    return 0;
}

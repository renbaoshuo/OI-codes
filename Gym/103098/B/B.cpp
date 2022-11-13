#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

int n;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    if (n == 1) {
        cout << "YES" << endl
             << 0 << endl;
    } else if (n % 4 == 0) {
        int k = n / 4;

        cout << "YES" << endl;

        for (int i = 1; i <= k; i++) {
            cout << n - i << ' ';
        }

        for (int i = k + 1; i <= 2 * k - 1; i++) {
            cout << n - i - 1 << ' ';
        }

        cout << 0 << ' ';

        for (int i = 2 * k + 1; i <= 3 * k - 1; i++) {
            cout << n - i << ' ';
        }

        cout << n - k - 1 << ' ';

        for (int i = 3 * k + 1; i <= 4 * k; i++) {
            cout << n - i + 1 << ' ';
        }

        cout << endl;
    } else if (n % 4 == 1) {
        int k = n / 4;

        cout << "YES" << endl;

        for (int i = 1; i <= k; i++) {
            cout << n - i << ' ';
        }

        cout << k + 1 << ' ';

        for (int i = k + 2; i <= 2 * k; i++) {
            cout << n - i + 1 << ' ';
        }

        cout << 0 << ' ';

        for (int i = 2 * k + 2; i <= 3 * k + 1; i++) {
            cout << n - i + 2 << ' ';
        }

        for (int i = 3 * k + 2; i <= 4 * k + 1; i++) {
            cout << n - i + 1 << ' ';
        }

        cout << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}

// #include <iostream>
#include <fstream>

// using std::cin;
// using std::cout;
std::ifstream cin("stone.in");
std::ofstream cout("stone.out");
const char endl = '\n';

int n;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    if (n == 1) {
        cout << "YES" << endl
             << 1 << ' ' << 1 << endl;
    } else if (n % 4 == 0) {
        int k = n / 4;

        cout << "YES" << endl;

        for (int i = 1; i <= k; i++) {
            cout << i << ' ' << n - i + 1 << endl;
        }

        for (int i = k + 1; i <= 2 * k - 1; i++) {
            cout << i << ' ' << n - i << endl;
        }

        cout << 2 * k << ' ' << 1 << endl;

        for (int i = 2 * k + 1; i <= 3 * k - 1; i++) {
            cout << i << ' ' << n - i + 1 << endl;
        }

        cout << 3 * k << ' ' << n - k << endl;

        for (int i = 3 * k + 1; i <= 4 * k; i++) {
            cout << i << ' ' << n - i + 2 << endl;
        }
    } else if (n % 4 == 1) {
        int k = n / 4;

        cout << "YES" << endl;

        for (int i = 1; i <= k; i++) {
            cout << i << ' ' << n - i + 1 << endl;
        }

        cout << k + 1 << ' ' << k + 2 << endl;

        for (int i = k + 2; i <= 2 * k; i++) {
            cout << i << ' ' << n - i + 2 << endl;
        }

        cout << 2 * k + 1 << ' ' << 1 << endl;

        for (int i = 2 * k + 2; i <= 3 * k + 1; i++) {
            cout << i << ' ' << n - i + 3 << endl;
        }

        for (int i = 3 * k + 2; i <= 4 * k + 1; i++) {
            cout << i << ' ' << n - i + 2 << endl;
        }
    } else {
        cout << "NO" << endl;
    }

    return 0;
}

#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

int n;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    while (n) {
        if (n % 10 == 1) {
            n /= 10;
        } else if (n % 100 == 14) {
            n /= 100;
        } else if (n % 1000 == 144) {
            n /= 1000;
        } else {
            cout << "NO" << endl;

            exit(0);
        }
    }

    cout << "YES" << endl;

    return 0;
}

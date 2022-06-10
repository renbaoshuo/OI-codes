#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

bool isPrime(int x) {
    if (x <= 1) return false;

    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x;

    cin >> x;

    if (isPrime(x) && isPrime(x - 6)) {
        cout << "Yes" << endl
             << x - 6 << endl;
    } else if (isPrime(x) && isPrime(x + 6)) {
        cout << "Yes" << endl
             << x + 6 << endl;
    } else {
        cout << "No" << endl;

        while (!(isPrime(x) && (isPrime(x - 6) || isPrime(x + 6)))) x++;

        cout << x << endl;
    }

    return 0;
}

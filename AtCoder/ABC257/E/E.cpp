#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e6 + 5;

int n, a[N], c[10], min, max;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    min = 1;
    for (int i = 1; i <= 9; i++) {
        cin >> c[i];

        if (c[i] <= c[min]) min = i;
    }

    max = n / c[min];

    for (int i = 1; i <= max; i++) {
        a[i] = min;
    }

    n %= c[min];

    for (int i = max; i; i--) {
        for (int j = 9; j > min; j--) {
            if (n >= c[j] - c[min]) {
                n -= c[j] - c[min];
                a[i] = j;
                break;
            }
        }
    }

    for (int i = max; i; i--) {
        cout << a[i];
    }

    cout << endl;

    return 0;
}

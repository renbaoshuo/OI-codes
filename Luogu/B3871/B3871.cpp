#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
const char endl = '\n';

long long n;
bool flag;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    long long x = n;

    for (long long i = 2; i <= std::sqrt(n); i++) {
        if (x % i == 0) {
            int cnt = 0;

            while (x % i == 0) x /= i, cnt++;

            if (flag) cout << " * ";
            else flag = true;

            if (cnt > 1) {
                cout << i << '^' << cnt;
            } else {
                cout << i;
            }
        }
    }

    if (x > 1) {
        if (flag) cout << " * ";
        cout << x;
    }

    return 0;
}

#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e6 + 5;

int n, b, a[N]{0, 1}, cnt;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> b;

    for (int i = 2; i <= n; i++) {
        if (a[i] == 0) {
            for (int j = i; j <= n; j += i) {
                a[j] = i;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (a[i] <= b) {
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}

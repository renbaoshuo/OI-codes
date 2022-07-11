#include <iostream>
#include <cstring>
#include <limits>
#include <queue>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

int n, l, s, a[N], b[N];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> l;

    for (int i = 1; i < n; i++) {
        cin >> a[i];

        s += a[i];
    }

    a[n] = b[0] = s;
    for (int i = 0; i < n; i++) {
        for (int j = std::min(i + l, n); j > i; j--) {
            if (b[j] < a[j]) {
                if (b[j] + b[i] <= a[j]) {
                    b[j] += b[i];
                    b[i] = 0;
                    break;
                } else {
                    b[i] -= a[j] - b[j];
                    b[j] = a[j];
                }
            }
        }
    }

    cout << b[n] << endl;

    return 0;
}

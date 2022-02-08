#include <iostream>

using std::cin;
using std::cout;
#define endl '\n'

const int N = 100005;

int n, m, x, a[N], b[N];

int main() {
    cin >> n >> m >> x;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    for (int i = 0, j = m - 1; i < n; i++) {
        while (a[i] + b[j] > x) j--;
        if (a[i] + b[j] == x) {
            cout << i << ' ' << j << endl;
            exit(0);
        }
    }
    return 0;
}

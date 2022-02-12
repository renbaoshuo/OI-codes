#include <iostream>

using std::cin;
using std::cout;
#define endl '\n'

int m, sum, j;

int main() {
    std::ios::sync_with_stdio(false);
    cin >> m;
    for (int i = 1; i <= m / 2; i++) {
        sum = 0;
        for (j = i; j < m; j++) {
            sum += j;
            if (sum >= m) break;
        }
        if (sum == m) {
            cout << i << ' ' << j << endl;
        }
    }
    return 0;
}

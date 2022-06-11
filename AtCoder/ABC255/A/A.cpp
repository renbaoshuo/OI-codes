#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

int r, c, a[10][10];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> r >> c;

    for (int i = 1; i <= 2; i++) {
        for (int j = 1; j <= 2; j++) {
            cin >> a[i][j];
        }
    }

    cout << a[r][c] << endl;

    return 0;
}

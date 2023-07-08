#include <iostream>
#include <string>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 105;

int n;
std::string a[N], b[N];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];

        b[i] = a[i] = ' ' + a[i];
    }

    for (int i = 2; i <= n; i++) {
        b[1][i] = a[1][i - 1];
    }

    for (int i = 1; i < n; i++) {
        b[i][1] = a[i + 1][1];
    }

    for (int i = 1; i < n; i++) {
        b[n][i] = a[n][i + 1];
    }

    for (int i = 2; i <= n; i++) {
        b[i][n] = a[i - 1][n];
    }

    for (int i = 2; i < n; i++) {
        for (int j = 2; j < n; j++) {
            b[i][j] = a[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << b[i][j];
        }

        cout << endl;
    }

    return 0;
}

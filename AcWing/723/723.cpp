#include <bits/stdc++.h>

using namespace std;

int n, m, c;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++, c++) {
        for (int j = 1; j < m; j++) {
            cout << ++c << ' ';
        }
        cout << "PUM" << endl;
    }
    return 0;
}

// R38858817

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, a[10000005], q;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> q;
        cout << a[q - 1] << endl;
    }
    return 0;
}

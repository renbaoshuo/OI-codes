#include <bits/stdc++.h>

using namespace std;

int main() {
    short a[1000005];
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < m; i++) {
        cout << a[i] << endl;
    }
}
#include <bits/stdc++.h>

using namespace std;

int n, t;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        cout << __builtin_popcount(t) << ' ';
    }
    cout << endl;
    return 0;
}

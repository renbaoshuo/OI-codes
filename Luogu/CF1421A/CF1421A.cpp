#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, a, b;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        cout << a + b - (a & b) * 2 << endl;
    }
    return 0;
}

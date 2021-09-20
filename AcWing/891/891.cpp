#include <bits/stdc++.h>

using namespace std;

int n, r, a;

int main() {
    cin >> n;
    while (n--) {
        cin >> a;
        r ^= a;
    }
    cout << (r ? "Yes" : "No") << endl;
    return 0;
}

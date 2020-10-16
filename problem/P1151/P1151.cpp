#include <bits/stdc++.h>

using namespace std;

int main() {
    int k, f = 0;
    cin >> k;
    for (int i = 10000; i <= 30000; i++) {
        if ((i / 100) % k == 0 && (i / 10 - i / 10000 * 1000) % k == 0 && (i - i / 1000 * 1000) % k == 0) {
            cout << i << endl;
            f = 1;
        }
    }
    cout << (f ? "" : "No") << endl;
    return 0;
}

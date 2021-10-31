#include <bits/stdc++.h>

using namespace std;

int k, n;
double s;

int main() {
    cin >> k;
    while (s <= k) {
        s += 1.00 / ++n;
    }
    cout << n << endl;
    return 0;
}

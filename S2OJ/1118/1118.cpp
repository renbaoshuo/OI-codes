#include <bits/stdc++.h>

using namespace std;

int n, l, r;

int main() {
    cin >> n >> l >> r;
    cout << min((int)(ceil(1.0 * l / n) * n + n - 1), r) % n << endl;
    return 0;
}

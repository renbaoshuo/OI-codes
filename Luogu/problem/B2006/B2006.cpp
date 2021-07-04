#include <bits/stdc++.h>

using namespace std;

int main() {
    int x, a, y, b;
    cin >> x >> a >> y >> b;
    cout << fixed << setprecision(2) << 1.00 * (b * y - a * x) / (b - a) << endl;
    return 0;
}

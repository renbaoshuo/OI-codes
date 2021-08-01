#include <bits/stdc++.h>

using namespace std;

int main() {
    double x;
    cin >> x;
    if (0.00 <= x && x <= 2000.00) {
        cout << "Isento" << endl;
    } else if (2000.01 <= x && x <= 3000.00) {
        cout << "R$ " << fixed << setprecision(2) << (x - 2000.00) * 0.08 << endl;
    } else if (3000.01 <= x && x <= 4500.00) {
        cout << "R$ " << fixed << setprecision(2) << (1000.00 * 0.08) + (x - 3000.00) * 0.18 << endl;
    } else {
        cout << "R$ " << fixed << setprecision(2) << (1000.00 * 0.08) + (1500 * 0.18) + (x - 4500) * 0.28 << endl;
    }
    return 0;
}

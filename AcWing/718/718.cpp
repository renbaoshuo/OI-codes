#include <bits/stdc++.h>

using namespace std;

int f[100], sum;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int a;
        char t;
        cin >> a >> t;
        if (t == 'C') {
            f[1] += a;
        } else if (t == 'R') {
            f[2] += a;
        } else {
            f[3] += a;
        }
        sum += a;
    }
    cout << "Total: " << sum << " animals" << endl
         << "Total coneys: " << f[1] << endl
         << "Total rats: " << f[2] << endl
         << "Total frogs: " << f[3] << endl
         << "Percentage of coneys: " << fixed << setprecision(2) << 100.0 * f[1] / sum << " %" << endl
         << "Percentage of rats: " << fixed << setprecision(2) << 100.0 * f[2] / sum << " %" << endl
         << "Percentage of frogs: " << fixed << setprecision(2) << 100.00 * f[3] / sum << " %" << endl;
    return 0;
}

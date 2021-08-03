#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    double a, b;
    cin >> s >> a >> b;
    cout << "TOTAL = R$ " << fixed << setprecision(2) << a + 0.15 * b << endl;
    return 0;
}

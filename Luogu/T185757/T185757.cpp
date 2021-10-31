#include <bits/stdc++.h>

using namespace std;

int a1, b1, c1, d1, a2, b2, c2, d2;

int main() {
    cin >> a1 >> b1 >> c1 >> d1 >> a2 >> b2 >> c2 >> d2;
    if (a1 == a2 && b1 == b2 && c1 == c2 && d1 == d2) {
        cout << "Yes" << endl;
    } else if (a1 > 0 && b1 > 0 && c1 > 0 && d1 > 0 && a2 > 0 && b2 > 0 && c2 > 0 && d2 > 0) {
        cout << "No" << endl;
    } else if (!a1 + !b1 + !c1 + !d1 == 1 && d1 == 0) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
    return 0;
}

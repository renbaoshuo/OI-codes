// R38989380

#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    // abc abd acd bcd
    if (a + b > c && a + c > b && b + c > a || a + b > d && a + d > b && b + d > a || a + c > d && a + d > c && c + d > a || b + c > d && b + d > c && c + d > b) {
        cout << "TRIANGLE" << endl;
    }
    else if (a + b >= c && a + c >= b && b + c >= a || a + b >= d && a + d >= b && b + d >= a || a + c >= d && a + d >= c && c + d >= a || b + c >= d && b + d >= c && c + d >= b) {
        cout << "SEGMENT" << endl;
    }
    else {
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}

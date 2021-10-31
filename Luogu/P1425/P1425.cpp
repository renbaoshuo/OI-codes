#include <bits/stdc++.h>

using namespace std;

int a, b, c, d, x, y;

int main() {
    cin >> a >> b >> c >> d;
    x = c - a, y = d - b;
    if (y < 0) {
        x--;
        y += 60;
    }
    cout << x << ' ' << y << endl;
    return 0;
}

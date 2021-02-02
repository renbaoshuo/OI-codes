#include <bits/stdc++.h>

using namespace std;

int exgcd(int a, int b, int& x, int& y) {
    if (!b) {
        x = 1;
        y = 0;
        return a;
    }
    int d = exgcd(b, a % b, x, y);
    int t = x;
    x = y;
    y = t - (a / b) * y;
    return d;
}

int main() {
    int a, b, x = 0, y = 0;
    cin >> a >> b;
    exgcd(a, b, x, y);
    x = (x % b + b) % b;
    cout << x << endl;
    return 0;
}

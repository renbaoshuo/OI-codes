#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    if (!b) return a;
    return gcd(b, a % b);
}

int main() {
    int n, a, b;
    cin >> n;
    while (n--) {
        cin >> a >> b;
        cout << gcd(a, b) << endl;
    }
    return 0;
}

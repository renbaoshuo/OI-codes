#include <bits/stdc++.h>

using namespace std;

int n, x;

int phi(int x) {
    int res = x;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            res = res / i * (i - 1);
            while (x % i == 0) x /= i;
        }
    }
    if (x > 1) res = res / x * (x - 1);
    return res;
}

int main() {
    cin >> n;
    while (n--) {
        cin >> x;
        cout << phi(x) << endl;
    }
    return 0;
}

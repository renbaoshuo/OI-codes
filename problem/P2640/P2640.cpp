#include <bits/stdc++.h>

using namespace std;

bool isPrime(int x) {
    if (x == 1) {
        return false;
    }
    if (x == 2) {
        return true;
    }
    if (x % 2 == 0) {
        return false;
    }
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int  n, k;
    bool flag = false;
    cin >> n >> k;
    for (int i = 2; i + k <= n; i++) {
        if (isPrime(i) && isPrime(i + k)) {
            cout << i << ' ' << i + k << endl;
            flag = true;
        }
    }
    if (!flag) {
        cout << "empty" << endl;
    }
    return 0;
}

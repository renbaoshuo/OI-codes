#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
    cin >> n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            cout << n / i << endl;
            exit(0);
        }
    }
    return 0;
}

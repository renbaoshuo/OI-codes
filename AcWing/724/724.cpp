#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            cout << i << endl;
        }
    }

    return 0;
}

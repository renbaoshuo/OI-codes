#include <bits/stdc++.h>

using namespace std;

int n, a[1030] = {1};

int main() {
    cin >> n;
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 1; j < (1 << n) - i; ++j) {
            cout << " ";
        }
        for (int j = i; j >= 0; j--) {
            a[j] ^= a[j - 1];
        }
        if (i & 1) {
            for (int j = 0; j <= i; j += 2) {
                cout << (a[j] ? "/__\\" : "    ");
            }

        } else {
            for (int j = 0; j <= i; j++) {
                cout << (a[j] ? "/\\" : "  ");
            }
        }
        cout << endl;
    }
    return 0;
}
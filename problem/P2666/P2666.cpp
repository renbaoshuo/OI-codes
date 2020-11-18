#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            for (int k = 0; k <= 100; k++) {
                for (int p = 0; p <= 100; p++) {
                    if (i * i + j * j + k * k + p * p == n) {
                        ans++;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

unsigned long long n, f[105];

int main() {
    cin >> n;
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        int j = 0;
        while (j <= i - 1) {
            f[i] += f[j] * f[i - j - 1];
            f[i] %= 100;
            j++;
        }
    }
    cout << f[n] % 100 << endl;
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int t, n, a[105], sum, p1, p2;
bool is_prime[20005];

void Eratosthenes(int n) {
    for (int i = 0; i <= n; i++) is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            if (i * i <= n) {
                for (int j = i * i; j <= n; j += i) {
                    is_prime[j] = false;
                }
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin >> t;
    Eratosthenes(20000);
    while (t--) {
        sum = 0;
        p1 = p2 = -1;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] == 1) p1 = i;
            if (a[i] % 2) p2 = i;
            sum += a[i];
        }
        cout << n - is_prime[sum] << endl;
        if (!is_prime[sum]) {
            for (int i = 1; i <= n; i++) {
                cout << i << ' ';
            }
        } else if (p1 != -1) {
            for (int i = 1; i <= n; i++) {
                if (i != p1) cout << i << ' ';
            }
        } else {
            for (int i = 1; i <= n; i++) {
                if (i != p2) cout << i << ' ';
            }
        }
        cout << endl;
    }
    return 0;
}

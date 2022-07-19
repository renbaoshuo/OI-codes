#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;

int n, phi[N];
long long sum[N], ans;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    phi[1] = 1;
    for (int i = 2; i <= n; i++) {
        phi[i] = i;
    }

    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j < N; j += i) {
                phi[j] = phi[j] / i * (i - 1);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + phi[i];
    }

    for (int i = 1; i <= n; i++) {
        ans += (sum[n / i] * 2 - 1) * i;
    }

    cout << ans << endl;

    return 0;
}

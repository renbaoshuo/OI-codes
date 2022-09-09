#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e5 + 5;
const int mod = 998244353;

int n, ans = 1;
int cnt1, cnt5, cnt7;
int cnt2, cnt3, cnt236;
int fac[N], inv[N], fac_inv[N];

inline int C(int n, int m) {
    return static_cast<long long>(fac[n]) * fac_inv[m] % mod * fac_inv[n - m] % mod;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fac[0] = 1;
    for (int i = 1; i < N; i++) {
        fac[i] = static_cast<long long>(fac[i - 1]) * i % mod;
    }

    inv[0] = inv[1] = 1;
    for (int i = 2; i < N; i++) {
        inv[i] = static_cast<long long>(mod - (mod / i)) * inv[mod % i] % mod;
    }

    fac_inv[0] = fac_inv[1] = 1;
    for (int i = 2; i < N; i++) {
        fac_inv[i] = static_cast<long long>(fac_inv[i - 1]) * inv[i] % mod;
    }

    cin >> n;

    for (int i = 1, x; i <= n; i++) {
        cin >> x;

        switch (x) {
            case 1: {
                cnt1++;

                break;
            }

            case 5: {
                cnt5++;

                break;
            }

            case 7: {
                cnt7++;

                break;
            }

            case 2:
            case 4:
            case 8: {
                cnt2++;
                cnt236++;

                break;
            }

            case 3:
            case 9: {
                cnt3++;
                cnt236++;

                break;
            }

            case 6: {
                cnt236++;
                ans = static_cast<long long>(ans) * fac[cnt2 + cnt3] % mod * fac_inv[cnt2] % mod * fac_inv[cnt3] % mod;
                cnt2 = cnt3 = 0;

                break;
            }
        }
    }

    ans = static_cast<long long>(ans) * fac[cnt2 + cnt3] % mod * fac_inv[cnt2] % mod * fac_inv[cnt3] % mod;
    ans = static_cast<long long>(ans) * fac[cnt1 + cnt236 + cnt5 + cnt7] % mod * fac_inv[cnt1] % mod * fac_inv[cnt236] % mod * fac_inv[cnt5] % mod * fac_inv[cnt7] % mod;

    cout << ans << endl;

    return 0;
}

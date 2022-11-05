#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

int n, k;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    int a = n / k,
        b = (n - 1) / k + 1;
    int cb = n % k,
        ca = k - n % k;
    long long res = 0;

    res += static_cast<long long>(ca) * (ca - 1) / 2 * a * a;
    res += static_cast<long long>(cb) * (cb - 1) / 2 * b * b;
    res += static_cast<long long>(a) * b * ca * cb;

    cout << res << endl;

    return 0;
}

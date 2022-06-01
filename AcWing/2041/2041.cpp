#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

const int N = 1000005;

int n, k, a, b, s[N], f[N];

int main() {
    cin >> n >> k;
    for (int i = 1; i <= k; i++) {
        cin >> a >> b;
        s[a] += 1;
        s[b + 1] -= 1;
    }
    for (int i = 1; i <= n; i++) {
        f[i] = f[i - 1] + s[i];
    }
    std::sort(f + 1, f + 1 + n);
    cout << f[n / 2 + 1] << endl;
    return 0;
}

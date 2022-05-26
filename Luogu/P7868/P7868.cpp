#include <algorithm>
#include <iostream>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 1e6 + 5;

int n, p, a[N];
long long b[N], ans;

void solve(int l, int r) {
    if (l == r) {
        if (a[l] >= p) ans++;
        return;
    }

    int mid = l + r >> 1;

    solve(l, mid);
    solve(mid + 1, r);

    b[mid] = a[mid] - p;
    for (int i = mid - 1; i >= l; i--) b[i] = b[i + 1] + a[i] - p;
    std::sort(b + l, b + mid + 1);

    b[mid + 1] = a[mid + 1] - p;
    for (int i = mid + 2; i <= r; i++) b[i] = b[i - 1] + a[i] - p;
    std::sort(b + mid + 1, b + r + 1);

    int i = l, j = r;
    while (i <= mid) {
        while (j > mid && b[i] + b[j] >= 0) j--;
        ans += r - j;
        i++;
    }
}

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    cin >> p;

    solve(1, n);

    cout << ans << endl;

    return 0;
}

#include <algorithm>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int n, q, x, a[200005];

int main() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    std::sort(a, a + n);
    while (q--) {
        cin >> x;
        cout << n - (std::lower_bound(a, a + n, x) - a) << endl;
    }
    return 0;
}

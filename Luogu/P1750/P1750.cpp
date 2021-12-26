#include <algorithm>
#include <iostream>
#include <limits>

using std::cin;
using std::cout;
using std::endl;

const int N = 300005;

int n, c, l, r, a[N];
bool vis[N];

int main() {
    std::ios::sync_with_stdio(false);
    cin >> n >> c;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    l = 1, r = c;
    for (int i = 1; i <= n; i++) {
        int p = std::min_element(a + l, a + r + 1) - a;
        cout << a[p] << ' ';
        vis[p] = true;
        a[p] = std::numeric_limits<int>::max();
        while (p && vis[p]) p--;
        l = std::max(p, 1);
        r = std::min(r + 1, n);
    }
    cout << endl;
    return 0;
}

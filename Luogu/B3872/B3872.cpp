#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
const char endl = '\n';

const int N = 505;

int n, ans;
bool t[N];

struct node {
    int t, r;
} a[N];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i].t;
    }

    for (int i = 1; i <= n; i++) {
        cin >> a[i].r;
    }

    std::sort(a + 1, a + 1 + n, [&](const node &a, const node &b) {
        return a.r > b.r;
    });

    for (int i = 1; i <= n; i++) {
        for (int j = a[i].t; j; j--) {
            if (!t[j]) {
                t[j] = true;
                ans += a[i].r;
                break;
            }
        }
    }

    cout << ans << endl;

    return 0;
}

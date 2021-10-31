#include <bits/stdc++.h>

using namespace std;

struct node {
    long long a, b;

    bool operator<(const node& b) {
        return a < b.a;
    }
} a[500005];
int n;
long long s[500005], c, ans;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].a >> a[i].b;
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + a[i].b;
    }
    for (int i = 0; i <= n; i++) {
        c = max(c, a[i].a - s[i - 1]);
        ans = max(ans, s[i] - a[i].a + c);
    }
    cout << ans << endl;
    return 0;
}

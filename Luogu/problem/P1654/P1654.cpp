#include <bits/stdc++.h>

using namespace std;

int n;
double a[100005], l1[100005], l2[100005], l3[100005], ans[100005];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        l1[i] = a[i] * (l1[i - 1] + 1);
        l2[i] = a[i] * (l2[i - 1] + 2 * l1[i - 1] + 1);
        l3[i] = a[i] * (l3[i - 1] + 3 * l2[i - 1] + 3 * l1[i - 1] + 1);
        ans[i] = ans[i - 1] + l3[i] - a[i] * l3[i - 1];
    }
    cout << fixed << setprecision(1) << ans[n] << endl;
    return 0;
}

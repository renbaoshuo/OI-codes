#include <bits/stdc++.h>

using namespace std;

int n;
double sum = 0.00;
pair<int, int> a[1005];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) {
        cout << a[i].second << ' ';
        sum += a[i].first * (n - i);
    }
    cout << endl;
    cout << fixed << setprecision(2) << sum / n << endl;
    return 0;
}

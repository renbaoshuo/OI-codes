#include <bits/stdc++.h>

using namespace std;

int main() {
    long double x, m, n;
    set<long double> ans[2];
    cin >> x >> m >> n;
    ans[0].insert(x / 2);
    ans[0].insert(x);
    ans[0].insert(180 - x * 2);
    ans[0].insert((180 - x) / 2);
    for (auto i : ans[0]) {
        if (i <= 0 || i > 180) continue;
        cout << i << ' ';
    }
    cout << endl;
    if (n != m) ans[1].insert(sqrt(pow(n, 2) - pow(m, 2)));
    ans[1].insert(sqrt(pow(n, 2) + pow(m, 2)));
    for (auto i : ans[1]) {
        cout << fixed << setprecision(5) << i << ' ';
    }
    cout << endl;
    return 0;
}

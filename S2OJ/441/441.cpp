#include <bits/stdc++.h>

using namespace std;

int main() {
    int m, s, a[15], ans1 = 0;
    string x, ans2;
    map<int, int> m1, m2;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    sort(a, a + m);
    for (int i = 0; i < m; i++) {
        m1[i] = a[i];
        m2[a[i]] = i;
    }
    cin >> x >> s;
    reverse(x.begin(), x.end());
    for (int i = 0; i < x.size(); i++) {
        ans1 += m2[x[i] - '0'] * pow(m, i);
    }
    while (s) {
        ans2.push_back(m1[s % m] + '0');
        s /= m;
    }
    reverse(ans2.begin(), ans2.end());
    cout << ans1 << endl
         << ans2 << endl;
    return 0;
}

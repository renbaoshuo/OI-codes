#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, a[100005];
    queue<int> q;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int h, s, t;
    h = a[n - 1];
    s = unique(a, a + n) - a;
    t = h * (4 + 6) + n;
    for (int i = 0; i < s; i++) {
        if (a[i]) {
            t += 5;
        }
    }
    cout << t << endl;
    return 0;
}

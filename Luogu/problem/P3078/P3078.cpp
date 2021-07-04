#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, a[1000005], s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    s = a[0];
    for (int i = 1; i < n; i++) {
        s += max(0ll, a[i] - a[i - 1]);
    }
    cout << s << endl;
    return 0;
}

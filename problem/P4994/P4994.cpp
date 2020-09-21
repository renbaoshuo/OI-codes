// R38706118

#include <bits/stdc++.h>

using namespace std;

long long a[10000000];

long long dfib(long long x, long long m) {
    if (a[x] != -1) {
        return a[x];
    }
    if (x == 0) {
        a[x] = 0 % m;
        return 0;
    }
    if (x == 1) {
        a[x] = 1 % m;
        return 1;
    }
    a[x] = (dfib(x - 1, m) + dfib(x - 2, m)) % m;
    return a[x];
}

int main() {
    long long m;
    memset(a, 0xff, sizeof(a));
    cin >> m;
    for (int i = 2; i < m * m; i++) {
        // cout << i << ' ' << dfib(i, m) << endl;
        if (dfib(i, m) == 0 && dfib(i + 1, m) == 1) {
            cout << i;
            break;
        }
    }
    return 0;
}

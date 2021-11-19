#include <bits/stdc++.h>

using namespace std;

int main() {
    int maxi, maxn, t0, t1;
    for (int i = 0; i < 5; i++) {
        t1 = 0;
        for (int j = 0; j < 4; j++) {
            cin >> t0;
            t1 += t0;
        }
        if (t1 > maxn) {
            maxn = t1;
            maxi = i + 1;
        }
    }
    cout << maxi << ' ' << maxn << endl;
    return 0;
}

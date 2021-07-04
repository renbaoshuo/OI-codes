// R39029021

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, a[10005], k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    n = unique(a, a + n) - a;
    if (k >= n) {
        cout << "NO RESULT" << endl;
    }
    else {
        cout << a[--k];
    }
    return 0;
}

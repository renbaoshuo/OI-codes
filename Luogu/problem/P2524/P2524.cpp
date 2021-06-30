#include <bits/stdc++.h>

using namespace std;

int n, ans, a[11], b[11];

bool cmp() {
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%1d", a + i);
        b[i] = i + 1;
    }
    while (!cmp()) {
        next_permutation(b, b + n);
        ans++;
    }
    cout << ++ans << endl;
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int n, a[110], i;
bool t1, t2;
long long l = 0, r = 1000000000, mid, t[110], top;

bool check(long long x) {
    top = 0;
    for (i = 1; i < n; i++) {
        if (a[i] == -1) {
            t[++top] = x;
        } else if (a[i] > 0) {
            t[++top] = a[i];
        } else if (top > 1) {
            t[top - 1] += t[top];
            top--;
        }
    }
    return t[top] <= a[n];
}

int main() {
    while (cin >> a[++n]) {}
    n--;
    t1 = check(0);
    if (t[top] == a[n]) {
        cout << 0 << endl;
        return 0;
    }
    t2 = check(1000000001);
    if (t1 == t2) {
        cout << -1 << endl;
        return 0;
    }
    while (l < r) {
        mid = l + r + 1 >> 1;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << l << endl;
    return 0;
}